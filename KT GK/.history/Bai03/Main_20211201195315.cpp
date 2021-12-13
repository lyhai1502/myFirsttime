#include "Source.cpp"

int main()
{
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
    cout << endl;
    cout << Bai03(arr, n);
    return 0;
}