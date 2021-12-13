#include "Source.cpp"
using namespace std;

int main()
{
    vector<int> arr;
    // arr.push_back(3);
    // arr.push_back(5);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(6);
    // arr.push_back(8);
    // arr.push_back(7);

    int n;
    cout << "Nhap cac phan tu vao hang doi uu tien (nhap 0 de dung)";
    int count = 0;
    do
    {
        count++;
        cout << "\nNhap phan tu thu " << count << " : ";
        cin >> n;
        insert(arr, n);
    } while (n != 0);

    cout << "Hang doi uu tien ban dau: ";
    printArray(arr);
    // Bai 1: Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
    cout << "\nNut goc: " << getMin(arr) << endl;

    // Bai 2: Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
    cout << "\nSau khi lay nut goc = " << extractMin(arr) << endl;
    cout << "Hang doi duoc heapify lai: ";
    printArray(arr);

    // Bai 3: Them phan tu moi vao hang doi uu tien, heapify lai nut do
    int newData = -4;
    cout << "\nChen them phan tu = " << newData;
    cout << "\nHang doi sau khi heapify nguoc nut = " << newData << " : ";
    arr.push_back(newData);
    reverseHeapify(arr, arr.size() - 1);
    printArray(arr);

    return 0;
}