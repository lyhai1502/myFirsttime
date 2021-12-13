#include <iostream>
using namespace std;

int main()
{
    string s = "CONG TY TNHH BEE VIET NAM";
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (int)s[i];
        cout << sum << endl;
        return 0;
    }