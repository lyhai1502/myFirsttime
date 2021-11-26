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
    //interchangeSort(arr); // Bai 1.1
    //insertionSort(arr);   // Bai 1.2
    //shellSort(arr);       // Bai 1.2 cai tien
    //selectionSort(arr);   // Bai 1.3
    bubbleSort(arr); // Bai 1.4
    //shakerSort(arr);      // Bai 1.4 cai tien
    printArray(arr);
    cout << "\n";

    // Bai 1.5
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