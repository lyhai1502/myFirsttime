#include "Source.cpp"
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(7);
    printArray(arr);

    minHeapify(arr); // Xay dung Min Heap hoan chinh
    cout < getMin(arr);
    cout << extractMin(arr) << endl;
    arr.push_back(4);
    printArray(arr);
    cout << extractMin(arr) << endl;
    cout << extractMin(arr) << endl;
    cout << extractMin(arr);
    return 0;
}