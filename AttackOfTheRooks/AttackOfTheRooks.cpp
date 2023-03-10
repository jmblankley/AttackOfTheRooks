// author: Joshua Blankley
// version: 1/26/2023

#include <iostream>
#include <fstream>
#define EMPTY '.'
#define MAXSIZE 100
using namespace std;
// minimum comments
// explain every block of code (general explaination)

// initalize an empty 2d array to be filled with input from user selected file
char rooks[MAXSIZE][MAXSIZE];
int row, col;
char input;

// prints out our empty grid
// used to test if our input was getting put into the grid
void printGrid(int rowCount, int colCount)
{
    for (int r = 0; r < rowCount; r++)
    {
        for (int c = 0; c < colCount; c++)
        {
            cout << rooks[r][c];
        }
        cout << endl;
    }
}

// this function takes in our ifstream and stores it in our 2d array
void readGrid(int rowCount, int colCount, ifstream &input)
{
    for (int r = 0; r < rowCount; r++)
    {
        for (int c = 0; c < colCount; c++)
        {
            char var;
            input >> var;
            rooks[r][c] = var;
        }
    }
}

void readFile(string fname)
{
}

// this function checks each row and column for Rooks and Blocks to see if the rooks can attack
// or not attack
void rookAttacks(int rowCount, int colCount)
{
    // iterates through the rows and columns of the 2d array
    for (int r = 0; r < rowCount; r++)
    {
        for (int c = 0; c < colCount; c++)
        {
            // checks for char 'R', if it comes across one, iterates through the remaining items in the array checking for blocks ("#") or rooks ('R')
            if (rooks[r][c] == 'R')
            {
                // look through the remaining columns for # or R
                // returns to main if it finds either
                for (int cc = c + 1; cc < colCount; cc++)
                {
                    if (rooks[r][cc] == '#')
                    {
                        cout << "No two rooks can attack each other." << endl;
                        // returns to main when it finds a '#'
                        return;
                    }
                    if (rooks[r][cc] == 'R')
                    {
                        cout << "At least two rooks can attack each other." << endl;
                        return;
                    }
                }
                // look through the remaining rows for # or R
                // returns to main if it find either
                for (int rr = r + 1; rr < rowCount; rr++)
                {
                    if (rooks[rr][c] == '#')
                    {
                        cout << "No two rooks can attack each other" << endl;
                        return;
                    }
                    if (rooks[rr][c] == 'R')
                    {
                        cout << "At least two rooks can attack each other." << endl;
                        return;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{

    // ask user for input
    string fname;
    cout << "Please enter the name of an input file: ";
    cin >> fname;

    // uses fstream to read the filename given by the user and store
    ifstream reader(fname);

    // next two if statements handles errors
    // returns error if file is un-openable
    if (!reader)
    {

        cerr << "Could not open \"" << fname << '"' << endl;
        return 1;
    }
    // returns error if nothing is in the file
    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return 2;
    }

    // takes the first two values of our text file and stores them in variables to construct the 2d array
    reader >> row >> col;

    // call this function, pass it our row and col size taken from input file as well as what ifstream we need to read
    readGrid(row, col, reader);

    // call this function to print out the 2d array we just filled in readGrid()
    printGrid(row, col);

    rookAttacks(row, col);

    return 0;
}