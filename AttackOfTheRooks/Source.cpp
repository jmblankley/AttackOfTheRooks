#include <iostream>
#include <fstream>
#define EMPTY '.'
#define MAXSIZE 100
using namespace std;

// initalize an empty 2d array to be filled with input from user selected file
char rooks[MAXSIZE][MAXSIZE];
int row, col;
char input;

// initalizes an empty 2d array with the max size of 100 spaces
// will be filled with input from a text file
void initGrid()
{
    for (int r = 0; r < MAXSIZE; r++)
    {
        for (int c = 0; c < MAXSIZE; c++)
        {
            rooks[r][c] = EMPTY;
        }
    }
}

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

int main(int argc, char *argv[])
{

    // ask user for input
    string fname;
    cout << "Please enter the name of an input file: ";
    cin >> fname;

    // uses fstream to read the filename given by the user and store
    // opens file
    ifstream reader(fname);

    // next two if statements handles errors
    if (!reader)
    {
        // cerr prints out where you want to print out errors
        cerr << "Could not open \"" << fname << '"' << endl;
        // ends the current function
        return 1;
    }
    // returns error if nothing is in the file
    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return 2;
    }

    // takes the first two values of our text file and stores them in variables to later construct the 2d array
    reader >> row >> col;

    // initGrid();

    // moves reader along to next char in file
    // reader >> input;

    // while (reader)
    //{
    //   cout << input;
    // reader >> input; // stops reader when it runs out of char
    //}

    readGrid(row, col, reader);

    printGrid(row, col);
    return 0;
}
