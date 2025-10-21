#include "../include/QuanLyPhieu.h"
#include "../include/QuanLyHangHoa.h"
#include <iostream>
using namespace std;
bool QuanLyPhieu::taophieunhap(const PhieuNhap& pn, QuanLyHangHoa& qlhh) {
    dsphieunhap.addLast(pn);
    const LinkedList<ChitietPhieuNhap>& dsCTPN = pn.getDsCTPN();
    Node<ChitietPhieuNhap>* current = dsCTPN.getHead();
    while (current != nullptr) {
        string maHH = current->data.maHH;
        int soLuong = current->data.soLuong;
        HangHoa* hh = qlhh.timkiemhanghoa(maHH);
        if (hh == nullptr) {
            cout << "Error: Commodity " << maHH << " not found in inventory." << endl;
            return false;
        }
        hh->capNhatSoLuong(soLuong); 
        current = current->pNext;
    }
    const_cast<PhieuNhap&>(pn).tinhThanhtien();
    return true;
}
void QuanLyPhieu::hienthidsphieunhap() {
    if (dsphieunhap.getSize() == 0) {
        cout << "Danh sach phieu nhap rong." << endl;
        return;
    }
    Node<PhieuNhap>* current = dsphieunhap.getHead();
    while (current != nullptr) {
        cout << current->data;
        current = current->pNext;
    }
}
QuanLyPhieu* QuanLyPhieu::timphieunhap(const string& maPhieu) {
    Node<PhieuNhap>* current = dsphieunhap.getHead();
    while (current != nullptr) {
        if (current->data.PhieuNhap::getKey() == maPhieu) {
            return this;
        }
        current = current->pNext;
    }
    return nullptr;
}
QuanLyPhieu QuanLyPhieu::taophieuxuat(QuanLyHangHoa& qlhh) {
    string maPhieuXuat, tenKH;
    Date ngayXuat;
    cout << "Nhap ma phieu xuat: ";
    cin >> maPhieuXuat;
    cout << "Nhap ten khach hang: ";
    cin.ignore();
    getline(cin, tenKH);
    cout << "Nhap ngay xuat (dd mm yyyy): ";
    int day, month, year;
    cin >> day >> month >> year;
    ngayXuat = Date(day, month, year);

    PhieuXuat px(maPhieuXuat, ngayXuat, tenKH);
    char continueAdding;
    do {
        string maHH;
        int soLuong;
        double donGiaBan;
        cout << "Nhap ma hang hoa: ";
        cin >> maHH;
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia ban: ";
        cin >> donGiaBan;
        HangHoa* hh = qlhh.timkiemhanghoa(maHH);
        if (hh == nullptr) {
            cout << "Error: Commodity " << maHH << " not found." << endl;
            continue;
        }
        if (hh->getSoLuongTon() < soLuong) {
            cout << "Error: Insufficient stock for " << maHH << ". Available: "
                 << hh->getSoLuongTon() << endl;
            continue;
        }
        ChitietPhieuXuat ctpx(maHH, soLuong, donGiaBan);
        px.themChiTiet(ctpx);
        hh->capNhatSoLuong(-soLuong);

        cout << "Tiep tuc them chi tiet? (y/n): ";
        cin >> continueAdding;
    } while (continueAdding == 'y' || continueAdding == 'Y');
    px.tinhThanhtien();
    dsphieuxuat.addLast(px);
    return *this;
}
void QuanLyPhieu::hienthidsphieuxuat() {
    if (dsphieuxuat.getSize() == 0) {
        cout << "Danh sach phieu xuat rong." << endl;
        return;
    }
    Node<PhieuXuat>* current = dsphieuxuat.getHead();
    while (current != nullptr) {
        cout << current->data;
        current = current->pNext;
    }
}
void QuanLyPhieu::timphieuxuat() {
    string maPhieu;
    cout << "Nhap ma phieu xuat can tim: ";
    cin >> maPhieu;
    Node<PhieuXuat>* current = dsphieuxuat.getHead();
    while (current != nullptr) {
        if (current->data.PhieuXuat::getKey() == maPhieu) {
            cout << current->data;
            return;
        }
        current = current->pNext;
    }
    cout << "Khong tim thay phieu xuat voi ma: " << maPhieu << endl;
}

