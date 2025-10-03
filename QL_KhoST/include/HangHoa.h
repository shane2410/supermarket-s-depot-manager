#ifndef HangHoa_h
#define HangHoa_h
#include "Date.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class HangHoa {
  private:
    string maHH, tenHH, donViTinh;
    double giaNhap, giaBan;
    int soLuongTon;
    string maNCC;
    Date ngaySanXuat, hanSuDung;

  public:
    HangHoa();
    HangHoa(string maHH, string tenHH, string donViTinh, double giaNhap,
            double giaBan, int soLuongTon, string maNCC, Date ngaySanXuat,
            Date hanSuDung);
    ~HangHoa();
    // get
    string getMaHH() const;
    string getTenHH() const;
    string getDonViTinh() const;
    string getMaNCC() const;
    double getGiaNhap() const;
    double getGiaBan() const;
    int getSoLuongTon() const;
    Date getNgaySanXuat() const;
    Date getHanSuDung() const;
    // set
    void setMaHH(string maHH);
    void setTenHH(string tenHH);
    void setDonViTinh(string donViTinh);
    void setMaNCC(string maNCC);
    void setGiaNhap(double giaNhap);
    void setGiaBan(double giaBan);
    void setSoLuongTon(int soLuongTon);
    void setNgaySanXuat(Date ngaySanXuat);
    void setHanSuDung(Date hanSuDung);
    //
    void capNhatSoLuong(int soLuong);
    static void printWrappedString(ostream &os, const string &str,
                                   size_t maxwidth, const string &padding);
    friend ostream &operator<<(ostream &os, const HangHoa &hh);
    string getKey() const;
};

#endif
