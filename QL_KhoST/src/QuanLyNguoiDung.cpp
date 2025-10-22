#include "../include/QuanLyNguoiDung.h"
#include <iostream>
#include "../include/NguoiDung.h"
#include <fstream>
#include <sstream>
using namespace std;
NguoiDung QuanLyNguoiDung::dangnhap(const string tk, const string mk){
    if(tk == getTenDangNhap() && mk == getMatKhau()){
        cout << "dangnhap tc";
    }
}
void QuanLyNguoiDung::dangxuat() {
    if (nguoidunghientai.getTenDangNhap().empty()) {
        cout << "Chua co ai dang nhap!\n";
    } else {
        cout << "Dang xuat thanh cong: " << getTenDangNhap() << endl;
        NguoiDung n;
       nguoidunghientai = NguoiDung(); 
    }
}
