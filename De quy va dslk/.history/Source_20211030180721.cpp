#include <iostream>
using namespace std;

// Tinh S=1+2+3+...+n
int sumOf_S(int n)
{
    if (n == 1)
        return 1;
    return n + sumOf_S(n - 1);
}

// Tinh so Fibonacci thu n
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tinh uoc chung lon nhat 2 so nguyen a,b
int ucln(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    if (a == b)
        return a;
    else if (a > b)
        return ucln(a - b, b);
    else
        return ucln(a, b - a);
}

// tim kiem phan tu su dung thuat toan nhi phan
int recurseBinarySearch(int *a, int left, int right, int key)
{
}

// in ra cac hoan vi duoc tao thanh tu cac ky tu
// "A,B,C,D,E" -> ABCDF, ACDEB,...
void hoanViKyTu(char *list, int i, int n)
{
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Hoan vi cac ky tu
void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        cout << a;
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); //backtrack
        }
    }
}

int main()
{
    char str[] = "ABC";
    permute(str, 0, strlen(str) - 1);
    return 0;
}