#include "Source.cpp"

int main()
{
    cin >> n;

    inputArray(arr1, n);
    inputArray(arr2, n);

    cout << '\n'
         << Bai02(arr1, arr2, n);

    return 0;
}