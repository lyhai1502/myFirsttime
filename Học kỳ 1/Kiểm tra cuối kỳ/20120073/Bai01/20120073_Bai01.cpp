#include <iostream>
#include <vector>

using namespace std;

// Tra ve phan tu lon nhat cua mang
int getMax(vector<int> arr)
{
    int n = arr.size();
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
// Xay dung maxHeap
void minHeapify(vector<int> &arr, int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[large])
        large = left;
    if (right < n && arr[right] < arr[large])
        large = right;
    if (large != i)
    {
        swap(arr[i], arr[large]);
        minHeapify(arr, n, large);
    }
}
// Sap xep vun dong: Heap sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
long long function1(vector<int> arr1, int n1, vector<int> arr2, int n2)
{
    heapSort(arr1);
    long long sum = 0;
    int index = n1 - 1;
    for (int i = 0; i < n2; i++)
    {
        if (arr2[i] == 1)
            sum += arr1[index--];
        else if (arr2[i] == 2)
        {
            sum += arr1[index - 1];
            arr1[index - 1] = arr1[index];
            index--;
        }
    }
    return sum;
}
int main()
{
    // Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     freopen("./output1.txt", "w", stdout);
    // }
    // freopen_s("input.txt", "r", stdin);
    vector<int> arr1;
    vector<int> arr2;

    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    cout << function1(arr1, n1, arr2, n2);

    // Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    // cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";

    return 0;
}