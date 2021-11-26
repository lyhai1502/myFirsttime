#include "Source.cpp"
using namespace std;

int main()
{
    char a[] = "1-4*2";
    char *z = new char;
    z = trungToSangHauTo(a);
    cout << z[0] << z[1] << z[2] << z[3] << z[4] << z[5];
    return 0;
}