#include "Source.cpp"
using namespace std;

int main()
{
    string s = "hello";
    char *c = convertToChar(s);
    cout << c[1];
    return 0;
}