#include "Source.cpp"
using namespace std;

int main()
{
    char a[] = "X+Y*Z";
    char *z = new char;
    z = trungToSangHauTo(a);
    cout << z[0] << z[1] << z[2] << z[3] << z[4] << z[5];
    return 0;
}