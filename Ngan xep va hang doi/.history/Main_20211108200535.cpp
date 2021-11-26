#include "Source.cpp"
using namespace std;

int main()
{
    stackNode s;
    pushStack(s, 11);
    if (s.head->next == NULL)
        cout << "co rong";

    return 0;
    // char a[] = "8/4";
    // char *z = new char;
    // z = trungToSangHauTo(a);
    // cout << z[0] << z[1] << z[2] << z[3] << z[4] << z[5] << z[6];
    // return 0;
}