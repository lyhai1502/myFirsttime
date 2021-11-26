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
    arr.push_back(10);
    //heapSort(arr);
    //mergeSort(arr, 0, arr.size() - 1);
    //quickSort(arr, 0, arr.size() - 1);
    // if (getMax(arr) < 10)
    //     countingSort(arr, 1);
    // else
    //     radixSort(arr);
    printArray(arr);
    return 0;
}