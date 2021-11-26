#include "Source.cpp"
using namespace std;

int main()
{

    //BAI 1: In tong S = 1 + 2 + ... + n
    int n = 9;
    cout << "\nTong S = 1 + 2 + ... + n , voi n = " << n << " la: S = " << sumOf_S(n);

    //BAI 2: In so Fibonacci thu n
    int m = 7;
    cout << "\nSo Fibonacci thu " << n << " : " << fibonacci(m);

    //BAI 3: In uoc chung lon nhat cua 2 so
    int a = 21, b = 18;
    cout << "\nUoc chung lon nhat cua " << a << " va " << b << " : " << ucln(a, b);

    //BAI 4: Tra ve vi tri xuat hien key trong mang
    int arr[] = {-10, -9, -2, 3, 4, 8, 11, 80, 118};
    int N = sizeof(arr) / sizeof(arr[0]);
    int X = 11;
    cout << "\nGia tri " << X << " trong mang dong tai vi tri thu : " << recurseBinarySearch(arr, 0, N - 1, X);

    //BAI 5: In tat cac cac hoan vi
    // char str[] = "ABCDE";
    // hoanViKyTu(str, 0, strlen(str) - 1);
    return 0;
}