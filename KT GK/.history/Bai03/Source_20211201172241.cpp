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
        sumArri_index[i] = arr[i] + i;
        minusArrj_index[i] = arr[i] - i;
    }

    vector<int> countMinusArr;
    for (int i = 0; i < n; i++)
    {
    }
}