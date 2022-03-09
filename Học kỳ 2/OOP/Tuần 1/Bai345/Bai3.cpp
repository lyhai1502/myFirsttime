#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void input();       // nhap
    void isLeapYear();  // kiem tra nam nhuan
};

void Date::input()
{
    cout << "Nhap lan luot ngay thang nam: ";
    cin >> day >> month >> year;
}

void Date::isLeapYear()
{
    if (year % 4 == 0)
        if (year % 400 != 0 && year % 100 == 0)
            cout << "Nam khong nhuan!";
        else
            cout << "Nam nhuan!";
    else
        cout << "Nam khong nhuan!";
}

int main()
{
    Date date;
    date.input();
    date.isLeapYear();
    return 0;
}