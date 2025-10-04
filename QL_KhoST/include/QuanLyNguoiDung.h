#ifndef QuanLyNguoiDung_h
#define QuanLyNguoiDung_h
#include <iostream>
#include "NguoiDung.h"
#include "LinkedList.h"
using namespace std;
class QuanLyNguoiDung : public NguoiDung{
    LinkedList<NguoiDung>dsnguoidung;
    public:
        NguoiDung* nguoidunghientai;
        NguoiDung dangnhap();
        NguoiDung dangxuat();
        NguoiDung thongtinnguoidung();
};
#endif
