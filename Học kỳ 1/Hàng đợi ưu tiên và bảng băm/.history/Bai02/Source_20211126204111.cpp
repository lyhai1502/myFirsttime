#include <iostream>
#include <vector>
using namespace std;
struct CongTy
{
    string tenCongTy;
    string maSoThue;
    string diaChi;
};

int charCount = 18;
int p = 31;
int m = 100019;
CongTy hashTable[10019];

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
    int n = tenCongTy.length();
    string ans = "";
    for (int i = 0; i < charCount; i++)
        ans += tenCongTy[n - charCount + i];
    long long result = 0;
    for (int i = 0; i < ans.length(); i++)
    {
        result += ((char)ans[i] * Pow(p, i)) % m;
        result %= m;
    }
    return result;
}

// Xu ly dung do
// void Chaining(vector<string> *&hashTable, string tenCongTy)
// {
//     int index = HashString(tenCongTy);
//     hashTable[index].push_back(tenCongTy);
// }

void openAddressing(CongTy *hashTable, string tenCongTy)
{
    long long index = HashString(tenCongTy);
    while (hashTable[index].tenCongTy != "")
        index = (index + 1) % m;
    hashTable[index].tenCongTy = tenCongTy;
}

CongTy *readHashTable(CongTy *hashTable, const char *tenFile)
{
}
int main()
{
    cout << HashString("CONG TY TNHH BEE VIET NAM");
    return 0;
}