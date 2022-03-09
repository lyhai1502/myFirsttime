// 20120073 Van Ly Hai
#include <iostream>
using namespace std;

class Ctime
{
private:
    int hour, minute, second;

public:
    Ctime(int h, int m, int s);
    bool operator>=(Ctime);
    void display();
    Ctime addTime(const Ctime &);
    Ctime minusTime(const Ctime &);
    Ctime operator++();
    Ctime operator--(int);
};

Ctime::Ctime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Ctime::display()
{
    cout << hour << ":" << minute << ":" << second << endl;
}
bool Ctime::operator>=(Ctime src)
{
    if (hour > src.hour)
        return true;
    else if (hour < src.hour)
        return false;
    else
    {
        if (minute > src.minute)
            return true;
        else if (minute < src.minute)
            return false;
        else
        {
            if (second >= src.second)
                return true;
            else
                return false;
        }
    }
}

Ctime Ctime::addTime(const Ctime &src)
{
    this->hour += src.hour;
    this->minute += src.minute;
    this->second += src.second;
    while (second >= 60)
    {
        second -= 60;
        minute++;
    }
    while (minute >= 60)
    {
        minute -= 60;
        hour++;
    }
    while (hour >= 24)
    {
        hour -= 24;
    }
    return *this;
}
Ctime Ctime::minusTime(const Ctime &src)
{
    this->hour -= src.hour;
    this->minute -= src.minute;
    this->second -= src.second;
    while (second < 0)
    {
        second += 60;
        minute--;
    }
    while (minute < 0)
    {
        minute += 60;
        hour--;
    }
    while (hour < 0)
    {
        hour += 24;
    }
    return *this;
}

Ctime Ctime::operator++()
{
    this->second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    if (hour == 24)
    {
        hour = 0;
    }
    return *this;
}

Ctime Ctime::operator--(int)
{
    Ctime tmp = *this;
    this->second -= 1;
    if (this->second < 0)
    {
        this->second = 59;
        this->minute--;
    }
    if (this->minute < 0)
    {
        this->minute = 59;
        this->hour--;
    }
    if (this->hour < 0)
    {
        this->hour = 23;
    }
    return tmp;
}
int main()
{
    Ctime tm(0, 0, 0);
    Ctime src(18, 55, 30);
    // bool a = tm >= src;
    // cout << a;
    Ctime ans = tm--;
    tm.display();
    return 0;
}