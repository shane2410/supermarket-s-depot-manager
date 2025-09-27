#ifndef NhaCungcap_h
#define NhaCungcap_h
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class NhaCungCap {
  private:
    string maNCC;
    string tenNCC;
    string diaChi;
    string soDienThoai;

  public:
    NhaCungCap();
    NhaCungCap(string maNCC, string tenNCC, string diaChi, string soDienThoai);
    ~NhaCungCap();
    // get
    string getMaNCC() const;
    string getTenNCC() const;
    string getDiaChi() const;
    string getSoDienThoai() const;
    // set
    void setMaNCC(const string &maNCC);
    void setTenNCC(const string &tenNCC);
    void setDiaChi(const string &diaChi);
    void setSoDienThoai(const string &soDienThoai);
    string getKey() const;

    friend ostream &operator<<(ostream &os, const NhaCungCap &ncc);
};

#endif