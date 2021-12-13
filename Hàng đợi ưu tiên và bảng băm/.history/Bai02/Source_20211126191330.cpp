#include <iostream>
using namespace std;

struct CongTy
{
    string tenCongTy;
    string maSoThue;
    string diaChi;
};

long long HashString(const string &tenCongTy)
{
    int n = tenCongTy.length();
    string ans = "";
    for (int i = 0; i < 18; i++)
        ans += tenCongTy[n - 18 + i];
}
int main()
{
    string s = "vanlyhaivavanlydangaconggmailcom123";
    string ans;
    for (int i = 0; i < 18; i++)
        ans += s[s.length() - 18 + i];
    cout << ans;
    return 0;
}