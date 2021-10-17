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