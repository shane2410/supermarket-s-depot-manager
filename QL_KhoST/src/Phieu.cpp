#include "../include/Phieu.h"

PhieuNhap::PhieuNhap() : thanhTien(0) {}
PhieuNhap::PhieuNhap(const string &maPhieu, const Date &ngay,
                     const string &maNCC)
    : maPhieuNhap(maPhieuNhap), ngayNhap(ngay), maNCC(maNCC), thanhTien(0) {}
string PhieuNhap::getMaNCC() const { return maNCC; }
Date PhieuNhap::getNgayNhap() const { return ngayNhap; }
string PhieuNhap::getMaPhieuNhap() const { return maPhieuNhap; }
double PhieuNhap::getThanhTien() const { return thanhTien; }
void PhieuNhap::setMaPhieuNhap(const string &mapn) { this->maPhieuNhap = mapn; }
void PhieuNhap::setMaNCC(const string &mancc) { this->maNCC = mancc; }
void PhieuNhap::setNgayNhap(const Date &ngay) { this->ngayNhap = ngay; }
string PhieuNhap::getKey() const { return this->maPhieuNhap; }

PhieuXuat::PhieuXuat() : thanhTien(0) {}
PhieuXuat::PhieuXuat(const string &maPhieu, const Date &ngay,
                     const string &TenKH)
    : maPhieuXuat(maPhieuXuat), ngayXuat(ngay), TenKH(TenKH), thanhTien(0) {}

string PhieuXuat::getMaPhieuXuatI() { return this->maPhieuXuat; }
Date PhieuXuat::getNgayXuat() { return this->ngayXuat; }
string PhieuXuat::getTenKH() { return this->TenKH; }
double PhieuXuat::getThanhTien() const { return thanhTien; }
void PhieuXuat::setMaPhieuXuat(const string &mapx) { this->maPhieuXuat = mapx; }
void PhieuXuat::setTenKH(const string &ten) { this->TenKH = ten; }
void PhieuXuat::setNgayXuat(const Date &ngay) { this->ngayXuat = ngay; }
string PhieuXuat::getKey() const { return this->maPhieuXuat; }
void PhieuNhap::tinhThanhtien() const {
    double thanhTien = 0.0;
    Node<ChitietPhieuNhap> *current = dsCTPN.getHead();
    while (current != nullptr) {
        thanhTien += current->data.soLuong * current->data.donGiaNhap;
        current = current->pNext;
    }
}
void PhieuXuat::tinhThanhtien() const {
    double thanhTien = 0.0;
    Node<ChitietPhieuXuat> *current = dsCTPX.getHead();
    while (current != nullptr) {
        thanhTien += current->data.soLuong * current->data.donGiaBan;
        current = current->pNext;
    }
}

const LinkedList<ChitietPhieuNhap> &PhieuNhap::getDsCTPN() const {
    return dsCTPN;
}

const LinkedList<ChitietPhieuXuat> &PhieuXuat::getDsCTPX() const {
    return dsCTPX;
}

void PhieuNhap::themChiTiet(const ChitietPhieuNhap &ctpn) {
    dsCTPN.addLast(ctpn);
}
void PhieuXuat::themChiTiet(const ChitietPhieuXuat &ctpx) {
    dsCTPX.addLast(ctpx);
}
ostream &operator<<(ostream &os, const PhieuNhap pn) {
    os << "Chi tiết phiếu nhập: " << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << left << setw(20) << "Mã phiếu nhập: " << pn.maPhieuNhap << endl;
    os << left << setw(20) << "Ngày nhập: " << pn.ngayNhap << endl;
    os << left << setw(20) << "Mã nhà cung cấp: " << pn.maNCC << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << "| " << left << setw(15) << "Mã HH"
       << "| " << setw(10) << "Số lượng"
       << "| " << setw(18) << "Đơn giá nhập"
       << "| " << setw(18) << "Thành tiền" << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    Node<ChitietPhieuNhap> *current = pn.dsCTPN.getHead();
    while (current != nullptr) {
        double thanhTien = current->data.soLuong * current->data.donGiaNhap;
        os << "| " << left << setw(15) << current->data.maHH << "| " << right
           << setw(10) << current->data.soLuong << "| " << setw(18) << fixed
           << setprecision(0) << current->data.donGiaNhap << "| " << setw(18)
           << fixed << setprecision(0) << thanhTien << endl;
        current = current->pNext;
    }
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << right << setw(55) << "Tổng thành tiền: " << fixed << setprecision(0)
       << pn.thanhTien << " VND" << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    return os;
}

ostream &operator<<(ostream &os, const PhieuXuat px) {
    os << "Chi tiết phiếu xuất: " << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << left << setw(20) << "Mã phiếu xuất: " << px.maPhieuXuat << endl;
    os << left << setw(20) << "Ngày xuất: " << px.ngayXuat << endl;
    os << left << setw(20) << "Tên khách hàng: " << px.TenKH << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << "| " << left << setw(15) << "Mã HH"
       << "| " << setw(10) << "Số lượng"
       << "| " << setw(18) << "Đơn giá bán"
       << "| " << setw(18) << "Thành tiền" << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    Node<ChitietPhieuXuat> *current = px.dsCTPX.getHead();
    while (current != nullptr) {
        double thanhTien = current->data.soLuong * current->data.donGiaBan;
        os << "| " << left << setw(15) << current->data.maHH << "| " << right
           << setw(10) << current->data.soLuong << "| " << setw(18) << fixed
           << setprecision(0) << current->data.donGiaBan << "| " << setw(18)
           << fixed << setprecision(0) << thanhTien << endl;
        current = current->pNext;
    }
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    os << right << setw(55) << "Tổng thành tiền: " << fixed << setprecision(0)
       << px.thanhTien << " VND" << endl;
    os << "--------------------------------------------------------------------"
          "----"
       << endl;
    return os;
}