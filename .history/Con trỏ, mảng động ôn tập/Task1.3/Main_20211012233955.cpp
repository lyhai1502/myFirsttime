#include "Source.cpp"

using namespace std;

int main()
{
    cout << "Nhap ten file can doc: ";
    char *tenFile_doc;
    cin >> tenFile_doc; // data.txt

    vector<thiSinh> list = docDanhSachThiSinh(tenFile_doc);

    //dao nguoc ten
    daoNguocTenThiSinh(list);
    //viet hoa cac chu cai dau cua ten
    vietHoaTenThiSinh(list);
    //hoan doi ten
    doiTenThiSinh(list, "BD1200015", "BD1200016");
    //tinh diem thi
    tinhDiem(list);
    //xuat File
    cout << "Nhap ten file can ghi: ";
    char *tenFile_ghi;
    cin >> tenFile_ghi; // tongketdiemthi.txt
    xuatFile(list, tenFile_ghi);
    return 0;
}