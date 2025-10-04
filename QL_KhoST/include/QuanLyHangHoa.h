#ifndef quanlyhanghoa_h
#define quanlyhanghoa_h
#include <iostream>
#include "HangHoa.h"
#include "LinkedList.h"
class QuanLyHangHoa : public HangHoa{
    private: 
        LinkedList<HangHoa>dshanghoa;
    public:
        void themhanghoa();
        void hienthidanhsach();
        bool capnhathanghoa();
        bool xoahanghoa();
        void timkiemhanghoa();
        QuanLyHangHoa layhanghoatheoma();
        void baocaotonkho();
        void baocaosaphethang();
};
#endif
