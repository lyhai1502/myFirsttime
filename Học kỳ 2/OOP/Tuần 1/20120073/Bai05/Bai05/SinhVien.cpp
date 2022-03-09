#include "SinhVien.h"
void SinhVien::inputSinhVien()
{
    while (getchar() != '\n')
        ;
    cout << "\n\tNhap ho ten sinh vien: ";
    getline(cin, hoTen);
    cout << "\tNhap MSSV: ";
    cin >> MSSV;
    cout << "\tNhap diem tong ket nam: ";
    cin >> diemTongKetNam;
}

void SinhVien::outputSinhVien()
{
    cout << "\tHo ten: " << hoTen;
    cout << "\n\tMa so: " << MSSV;
    cout << "\n\tDiem tong ket nam: " << diemTongKetNam;
}

double SinhVien::getScore()
{
    return diemTongKetNam;
}