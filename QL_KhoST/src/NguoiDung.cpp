#include "../include/NguoiDung.h"

NguoiDung::NguoiDung() : tenDangNhap(""), matKhau(""), hoTen(""), vaiTro("") {}
NguoiDung::NguoiDung(const string &tenDN, const string &mk, const string &ten,
                     const string &vt)
    : tenDangNhap(tenDN), matKhau(mk), hoTen(ten), vaiTro(vt) {}
string NguoiDung::getTenDangNhap() const { return tenDangNhap; }
string NguoiDung::getMatKhau() const { return matKhau; }
string NguoiDung::getHoTen() const { return hoTen; }
string NguoiDung::getVaiTro() const { return vaiTro; }
string NguoiDung::getKey() const { return this->tenDangNhap; }