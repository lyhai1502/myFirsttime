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
    cout << "Nhap cac phan tu vao hang doi uu tien (nhap 0 de dung)\n";
    int count = 0;
    do
    {
        count++;
        cout << "Nhap phan tu thu " << count << " : ";
        cin >> n;
        if (n == 0)
            break;
        insert(arr, n); // Bai 3: Chen them phan tu moi va heapify nguoc phan tu do
    } while (n != 0);

    cout << "\nHang doi uu tien ban dau: ";
    printArray(arr);

    // Bai 1: Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
    cout << "\nNut goc = " << getMin(arr) << endl;

    // Bai 2: Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
    cout << "\nSau khi lay nut goc = " << extractMin(arr) << " ra khoi hang doi" << endl;
    cout << "Hang doi duoc heapify lai: ";
    printArray(arr);

    return 0;
}