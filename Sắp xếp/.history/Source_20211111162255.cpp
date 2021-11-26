#include <iostream>
#include <vector>
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

// Hoan doi thong tin 2 sinh vien
void swapSinhVien(sinhVien &a, sinhVien &b)
{
    sinhVien tmp = a;
    a = b;
    b = tmp;
}

// In cac phan tu cua mang vector
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
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
    interchangeSort(arr);
    //insertionSort(arr);
    //shellSort(arr);
    //selectionSort(arr);
    //bubbleSort(arr);
    //shakerSort(arr);
    printArray(arr);

    vector<sinhVien> svArray;
    int n = 5; // So luong sinh vien
    svArray.push_back(sinhVien("1512341", 10));
    svArray.push_back(sinhVien("1613234", 9.0));
    svArray.push_back(sinhVien("1514920", 9.0));
    svArray.push_back(sinhVien("1712000", 7.0));
    svArray.push_back(sinhVien("1812000", 4.0));
    cout << "\nMa so sinh vien duoc sap xep theo diem tang dan: ";
    printSinhVienMarksSort(svArray, n);
    return 0;
}