#include "Source.cpp"

using namespace std;

int main()
{
    cout << "Nhap ten file can doc: ";
    char *tenFile;
    cin >> tenFile; // data.txt

    vector<thiSinh> list = docDanhSachThiSinh(tenFile);

    //dao nguoc ten
    daoNguocTenThiSinh(list);
    //viet hoa cac chu cai dau cua ten
    vietHoaTenThiSinh(list);
    //hoan doi ten
    doiTenThiSinh(list);
    //tinh diem thi
    tinhDiem(list);
    return 0;
}