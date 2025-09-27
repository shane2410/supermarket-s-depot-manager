#include "../include/NhaCungCap.h"

NhaCungCap::NhaCungCap() {
    this->maNCC = "";
    this->tenNCC = "";
    this->diaChi = "";
    this->soDienThoai = "";
}
NhaCungCap::NhaCungCap(string maNCC, string tenNCC, string diaChi,
                       string soDienThoai) {
    this->maNCC = maNCC;
    this->tenNCC = tenNCC;
    this->diaChi = diaChi;
    this->soDienThoai = soDienThoai;
}
NhaCungCap::~NhaCungCap() {}

string NhaCungCap::getMaNCC() const { return this->maNCC; }
string NhaCungCap::getTenNCC() const { return this->tenNCC; }
string NhaCungCap::getDiaChi() const { return this->diaChi; }
string NhaCungCap::getSoDienThoai() const { return this->soDienThoai; }

void NhaCungCap::setMaNCC(const string &mancc) { this->maNCC = mancc; }
void NhaCungCap::setTenNCC(const string &ten) { this->tenNCC = ten; }
void NhaCungCap::setDiaChi(const string &dc) { this->diaChi = dc; }
void NhaCungCap::setSoDienThoai(const string &sdt) { this->soDienThoai = sdt; }
string NhaCungCap::getKey() const { return this->maNCC; }

ostream &operator<<(ostream &os, const NhaCungCap &ncc) {
    os << left << setw(20) << "Mã NCC: " << ncc.maNCC << endl;
    os << left << setw(20) << "Tên NCC: " << ncc.tenNCC << endl;
    os << left << setw(20) << "Địa chỉ: " << ncc.diaChi << endl;
    os << left << setw(20) << "Số điện thoại: " << ncc.soDienThoai << endl;
    return os;
}