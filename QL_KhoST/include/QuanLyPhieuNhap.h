#ifndef QuanLyPhieu_h
#define QuanLyPhieu_h
#include "Phieu.h"
#include "LinkedList.h"
#include "QuanLyHangHoa.h"
#include "Date.h"
using namespace std;
class QuanLyPhieu : public PhieuXuat , public PhieuNhap{
  LinkedList <PhieuNhap> dsphieunhap;
  LinkedList <PhieuXuat> dsphieuxuat;
  public :
    void taophieunhap();
    void hienthidsphieunhap();
    QuanLyPhieu timphieunhap();
    QuanLyPhieu taophieuxuat(QuanLyHangHoa &qlhh);
    void hienthidsphieuxuat();
    void timphieuxuat();
    void thongkedoanhthu(Date tungay, Date denngay);
};
#endif
