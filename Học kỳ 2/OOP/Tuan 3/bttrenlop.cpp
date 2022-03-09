// 20120073 Van Ly Hai
#include <iostream>
using namespace std;
class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo();
    PhanSo(int, int);
    void display();
    PhanSo &operator++();
    PhanSo operator++(int);
    bool operator>(const PhanSo &);
    friend istream &operator>>(istream &, PhanSo &);
    friend ostream &operator<<(ostream &, PhanSo);
};

PhanSo::PhanSo(int a, int b)
{
    tu = a;
    mau = b;
}

void PhanSo::display()
{
    cout << tu << "/" << mau << endl;
}

PhanSo &PhanSo::operator++() // prefix
{
    tu += mau;
    return *this;
}

PhanSo PhanSo::operator++(int) // postfix
{
    PhanSo tmp = *this;
    (*this).tu += (*this).mau;
    return tmp;
}

bool PhanSo::operator>(const PhanSo &b)
{
    return tu * b.mau > mau * b.tu;
}

istream &operator>>(istream &is, PhanSo &ps)
{
    cout << "Nhap tu: ";
    is >> ps.tu;
    cout << "Nhap mau: ";
    is >> ps.mau;
    return is;
}

ostream &operator<<(ostream &os, PhanSo ps)
{
    os << ps.tu << "/" << ps.mau;
    return os;
}
int main()
{
    PhanSo ps(1, 2);
    cin >> ps;
    cout << ps;
    return 0;
}