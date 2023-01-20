#include <iostream>
#include <fstream>
#define EMPTY '.'
#define MAXSIZE 100
using namespace std;

char rooks[MAXSIZE][MAXSIZE];
int row, col;


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





int main(int argc, char* argv[])
{
    string fname;
    cout << "What is the name of your input file? ";
    cin >> fname;

    ifstream reader(fname);
    if (!reader)
    {
        // cerr prints out where you want to print out errors
        cerr << "Could not open \"" << fname << '"' << endl;
        // ends the current function
        return 1;
    }

   

    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return 2;
    }

    reader >> row >> col;

    initGrid();
    
    char empty;
    reader >> empty;

    while (reader) // read did work
    {
        rooks[row][col] << empty;

        reader >> empty;
    }
    
    









	return 0;
}





