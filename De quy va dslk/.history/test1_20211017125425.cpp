#include <iostream>
#include <fstream>
using namespace std;

struct Phanso
{
    int tu;
    int mau;
} PS;
int main()
{
    ifstream fileIn;
    fileIn.open("doc.txt", ios_base::in);
    if (!fileIn.is_open())
    {
        cout << "False to open the file";
        assert(false);
    }

    double sum = 0;
    int n;
    fileIn >> n;
    PS a;
    while (!fileIn.eof())
    {
        fileIn >> a.tu;
        char x;
        fileIn >> x;
        fileIn >> a.mau;
        sum += (double)a.tu / (double)a.mau;
    }
    cout << sum;
    fileIn.close();
    return 0;
}