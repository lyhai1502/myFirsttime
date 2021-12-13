#include <iostream>
#include <vector>
#include <fstream>
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
CongTy *hashTable = new CongTy[m];

long long modPow(int a, int b)
{
    int ans = a;
    for (int i = 1; i < b; i++)
    {
        ans *= a;
        ans = ans % m;
    }
    return ans;
}
bool isCongTy_Empty(CongTy congTy)
{
    if (congTy.diaChi != "" || congTy.tenCongTy != "" || congTy.maSoThue != "")
        return 0;
    else
        return 1;
}
// Ham bam
long long HashString(const string &tenCongTy)
{
    int n = tenCongTy.length();
    string ans = "";
    for (int i = 0; i < charCount; i++)
        ans += tenCongTy[n - charCount + i];
    long long result = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        result += ((int)ans[i] * modPow(p, i)) % m;
        result = result % m;
    }
    return result;
}

// Xu ly dung do
void openAddressing(CongTy *hashTable, CongTy congTy)
{
    long long index = HashString(congTy.tenCongTy);
    while (hashTable[index].tenCongTy != "")
        index = (index + 1) % m;

    hashTable[index].tenCongTy = congTy.tenCongTy;
    hashTable[index].maSoThue = congTy.maSoThue;
    hashTable[index].diaChi = congTy.diaChi;
}
CongTy initCongTy()
{
    CongTy congTy;
    congTy.diaChi = "";
    congTy.maSoThue = "";
    congTy.tenCongTy = "";
    return congTy;
}
CongTy tachChuoi(string str)
{
    int n = str.size();
    CongTy congTy = initCongTy();
    int choice = 0, save;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '|')
        {
            choice++;
            switch (choice)
            {
            case 1:
            {
                congTy.tenCongTy = str.substr(0, i);
                save = i + 1;
                break;
            }
            case 2:
            {
                congTy.maSoThue = str.substr(save, i - save);
                congTy.diaChi = str.substr(i + 1, n);
                break;
            }
            }
        }
    }
    return congTy;
}

void readHashTable(CongTy *hashTable, const char *tenFile)
{
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        assert(false);
    }
    string tmp;
    int index = 0;
    getline(ifs, tmp, '\n');
    while (!ifs.eof())
    {
        tmp = new char[255];
        getline(ifs, tmp, '\n');
        if (tmp[tmp.size() - 1] > 'z' || tmp[tmp.size() - 1] < 'a')
            tmp.pop_back();
        CongTy ct = tachChuoi(tmp);
        openAddressing(hashTable, ct);
    }
    ifs.close();
}
int main()
{
    string s = "CONG TY TNHH MEGA JARAI MADIRI";
    readHashTable(hashTable, "mst.txt");
    if (!isCongTy_Empty(hashTable[HashString(s)]))
        cout << hashTable[HashString(s)].diaChi << endl;
    else
        cout << "Khong co du lieu!";
    return 0;
}