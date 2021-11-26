#include "Source.cpp"
using namespace std;

int main()
{
    char *prefix = "*-1/23-/189";
    char *c = prefixToPostfix(prefix);
    for (int i = 0; i < strlen(c); i++)
        cout << c[i];
    return 0;
}