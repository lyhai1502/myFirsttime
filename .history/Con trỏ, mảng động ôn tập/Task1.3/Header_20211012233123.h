#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct thiSinh
{
    char *id, *hoVaTen, *ghiChu, *tinh;
    float toan, van, vatLy, hoaHoc, sinhHoc, lichSu, diaLy,
        giaoducCongDan, khoaHocTuNhien, khoaHocXaHoi, ngoaiNgu, tong;
};
thiSinh initThiSinh();
void deleteCharArray(char *str);
void strCpy(char *&a, char *b);
float charToNum(char *str);
thiSinh tachChuoiTuFile(char *str);
thiSinh docThongTinThiSinh(char *tenFile);
vector<thiSinh> docDanhSachThiSinh(char *tenFile);
char *daoNguocTen(char *&str);
void daoNguocTenThiSinh(vector<thiSinh> &danhSachThiSinh);
char *vietHoaTen(char *&str);
void vietHoaTenThiSinh(vector<thiSinh> &danhSachThiSinh);
void hoanDoiTen(char *&str1, char *&str2);
void doiTenThiSinh(vector<thiSinh> &danhSachThiSinh, char *ma1, char *ma2);
void tinhDiem(vector<thiSinh> &danhSachThiSinh);
void xuatFile(const vector<thiSinh> &danhSachThiSinh, char *tenFile);
