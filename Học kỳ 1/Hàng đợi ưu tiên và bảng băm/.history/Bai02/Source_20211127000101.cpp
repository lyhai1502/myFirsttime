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

// Luy thua lay du
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

// Kiem tra bang bam co rong hay ko
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

// Them 1 cong ty vao bang bam co xu ly dung do
void insert(CongTy congTy)
{
    long long index = HashString(congTy.tenCongTy);

    // Xu ly dung do Open Addressing
    while (hashTable[index].tenCongTy != "")
        index = (index + 1) % m;

    hashTable[index].tenCongTy = congTy.tenCongTy;
    hashTable[index].maSoThue = congTy.maSoThue;
    hashTable[index].diaChi = congTy.diaChi;
}

// Khoi tao mot cong ty
CongTy initCongTy()
{
    CongTy congTy;
    congTy.diaChi = "";
    congTy.maSoThue = "";
    congTy.tenCongTy = "";
    return congTy;
}

// Tach cac thanh phan tu chuoi duoc doc trong file
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

// Xay dung bang bam doc tu file
void readHashTable(const char *tenFile)
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
        insert(ct);
    }
    ifs.close();
}

// Tim kiem phan tu trong bang bam
void search(string tenCongTy)
{
    if (!isCongTy_Empty(hashTable[HashString(tenCongTy)]))
    {
        cout << "\nTen cong ty: " << hashTable[HashString(tenCongTy)].tenCongTy << endl;
        cout << "Ma so thue: " << hashTable[HashString(tenCongTy)].maSoThue << endl;
        cout << "Dia chi: " << hashTable[HashString(tenCongTy)].diaChi << "\n\n";
    }
    else
        cout << "Khong co du lieu!";
}
int main()
{
    readHashTable("mst.txt");

    search("CONG TY CO PHAN XAY DUNG DAU TU PHAT TRIEN DI SAN SAO VIET");
    return 0;
}