#include "Source.cpp"

using namespace std;

int main()
{
    cout << "Nhap ten file can doc: ";
    char *tenFile;
    cin >> tenFile; // data.txt

    thiSinh thisinh = docThongTinThiSinh(tenFile);
    return 0;
}