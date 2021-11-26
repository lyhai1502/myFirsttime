#include <iostream>
#include <vector>
using namespace std;

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// Sap xep doi cho truc tiep: interchange sort
void interchangeSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                Swap(arr[i], arr[j]);
}
// In cac phan tu cua mang vector
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(9);
    arr.push_back(8);
    interchangeSort(arr);
    printArray(arr);
    return 0;
}