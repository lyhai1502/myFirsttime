#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    string hoTen;
    unsigned int MSSV;
    double diemTongKetNam;

public:
    void inputSinhVien();
    void outputSinhVien();
    int getScore();
};

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

int SinhVien::getScore()
{
    return diemTongKetNam;
}
class List
{
private:
    unsigned int amountOfSinhVien;
    SinhVien list[1000];

public:
    void inputList();
    void outputList();
    void sortScores();
};
void List::inputList()
{
    int index = 0;
    int count;
    cout << "Nhap so luong sinh vien: ";
    cin >> amountOfSinhVien;
    for (int i = 0; i < amountOfSinhVien; i++)
    {
        cout << "Sinh vien " << i + 1;
        list[index++].inputSinhVien();
    }
}

void List::outputList()
{
    cout << "----------XUAT DANH SACH SINH VIEN----------\n";
    for (int i = 0; i < amountOfSinhVien; i++)
    {
        cout << "Sinh vien " << i + 1 << endl;
        list[i].outputSinhVien();
        cout << endl;
    }
}
void List::sortScores()
{
    for (int i = 0; i < amountOfSinhVien - 1; i++)
        for (int j = i + 1; j < amountOfSinhVien; j++)
            if (list[i].getScore() > list[j].getScore())
            {
                SinhVien tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
}

int main()
{
    List list;
    list.inputList();
    list.sortScores();
    list.outputList();
    return 0;
}