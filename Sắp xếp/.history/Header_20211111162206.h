#include <iostream>
#include <vector>
using namespace std;
struct sinhVien
{
    string maSo;
    float diem;
    sinhVien(string Maso, float Diem = 0)
    {
        maSo = Maso;
        diem = Diem;
    }
};
// Hoan doi 2 so nguyen
void swap_int(int &a, int &b);

// Sap xep doi cho truc tiep: Interchange sort
void interchangeSort(vector<int> &arr);

// Sap xep chen: Insertion sort
void insertionSort(vector<int> &arr);

// Sap xep shell: Shell sort
void shellSort(vector<int> &arr);

// Sap xep chon: Selection sort
void selectionSort(vector<int> &arr);

// Sap xep noi bot: Bubble sort
void bubbleSort(vector<int> &arr);

// Sap xep shaker: Shaker sort
void shakerSort(vector<int> &arr);

// In cac phan tu cua mang vector
void printArray(vector<int> arr);

// Hoan doi thong tin 2 sinh vien
void swapSinhVien(sinhVien &a, sinhVien &b);

// In ma so sinh vien theo diem tang dan
void printSinhVienMarksSort(vector<sinhVien> &svArr, int n);
