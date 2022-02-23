#include <iostream>
using namespace std;
long long Pow(int a, int b)
{
    int ans = a;
    for (int i = 1; i < b; i++)
        ans *= a;
    return ans;
}
int main()
{
    string ans = " TNHH BEE VIET NAM";
    long long result = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        result += ((int)ans[i] * Pow(31, i)) % 100019;
        result = result % 100019;
        cout << result << endl;
    }
    cout << result;
    return 0;
}