#include <iostream>
using namespace std;

int main()
{
    string ans = "CONG TY TNHH BEE VIET NAM";
    int result = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        result += ((int)ans[i] * pow(31, i)) % 100019;
        result = result % 100019;
    }
    return 0;
}