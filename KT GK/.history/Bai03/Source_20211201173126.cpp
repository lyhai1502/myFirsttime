#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int n;

void inputData(vector<int> arr, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
}
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Bai03(vector<int> arr, int n)
{
    vector<int> sumArri_index;   // Tao mang Ai + i^1.5
    vector<int> minusArrj_index; // Tao mang Aj - canj
    for (int i = 0; i < n; i++)
    {
        sumArri_index.push_back(arr[i] + i + 1);
        minusArrj_index.push_back(arr[i] - i - 1);
    }

    printArray(sumArri_index);
    printArray(minusArrj_index);

    vector<int> countMinusArr;
    for (int i = 0; i < n + 1; i++)
        countMinusArr.push_back(0);
    for (int i = 0; i < n + 1; i++)
        countMinusArr[minusArrj_index[i]]++;

    // printArray(countMinusArr);
}

int main()
{
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
    Bai03(arr, n);
    return 0;
}