#include "Source.cpp"

int main()
{
    vector<int> arr1, arr2;
    int n;
    cin >> n;

    inputArray(arr1, n);
    inputArray(arr2, n);

    cout << '\n'
         << Bai02(arr1, arr2, n);

    return 0;
}