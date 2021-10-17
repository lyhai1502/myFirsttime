#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct monHoc
{
    string tenMonHoc;
    double diem;
};
typedef struct monHoc MONHOC struct sinhVien
{
    string hoten;
    string maso;
    string namsinh;
    vector<MONHOC> dsMonHoc;
};
typedef struct sinhVien SINHVIEN;

int main()
{
    ifstream fileIn;
    fileIn.open("doc.txt", ios_base::in);
    if (!fileIn.is_open())
    {
        cout << "False to open the file";
        assert(false);
    }

    fileIn.close();
    return 0;
}