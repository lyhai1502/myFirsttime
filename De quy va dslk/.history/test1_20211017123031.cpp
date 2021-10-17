#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fileIn;
    fileIn.open("doc.txt", ios_base::in);
    if (!fileIn.is_open())
    {
        cout << "False to open the file";
        assert(false);
    }
    while (!fileIn.eof())
    {
        string s;
        getline(fileIn, s, "\n");
    }
}