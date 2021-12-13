#include <iostream>
#include <vector>
using namespace std;

int m = 100019;
vector<string> hashTable[100019];

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
// Ham bam
long long HashString(const string &tenCongTy)
{
    int p = 31;
    int m = 100019;

    int n = tenCongTy.length();
    string ans = "";
    for (int i = 0; i < 18; i++)
        ans += tenCongTy[n - 18 + i];
    long long result = 0;
    for (int i = 0; i < ans.length(); i++)
    {
        result += ((char)ans[i] * Pow(p, i)) % m;
        result %= m;
    }
    return result;
}

// Xu ly dung do
void Chaining(vector<string> *&hashTable, string s)
{
}
int main()
{
    cout << HashString("CONG TY TNHH BEE VIET NAM");
    return 0;
}