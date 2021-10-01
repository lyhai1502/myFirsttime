#include <iostream>
using namespace std;

int func(int n, int k)
{
    return n == k;
}

int main()
{
    int *array = new int[6];
    cout << (func(1, 2) ? "OK" : "NO");
}