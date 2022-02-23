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
    arr.push_back(607);
    //heapSort(arr);
    //mergeSort(arr, 0, arr.size() - 1);
    //quickSort(arr, 0, arr.size() - 1);
    //countingSort(arr);
    countingSort1(arr, arr.size(), 1);
    //radixSort(arr);
    printArray(arr);
    return 0;
}