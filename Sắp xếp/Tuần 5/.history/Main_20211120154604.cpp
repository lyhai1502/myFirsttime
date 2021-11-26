#include "Source.cpp"
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(6);
    //heapSort(arr);
    //mergeSort(arr, 0, arr.size() - 1);
    //quickSort(arr, 0, arr.size() - 1);
    int n = 3;
    int c[n]{0};
    for (int i = 0; i < 3; i++)
        cout << c[i] << endl;
    printArray(arr);
    return 0;
}