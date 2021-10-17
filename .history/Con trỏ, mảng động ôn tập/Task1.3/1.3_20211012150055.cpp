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
//Ham tach chuoi va dua cac chuoi con vao mang dong
string *tachChuoi(string line, string delimiter)
{
    string *newString = new string;
    string token;
    size_t pos = 0;
    int indexArray = 0;
    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
        if (token == "")
            token = "0";
        newString[indexArray++] = token;
        line.erase(0, pos + delimiter.length());
    }
    newString[indexArray] = line;
    return newString;
}
//Cai dat thong tin thi sinh tu mang dong
thiSinh ganThongTin(string *saveValue)
{
    thiSinh thisinh;
    int indexArray = 0;
    thisinh.id = &saveValue[indexArray++][0];
    thisinh.hoVaTen = &saveValue[indexArray++][0];
    thisinh.toan = stof(saveValue[indexArray++]);
    thisinh.van = stof(saveValue[indexArray++]);
    thisinh.vatLy = stof(saveValue[indexArray++]);
    thisinh.hoaHoc = stof(saveValue[indexArray++]);
    thisinh.sinhHoc = stof(saveValue[indexArray++]);
    thisinh.lichSu = stof(saveValue[indexArray++]);
    thisinh.diaLy = stof(saveValue[indexArray++]);
    thisinh.giaoducCongDan = stof(saveValue[indexArray++]);
    thisinh.khoaHocTuNhien = stof(saveValue[indexArray++]);
    thisinh.khoaHocXaHoi = stof(saveValue[indexArray++]);
    thisinh.ngoaiNgu = stof(saveValue[indexArray++]);
    thisinh.ghiChu = &saveValue[indexArray++][0];
    thisinh.tinh = &saveValue[indexArray][0];

    return thisinh;
}
//Cai dat ham doc thong tin mot thi sinh
thiSinh docThongTinThiSinh(const char *tenFile)
{
    ifstream ifs;
    ifs.open(tenFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "\nKhong mo duoc file de doc!\n";
        ifs.close();
    }
    //Lay chuoi tu text
    char temp[255];
    ifs.getline(temp, 255);

    string line = temp;
    string delimiter = ",";

    string *newString = tachChuoi(line, delimiter);
    //dua cac chuoi con vao truong thi sinh
    thiSinh thisinh = ganThongTin(newString);
    ifs.close();
    return thisinh;
}

// //Cai dat ham doc thong tin danh sach cac thi sinh
// void docDanhSachThiSinh(char *tenFile)
// {
//     ifstream ifs;
//     ifs.open(tenFile, ios::in);
//     if (!ifs.is_open())
//     {
//         cout << "\nKhong mo duoc file de doc!\n";
//         ifs.close();
//     }
//     string line;
//     getline(ifs, line);
//     while (getline(ifs, line))
//     {

//         cout << x.diaLy << "\n";
//     }
//     // thiSinh thisinh = docThongTinThiSinh("data.txt");
//     // while (ifs.getline(tmp, 255))
//     // {
//     //     thiSinh thisinh = docThongTinThiSinh(tenFile);
//     //     cout << thisinh.id << endl;
//     //     //danhsach.push_back(thisinh);
//     // }
// }

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
    string s = "BD1200001,a van nguyen,4.0,5.0,,,,4.25,7.0,7.75,,,2.0,N1,BinhDinh";
    string *newS = tachChuoi(s, ",");
    cout << newS[15];
    thiSinh ts = ganThongTin(newS);
    cout << ts.id;
    return 0;
}
