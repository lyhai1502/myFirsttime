#ifndef __HEADER_H__
#define __HEADER_H__

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

// Khoi tao mot cong ty
CongTy initCongTy();

// Kiem tra bang bam co rong hay ko
bool isCongTy_Empty(CongTy congTy);

// Luy thua lay du
long long modPow(int a, int b);

// Ham bam
long long HashString(const string &tenCongTy);

// Them 1 cong ty vao bang bam co xu ly dung do
void insert(CongTy congTy);

// Tach cac thanh phan tu chuoi duoc doc trong file
CongTy tachChuoi(string str);

// Xay dung bang bam doc tu file
void readHashTable(const char *tenFile);

// Tim kiem phan tu trong bang bam
void search(string tenCongTy);

#endif // __HEADER_H__