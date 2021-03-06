#include "Header.h"
using namespace std;

// Hoan doi 2 so nguyen
void swap_int(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// Sap xep doi cho truc tiep: Interchange sort
void interchangeSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap_int(arr[i], arr[j]);
}
// Sap xep chen: Insertion sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int pos = i - 1;
        while (pos >= 0 && x < arr[pos])
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;
    }
}
// Sap xep shell: Shell sort
void shellSort(vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int x = arr[i];
            int j = i - gap;
            while (j >= 0 && x < arr[j])
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = x;
        }
    }
}
// Sap xep chon: Selection sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap_int(arr[i], arr[min_index]);
    }
}
// Sap xep noi bot: Bubble sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (arr[j - 1] > arr[j])
                swap_int(arr[j - 1], arr[j]);
}
// Sap xep shaker: Shaker sort
void shakerSort(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int stop = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
            if (arr[i] > arr[i + 1])
            {
                swap_int(arr[i], arr[i + 1]);
                stop = i;
            }
        right = stop;

        for (int i = right; i > left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap_int(arr[i], arr[i - 1]);
                stop = i;
            }
        }
        left = stop;
    }
}

// In cac phan tu cua mang vector
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

// Hoan doi thong tin 2 sinh vien
void swapSinhVien(sinhVien &a, sinhVien &b)
{
    sinhVien tmp = a;
    a = b;
    b = tmp;
}

// In ma so sinh vien theo diem tang dan
void printSinhVienMarksSort(vector<sinhVien> &svArr, int n)
{
    // Dung sap xep noi bot: Bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (svArr[j - 1].diem > svArr[j].diem)
                swapSinhVien(svArr[j - 1], svArr[j]);
    // In ma so sinh vien
    for (int i = 0; i < n; i++)
        cout << svArr[i].maSo << " ";
}

// In thong tin mang sinh vien
void printSinhVienArray(vector<sinhVien> svArr)
{
    cout << "\nThong tin cac sinh vien:\n";
    cout << svArr.size();
    for (int i = 0; i < svArr.size(); i++)
    {
        cout << "\n"
             << svArr[i].maSo << " " << fixed << setprecision(1) << svArr[i].diem;
    }
}
