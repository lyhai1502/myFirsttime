#include <iostream>
#include <string>
using namespace std;
void Innguoc(string str)
{
    int index = str.length() - 1;
    while (str[index] == '0')
    {
        index--;
    }
    for (int i = index; i >= 0; i--)
    {
        cout << str[i];
    }
}
int main()
{
    string str;
    cin >> str;
    Innguoc(str);
    return 0;
}