#include <iostream>
#include <cstring>
#include "../include/HangHoa.h"
#include "../include/QuanLyHangHoa.h"
#include "../include/Date.h"
#include "../include/LinkedList.h"
using namespace std;
void themhanghoa(LinkedList <HangHoa> &dshh,string maHH, string tenHH, string donViTinh, string soLuongTon,string maNCC,Date hansd,Date ngaysx,double gianhap,double giaban,int slt){
    HangHoa hh;
    hh.setMaHH(maHH);
    hh.setTenHH(tenHH);
    hh.setNgaySanXuat(ngaysx);
    hh.setMaNCC(maNCC);
    hh.setGiaNhap(gianhap);
    hh.setGiaBan(giaban);
    hh.setDonViTinh(donViTinh);
    hh.setHanSuDung(hansd);
    hh.setSoLuongTon(slt);
}
bool matchMaHH(const HangHoa& hh, const string& key) {
    return hh.maHH == key;
}
void hienthidanhsach(LinkedList <HangHoa> &ht){
    cout << ht;
}
bool capnhathanghoa(){
    
}
bool xoahanghoa(const string& key, LinkedList<HangHoa>& ds) {
    return ds.deletebyCond(matchMaHH, key);
}

HangHoa* timkiemhanghoa(LinkedList <HangHoa> &ds, const string &tenhh){
    Node <HangHoa> *p = ds.getHead();
    while(p != nullptr){
        if(p->data.getTenHH() == tenhh){
            return &(p->data);
        }
        p=p->pNext;
    }   
}
