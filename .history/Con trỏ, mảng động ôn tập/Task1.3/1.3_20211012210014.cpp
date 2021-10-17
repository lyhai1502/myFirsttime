#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct thiSinh
{
    char *id, *hoVaTen, *ghiChu, *tinh;
    float toan, van, vatLy, hoaHoc, sinhHoc, lichSu, diaLy,
        giaoducCongDan, khoaHocTuNhien, khoaHocXaHoi, ngoaiNgu;
};
// khoi tao bien thiSinh
thiSinh initThiSinh()
{
    thiSinh thisinh;
    thisinh.id = nullptr;
    thisinh.hoVaTen = nullptr;
    thisinh.ghiChu = nullptr;
    thisinh.tinh = nullptr;
    return thisinh;
}
void deleteStringArray(string *str)
{
    if (str != nullptr)
        delete[] str;
    else
        return;
}
// ham chuyen string thanh float
float stringToNum(char *str)
{
    int n = strlen(str);
    if (n == 0)
        return 0;
    float ans = 0;
    int nguyen = 10;
    int tphan = 1;
    bool thapphan = false;
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '.')
        {
            ans = ans * nguyen + (float)((int)str[i] - 48) / tphan;
            if (thapphan)
                tphan *= 10;
        }
        else
        {
            thapphan = true;
            nguyen = 1;
            tphan = 10;
        }
    }
    return ans;
}
//Ham tach chuoi va dua cac chuoi con vao mang dong
thiSinh tachChuoiTuFile(char *str)
{
    int n = strlen(str);
    char *line = new char[n];
    thiSinh thisinh = initThiSinh();
    int index = 0, choice = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ',')
        {
            line[index++] = str[i];
        }
        else
        {
            line[i] = '\0';
        }
    }
}
//Cai dat thong tin thi sinh tu mang dong
//Cai dat ham doc thong tin mot thi sinh
thiSinh docThongTinThiSinh(const char *tenFile)
{
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        assert(false);
    }
    //Lay chuoi tu text
    string line;
    getline(ifs, line);

    return thisinh;
}
//Cai dat ham doc thong tin danh sach cac thi sinh
void docDanhSachThiSinh(const char *tenFile)
{
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        assert(false);
    }
    char *temp = new char[255];
    ifs.getline(temp, 255);
    ifs.close();
    // thiSinh thisinh = docThongTinThiSinh("data.txt");
    // while (ifs.getline(tmp, 255))
    // {
    //     thiSinh thisinh = docThongTinThiSinh(tenFile);
    //     cout << thisinh.id << endl;
    //     //danhsach.push_back(thisinh);
    // }
}

//dao nguoc ten thi sinh
char *daoNguoc(char *&str)
{
    char *p = strtok(str, " ");
    string *saveString = new string;
    int ind = 0;
    while (p != NULL)
    {
        saveString[ind++] = p;
        p = strtok(NULL, " ");
    }
    string s = "";
    string delimeter = " ";
    for (int i = ind - 1; i >= 0; i--)
    {
        if (i == 0)
            s = s.append(saveString[i]);
        else
            s = s.append(saveString[i]).append(delimeter);
    }
    str = &s[0];
    return str;
}
// void daoNguocTenThiSinh(vector<thiSinh> &danhSachThiSinh)
// {
// }
// ham viet hoa ten
char *vietHoa(char *&str)
{
    char *p = str;
    p[0] = toupper(p[0]);
    while (strstr(p, " ") != NULL)
    {
        p = strstr(p, " ") + 1;
        p[0] = toupper(p[0]);
    }
    return str;
}

void hoanDoiTen(char *&str1, char *&str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
    cout << str1 << " " << str2;
}

void tinhDiem(vector<thiSinh> &danhSachThiSinh)
{
}

int main()
{
    docDanhSachThiSinh("data.txt");
    return 0;
}
