#include "Source.cpp"
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(9);
    arr.push_back(8);
    printArray(arr);
    cout << "\nSau khi sap xep tang dan: ";
    //interchangeSort(arr);
    //insertionSort(arr);
    //shellSort(arr);
    //selectionSort(arr);
    bubbleSort(arr);
    //shakerSort(arr);
    printArray(arr);
    cout << "\n";

    vector<sinhVien> svArray;
    int n = 5; // So luong sinh vien
    svArray.push_back(sinhVien("1512341", 10));
    svArray.push_back(sinhVien("1613234", 9.0));
    svArray.push_back(sinhVien("1514920", 9.0));
    svArray.push_back(sinhVien("1712000", 7.0));
    svArray.push_back(sinhVien("1812000", 4.0));
    printSinhVienArray(svArray);
    cout << "\nMa so sinh vien duoc sap xep theo diem tang dan: ";
    printSinhVienMarksSort(svArray, n);
    return 0;
}