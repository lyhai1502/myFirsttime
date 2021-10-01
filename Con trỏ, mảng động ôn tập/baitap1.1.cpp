#include <iostream>
using namespace std;

int func (int n, int k)
{
    return n+k;
}

int main()
{
    int *array = new int [6];
    array[1]=3;
    cout<<array[1];
}