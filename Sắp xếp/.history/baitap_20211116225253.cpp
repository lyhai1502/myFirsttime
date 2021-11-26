#include <iostream>
using namespace std;

void cau3(int a[], int n)
{
    if (n <= 2)
        return;
    int i = 0;
    int j = 1;
    while (i < j)
    {
        while (i < n && a[i] > 0)
            i += 2;
        while (j < n && a[j] < 0)
            j += 2;
        swap(a[i], a[j]);
        i += 2;
        j += 2;
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {1, 8, -2, 5, -3, -7, 8, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cau3(arr, n);
    printArray(arr, n);
    return 0;
}