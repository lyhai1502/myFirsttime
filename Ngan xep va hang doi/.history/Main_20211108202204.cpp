#include "Source.cpp"
using namespace std;

int main()
{
    char a[] = "1+1";
    stackNode s = createStack();
    pushStack(s, (char)a[1] - '0');
    printStack(s);
    cout << endl;
    cout << (int)'+';
    //char *z = trungToSangHauTo(a);
    // for (int i = 0; i <= strlen(z) - 1; i++)
    //     cout << z[i];
    return 0;
}