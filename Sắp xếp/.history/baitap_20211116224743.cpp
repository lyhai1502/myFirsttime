#include <iostream>
using namespace std;

void cau3(int a[], int n)
{
    if (n <= 2)
        return;
    int i = 0;
    int j = 1;
    while (i < n && a[i] > 0)
        i += 2;
    while (j < n && a[j] < 0)
        j += 2;
}