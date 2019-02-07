// Group Assingment 1
// Name: Darien Favorite
// Name: Chau Le
// Name: Ai Nguyen

#include <iostream>
#include <string>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[])
{
    // Argument manager
    if (argc < 2)
    {
        cout << "Usage: ./spiral input=input.txt output=output.txt" << endl;
        cout << "NOTE: \"input.txt\" and \"output.txt\" can be any text file name." << endl;
        return -1;
    }

    ArgumentManager am(argc, argv);
    const string inputFileName = am.get("input");
    const string outputFileName = am.get("output");

    ifstream input;
    input.open(inputFileName);

    ofstream output(outputFileName);

    string str;
    getline(input, str);
    input.close();

    int length = 0;
    while ((length*length)<str.length())
        length++;

    int dotCount = length*length-str.length();
    for (int j = 0;j<dotCount;j++)
        str += ".";

    char** spiral = new char*[length];
    for (int i=0;i<length;i++)
        spiral[i] = new char[length];

    int k = 0;
    int row = 0, col = 0;
    int lastRow = length - 1, lastCol = length - 1;
    while (k < length*length)
    {
        for (int i=row;i<=lastCol;i++)
            spiral[row][i] = str[k++];
        for (int i=row+1;i<=lastRow;i++)
            spiral[i][lastCol] = str[k++];
        for (int i=lastCol-1;i>=col;i--)
            spiral[lastRow][i] = str[k++];
        for (int i=lastRow-1;i>=row+1;i--)
            spiral[i][col] = str[k++];
        row++; col++; lastRow--; lastCol--;
    }

    for (int i=0;i<length;i++) {
        for (int j = 0; j < length; j++)
            output << spiral[i][j];
        output << endl;
    }

    for (int i = 0; i < length; i++)
    {
        delete[] spiral[i];
    }
    delete[] spiral;

    output.close();
    return 0;
}