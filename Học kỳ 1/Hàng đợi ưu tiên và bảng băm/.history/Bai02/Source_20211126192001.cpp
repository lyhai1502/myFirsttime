#include <iostream>
using namespace std;

struct CongTy
{
    string tenCongTy;
    string maSoThue;
    string diaChi;
};

long long Pow(int a, int b)
{
    int ans = a;
    for (int i = 1; i < b; i++)
        ans *= a;
    return ans;
}
long long HashString(const string &tenCongTy)
{
    int p = 31;
    int m = 100019;

    int n = tenCongTy.length();
    string ans = "";
    for (int i = 0; i < 18; i++)
        ans += tenCongTy[n - 18 + i];
    int result = 0;
    for (int i = 0; i < ans.length(); i++)
    {
        result += (char)ans[i] * Pow(p, i);
        cout << result << endl;
        return result % m;
    }
    int main()
    {
        cout << HashString("CONG TY TNHH BEE VIET NAM");
        return 0;
    }