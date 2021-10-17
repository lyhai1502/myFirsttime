#include "Header.h"
using namespace std;

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
// xoa mang dong char
void deleteCharArray(char *str)
{
    if (str != nullptr)
        delete[] str;
    else
        return;
}
// sao chep phan tu
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
// ham chuyen char thanh float
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
// ham tach cac chuoi con va dua vao truong thiSinh
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
// cai dat ham doc thong tin mot thi sinh
thiSinh docThongTinThiSinh(char *tenFile)
{
    cout << "Doc thong tin thi sinh thu may: ";
    int thu;
    cin >> thu;
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
    for (int i = 0; i <= thu; i++)
        ifs.getline(str, 255);
    thiSinh thisinh;
    thisinh = tachChuoiTuFile(str);
    ifs.close();
    return thisinh;
}
// cai dat ham doc thong tin danh sach cac thi sinh
vector<thiSinh> docDanhSachThiSinh(char *tenFile)
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
    vector<thiSinh> list;
    char *str = new char[255];
    while (!ifs.eof())
    {
        str = new char[255];
        ifs.getline(str, 255);
        thiSinh thisinh = tachChuoiTuFile(str);
        list.push_back(thisinh);
    }
    ifs.close();
    return list;
}
// ham dao nguoc ten thi sinh
char *daoNguocTen(char *&str)
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
    char *newStr = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
        newStr[i] = s[i];
    return newStr;
}
// ham dao nguoc ten cac thi sinh trong danh sach
void daoNguocTenThiSinh(vector<thiSinh> &danhSachThiSinh)
{
    int n = danhSachThiSinh.size();
    for (int i = 0; i < n; i++)
    {
        danhSachThiSinh[i].hoVaTen = daoNguocTen(danhSachThiSinh[i].hoVaTen);
    }
}
// ham viet hoa ten
char *vietHoaTen(char *&str)
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
// ham viet hoa cac ten trong danh sach
void vietHoaTenThiSinh(vector<thiSinh> &danhSachThiSinh)
{
    int n = danhSachThiSinh.size();
    for (int i = 0; i < n; i++)
    {
        danhSachThiSinh[i].hoVaTen = vietHoaTen(danhSachThiSinh[i].hoVaTen);
    }
}
// ham hoan vi ten
void hoanDoiTen(char *&str1, char *&str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}
// ham hoan vi ten trong danh sach
void doiTenThiSinh(vector<thiSinh> &danhSachThiSinh)
{
    cout << "Nhap lan luot MA SO SINH VIEN 2 sinh vien can hoan doi:\n";
    char *ma1 = new char;
    cout << "Sinh vien 1: ";
    cin.getline(ma1, 255);
    char *ma2 = new char;
    cout << "Sinh vien 2: ";
    cin.getline(ma2, 255);

    int n = danhSachThiSinh.size();
    int ma1_index = -1, ma2_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(danhSachThiSinh[i].id, ma1) == 0)
            ma1_index = i;
        if (strcmp(danhSachThiSinh[i].id, ma2) == 0)
            ma2_index = i;
    }
    if (ma1_index == -1 || ma2_index == -1)
    {
        cout << "Khong co sinh vien can doi ten!\n";
        assert(false);
        return;
    }
    hoanDoiTen(danhSachThiSinh[ma1_index].hoVaTen, danhSachThiSinh[ma2_index].hoVaTen);
}
// ham tinh diem
void tinhDiem(vector<thiSinh> &danhSachThiSinh)
{
    int n = danhSachThiSinh.size();
    for (int i = 0; i < n; i++)
    {
        danhSachThiSinh[i].khoaHocTuNhien = danhSachThiSinh[i].toan + danhSachThiSinh[i].vatLy + danhSachThiSinh[i].hoaHoc;
        danhSachThiSinh[i].khoaHocXaHoi = danhSachThiSinh[i].lichSu + danhSachThiSinh[i].diaLy + danhSachThiSinh[i].giaoducCongDan;
        danhSachThiSinh[i].tong = danhSachThiSinh[i].toan + danhSachThiSinh[i].van + danhSachThiSinh[i].ngoaiNgu + danhSachThiSinh[i].khoaHocTuNhien + danhSachThiSinh[i].khoaHocXaHoi;
    }
}
// ham xuat du lieu ra file
void xuatFile(const vector<thiSinh> &danhSachThiSinh, char *tenFile)
{
    ofstream ofs;
    ofs.open(tenFile, ios::out);
    if (!ofs.is_open())
    {
        cout << "Khong mo duoc file";
        assert(false);
    }
    int n = danhSachThiSinh.size();
    ofs << "So bao danh, Ho va ten, Diem thi KHTN, Diem thi KHXH, Diem tong:\n";
    for (int i = 0; i < n; i++)
    {
        ofs << danhSachThiSinh[i].id << "," << danhSachThiSinh[i].hoVaTen << "," << danhSachThiSinh[i].khoaHocTuNhien << "," << danhSachThiSinh[i].khoaHocXaHoi << "," << danhSachThiSinh[i].tong << endl;
    }
    ofs.close();
}
