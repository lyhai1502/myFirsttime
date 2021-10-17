#include "Source.cpp"

using namespace std;

int main()
{
    cout << "Nhap ten file can doc: ";
    char *tenFile;
    cin >> tenFile; // data.txt

    vector<thiSinh> list = docDanhSachThiSinh(tenFile);

    //dao nguoc ten
    return 0;
}