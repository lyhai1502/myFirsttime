#include "List.h"
void List::inputList()
{
    int index = 0;
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