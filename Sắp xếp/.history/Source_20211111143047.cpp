#include <iostream>
#include <vector>
using namespace std;

void Swap(int &a, int &b)
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
                Swap(arr[i], arr[j]);
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
void shellSort(vector<int> arr)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
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
        Swap(arr[i], arr[min_index]);
    }
}
// Sap xep noi bot: Bubble sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (arr[j - 1] > arr[j])
                Swap(arr[j - 1], arr[j]);
}
// Sap xep noi bot cai tien: Shaker sort
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
                Swap(arr[i], arr[i + 1]);
                stop = i;
            }
        right = stop;

        for (int i = right; i > left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                Swap(arr[i], arr[i - 1]);
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
int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(9);
    arr.push_back(8);
    //interchangeSort(arr);
    //insertionSort(arr);
    shellSort(arr);
    //selectionSort(arr);
    //bubbleSort(arr);
    //shakerSort(arr);
    printArray(arr);
    return 0;
}