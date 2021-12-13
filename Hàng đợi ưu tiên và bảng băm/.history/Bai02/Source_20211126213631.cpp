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
    for (int i = 0; i < ans.size(); i++)
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
                congTy.diaChi = str.substr(i + 1);
                break;
            }
            }
        }
    }
    return congTy;
}
CongTy *readHashTable(CongTy *hashTable, const char *tenFile)
{
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        assert(false);
    }
    int index = 0;
    char *tmp = new char[255];
    ifs.getline(tmp, 255);
    while (!ifs.eof())
    {
        tmp = new char[255];
        ifs.getline(tmp, 255);
        hashTable[index++] = tachChuoi(tmp);
    }
}
int main()
{
    string s = "CONG1 TY CO PHAN KY THUAT PHONG SACH THANH TAM|0108912989|So nha LK10-TT2, khu nha o 96+ 96B Nguyen Huy Tuong, Phuong Thanh Xuan Trung, Quan Thanh Xuan, Thanh pho Ha Noi";
    CongTy ct;
    ct = tachChuoi(s);
    cout << ct.diaChi;
    return 0;
}