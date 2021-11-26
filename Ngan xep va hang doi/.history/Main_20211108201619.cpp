#include "Source.cpp"
using namespace std;

int main()
{
    char a[] = "8";
    char *z = trungToSangHauTo(a);
    for (int i = 0; i < strlen(z) - 1; i++)
        cout << z[i];
    return 0;
}