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
int binarySearch(int *a, int left, int right, int key)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn
        // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
        if (a[mid] == key)
            return mid;

        // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
        if (a[mid] > key)
            return binarySearch(a, left, mid - 1, key);

        // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
        return binarySearch(a, mid + 1, right, key);
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
    int a[] = {-10, -9, -2, 3, 4, 8, 11, 80, 118};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1;
    cout << binarySearch(a, 0, n - 1, x);
    // char str[] = "ABCDE";
    // hoanViKyTu(str, 0, strlen(str) - 1);
    return 0;
}