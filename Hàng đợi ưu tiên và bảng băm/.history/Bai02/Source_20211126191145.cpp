#include <iostream>
using namespace std;

struct CongTy
{
    string tenCongTy;
    string maSoThue;
    string diaChi;
};

// long long HashString(const string &tenCongTy)
// {
//     int n = tenCongTy.length();

// }
int main()
{
    string s = "vanlyhaivavanlydangaconggmailcom123";
    string ans;
    for (int i = 0; i < s.length(); i++)
        ans += s[s.length() - 1 - 18 + i];
    return 0;
}