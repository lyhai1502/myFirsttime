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
void deleteCharArray(char *str)
{
    if (str != nullptr)
        delete[] str;
    else
        return;
}
void strCpy(char *&a, char *b)
{
    int n = strlen(b);
    free(a);
    a = new char[n + 1];
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    a[n] = '\0';
}
// ham chuyen string thanh float
float charToNum(char *str)
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
            ans = ans * nguyen + ((int)str[i] - 48) / (float)tphan;
            if (thapphan)
                tphan = tphan * 10;
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
    int index1 = 0, choice = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ',')
        {
            line[index1++] = str[i];
        }
        else
        {
            line[index1] = '\0';
            choice++;
            switch (choice)
            {
            case 1:
            {
                strCpy(thisinh.id, line);
                break;
            }
            case 2:
            {
                strCpy(thisinh.hoVaTen, line);
                break;
            }
            case 3:
            {
                thisinh.toan = charToNum(line);
                break;
            }
            case 4:
            {
                thisinh.van = charToNum(line);
                break;
            }
            case 5:
            {
                thisinh.vatLy = charToNum(line);
                break;
            }
            case 6:
            {
                thisinh.hoaHoc = charToNum(line);
                break;
            }
            case 7:
            {
                thisinh.sinhHoc = charToNum(line);
                break;
            }
            case 8:
            {
                thisinh.lichSu = charToNum(line);
                break;
            }
            case 9:
            {
                thisinh.diaLy = charToNum(line);
                break;
            }
            case 10:
            {
                thisinh.giaoducCongDan = charToNum(line);
                break;
            }
            case 11:
            {
                thisinh.khoaHocTuNhien = charToNum(line);
                break;
            }
            case 12:
            {
                thisinh.khoaHocXaHoi = charToNum(line);
                break;
            }
            case 13:
            {
                thisinh.ngoaiNgu = charToNum(line);
                break;
            }
            case 14:
            {
                strCpy(thisinh.ghiChu, line);
                break;
            }
            case 15:
            {
                strCpy(thisinh.tinh, line);
                break;
            }
            }
            deleteCharArray(line);
            line = new char[n];
            index1 = 0;
        }
    }
    return thisinh;
}
//Cai dat ham doc thong tin mot thi sinh
void docThongTinThiSinh(const char *tenFile)
{
    vector<thiSinh> list;
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        assert(false);
    }
    //Lay chuoi tu text
    char *str = new char[255];
    ifs.getline(str, 255);
    cout << str;
    thiSinh thisinh;
    thisinh = tachChuoiTuFile(str);
    cout << thisinh.id;
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
    vector<thiSinh> list;
    char *str = new char[255];
    ifs.getline(str, 255);
    cout << str << endl while (!ifs.eof())
    {
        str = new char[255];
        ifs.getline(str, 255);
        thiSinh thisinh = tachChuoiTuFile(str);
        cout << thisinh.id << endl;
        list.push_back(thisinh);
    }
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
