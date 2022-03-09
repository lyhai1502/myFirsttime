#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void input();               // nhap
    bool isInvalidDate();       // kiem tra ngay co hop le
    bool isLeapYear();          // kiem tra nam nhuan
    int numberDaysOfMonth();    // tra ve so ngay trong thang
    void nextDay();             // ngay tiep theo
};

bool Date::isLeapYear()
{
    if (year % 4 == 0)
        if (year % 400 != 0 && year % 100 == 0)
            return false;
        else
            return true;
    else
        return false;
}
int Date::numberDaysOfMonth()
{
    if (month < 1 || month > 12)
        return 0;
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 2 && isLeapYear())
        return 29;
    else if (month == 2 && !isLeapYear())
        return 28;
    else
        return 30;
}
bool Date::isInvalidDate()
{
    if (day >= 1 && day <= numberDaysOfMonth())
        return true;
    else
        return false;
}
void Date::input()
{
    cout << "Nhap ngay thang nam: ";
    cin >> day >> month >> year;
    while (!isInvalidDate())
    {
        cout << "Khong ton tai ngay nay, hay nhap lai: ";
        cin >> day >> month >> year;
    }
}
void Date::nextDay()
{
    cout << "Ngay mai cua ngay vua nhap: ";
    if (day == numberDaysOfMonth())
        if (month == 12)
            cout << "1/1/" << year + 1;
        else
            cout << "1/" << month + 1 << "/" << year;
    else
        cout << day + 1 << "/" << month << "/" << year;
}
int main()
{
    Date date;
    date.input();
    date.nextDay();
    return 0;
}