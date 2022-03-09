#pragma once
#include <iostream>
#include <string>
using namespace std;
class SinhVien
{
private:
    string hoTen;
    int MSSV;
    double diemTongKetNam;

public:
    void inputSinhVien();
    void outputSinhVien();
    double getScore();
};

