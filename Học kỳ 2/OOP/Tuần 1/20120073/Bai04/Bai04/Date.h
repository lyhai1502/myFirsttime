#pragma once
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

