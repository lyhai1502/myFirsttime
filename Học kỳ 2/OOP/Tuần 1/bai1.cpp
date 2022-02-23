#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string hoTen;
    float diemToan;
    float diemVan;

public:
    Student(string hoten, float diemtoan, float diemvan)
    {
        hoTen = hoten;
        diemToan = diemtoan;
        diemVan = diemvan;
    }

    void display()
    {
        cout << hoTen << endl;
        cout << "Diem toan: " << diemToan << endl;
        cout << "Diem van: " << diemVan << endl;
    }
};

int main()
{
    Student A("vanlyhai", 10, 9);
    A.display();
    return 0;
}