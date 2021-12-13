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
CongTy *hashTable = new CongTy[10];

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
        hashTable[index++] = tachChuoi(tmp);
    }
    ifs.close();
}
int main()
{
    readHashTable(hashTable, "mst1.txt");
    cout << hashTable[1].tenCongTy;
    //cout << hashTable[73846].diaChi;
    return 0;
}