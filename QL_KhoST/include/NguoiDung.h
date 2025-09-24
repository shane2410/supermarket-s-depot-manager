#ifndef NguoiDung_h
#define NguoiDung_h

#include <string>
using namespace std;

class NguoiDung {
  private:
    string tenDangNhap;
    string matKhau;
    string hoTen;
    string vaiTro;

  public:
    NguoiDung();
    NguoiDung(const string &tenDN, const string &mk, const string &ten,
              const string &vt);

    string getTenDangNhap() const;
    string getMatKhau() const;
    string getHoTen() const;
    string getVaiTro() const;

    string getKey() const;
};

#endif