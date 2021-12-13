#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct CongTy
{
    string tenCongTy;
    string maSoThue;
    string diaChi;
};

int charCount = 18;
int p = 31;
int m = 100019;
CongTy *hashTable = new CongTy[m];