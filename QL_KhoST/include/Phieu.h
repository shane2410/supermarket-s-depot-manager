#ifndef phieu_h
#define phieu_h
#include "Date.h"
#include "LinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct ChitietPhieuNhap {
    string maHH;
    int soLuong;
    double donGiaNhap;
    ChitietPhieuNhap(string ma = "", int sl = 0, double gia = 0)
        : maHH(ma), soLuong(sl), donGiaNhap(gia) {}
};

struct ChitietPhieuXuat {
    string maHH;
    int soLuong;
    double donGiaBan;
    ChitietPhieuXuat(string ma = "", int sl = 0, double gia = 0)
        : maHH(ma), soLuong(sl), donGiaBan(gia) {}
};

class PhieuNhap {
  private:
    string maPhieuNhap;
    Date ngayNhap;
    string maNCC;
    LinkedList<ChitietPhieuNhap> dsCTPN;
    double thanhTien;

  public:
    PhieuNhap();
    ~PhieuNhap();
    PhieuNhap(const string &maPhieuNhap, const Date &ngayNhap,
              const string &maNCC);
    string getMaPhieuNhap() const;
    Date getNgayNhap() const;
    string getMaNCC() const;
    double getThanhTien() const;
    void setMaPhieuNhap(const string &mapn);
    void setNgayNhap(const Date &ngay);
    void setMaNCC(const string &mancc);
    const LinkedList<ChitietPhieuNhap> &getDsCTPN() const;
    void tinhThanhtien() const;
    friend ostream &operator<<(ostream &os, const PhieuNhap pn);
    string getKey() const;
    void themChiTiet(const ChitietPhieuNhap &ctpn);
};

class PhieuXuat {
  private:
    string maPhieuXuat;
    Date ngayXuat;
    string TenKH;
    LinkedList<ChitietPhieuXuat> dsCTPX;
    double thanhTien;

  public:
    PhieuXuat();
    ~PhieuXuat();
    PhieuXuat(const string &maPhieuXuat, const Date &ngayXuat,
              const string &TenKH);
    string getMaPhieuXuatI();
    Date getNgayXuat();
    string getTenKH();
    double getThanhTien() const;
    void setMaPhieuXuat(const string &mapx);
    void setNgayXuat(const Date &ngay);
    void setTenKH(const string &ten);
    const LinkedList<ChitietPhieuXuat> &getDsCTPX() const;
    void tinhThanhtien() const;
    friend ostream &operator<<(ostream &os, const PhieuXuat px);
    string getKey() const;
    void themChiTiet(const ChitietPhieuXuat &ctpx);
};

#endif