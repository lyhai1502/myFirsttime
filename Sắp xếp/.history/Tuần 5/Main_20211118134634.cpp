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
    heapSort(arr);
    printArray(arr);
    return 0;
}