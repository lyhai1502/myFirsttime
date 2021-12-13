#include <iostream>
using namespace std;

int main()
{
    string ans = "CONG TY TNHH BEE VIET NAM";
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        result += ((int)ans[i] * Pow(p, i)) % m;
        result = result % m;
    }
    return 0;
}