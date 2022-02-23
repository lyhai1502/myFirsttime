#include <iostream>
#include <vector>

using namespace std;
void inputData(vector<int> arr, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        // cout << "Nhap so tien ng " << i + 1 << " : ";
        cin >> data;
        arr.push_back(data);
    }
}