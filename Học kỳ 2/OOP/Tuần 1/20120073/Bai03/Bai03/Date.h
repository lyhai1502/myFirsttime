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
    void input();       // nhap
    void isLeapYear();  // kiem tra nam nhuan
};

