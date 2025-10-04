#ifndef QuanLyNhaCungCap_h
#define QuanLyNhaCungCap_h
#include <iostream>
#include "NhaCungCap.h"
#include "LinkedList.h"
using namespace std;
class QuanLyNhaCungCap : public NhaCungCap{
    LinkedList <NhaCungCap>dsnhacungcap;
    public:
        QuanLyNhaCungCap themnhacungcap();
        QuanLyNhaCungCap hienthinhacungcap();
        QuanLyNhaCungCap capnhatnhacungcap();
        QuanLyNhaCungCap timkiemnhacungcap();
        QuanLyNhaCungCap kiemtrancc();
};
#endif
