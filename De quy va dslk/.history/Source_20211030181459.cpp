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

// Tim kiem phan tu su dung thuat toan nhi phan
int recurseBinarySearch(int *a, int left, int right, int key)
{
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn

        // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
        if (arr[mid] == x)
            return mid;

        // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
        return binarySearch(arr, mid + 1, r, x);
    }

    // Nếu không tìm thấy
    return -1;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Hoan vi cac ky tu
// "A,B,C,D,E" -> ABCDF, ACDEB,...
void hoanViKyTu(char *a, int left, int right)
{
    int i;
    if (left == right)
        cout << a << "\n";
    else
    {
        for (i = left; i <= right; i++)
        {
            swap((a + left), (a + i));
            hoanViKyTu(a, left + 1, right);
            swap((a + left), (a + i));
        }
    }
}

int main()
{
    int a[] = {4, 6, 1, 9, 10, 2, -3, -1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << binarySearch(a, 0, n; - 3);
    // char str[] = "ABCDE";
    // hoanViKyTu(str, 0, strlen(str) - 1);
    return 0;
}