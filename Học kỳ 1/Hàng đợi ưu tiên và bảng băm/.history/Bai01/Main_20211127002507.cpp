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

    minHeapify(arr); // Xay dung Min Heap hoan chinh
    cout << "Hang doi uu tien ban dau: ";
    printArray(arr);
    // Bai 1: Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
    cout << "\nNut goc: " << getMin(arr) << endl;

    // Bai 2: Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
    cout << "\nSau khi lay nut goc = " << extractMin(arr) << endl;
    cout << "Hang doi duoc heapify lai: ";
    printArray(arr);

    // arr.push_back(4);
    // printArray(arr);
    // cout << extractMin(arr) << endl;
    // cout << extractMin(arr) << endl;
    // cout << extractMin(arr);
    return 0;
}