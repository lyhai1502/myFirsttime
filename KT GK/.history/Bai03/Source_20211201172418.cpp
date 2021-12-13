#include <iostream>
#include <vector>

using namespace std;

void inputData(vector<int> arr, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
}
void Bai03(vector<int> arr, int n)
{
    vector<int> sumArri_index;   // Tao mang Ai + i^1.5
    vector<int> minusArrj_index; // Tao mang Aj - canj
    for (int i = 0; i < n; i++)
    {
        sumArri_index.push_back(arr[i] + i);
        minusArrj_index.push_back(arr[i] - i);
    }

    int countMinusArr[n];
    for (int i = 0; i < n; i++)
        countMinusArr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        countMinusArr[minusArrj_index[i]]++;
    }
}