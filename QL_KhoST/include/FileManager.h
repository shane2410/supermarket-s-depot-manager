#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "QuanLyHangHoa.h"
#include "QuanLyNhaCungCap.h"
#include "QuanLyPhieuNhap.h"
#include "QuanLyPhieuXuat.h"
#include "QuanLyNguoiDung.h"
using namespace std;

class FileManager {
private:
    const string hangHoaFile = "hanghoa.csv";
    const string nccFile = "nhacungcap.csv";
    const string phieuNhapFile = "phieunhap.csv";
    const string phieuXuatFile = "phieuxuat.csv";
    const string nguoiDungFile = "nguoidung.csv";

    void docHangHoa(QuanLyHangHoa& qlhh);
    void docNhaCungCap(QuanLyNhaCungCap& qlncc);
    void docPhieuNhap(QuanLyPhieuNhap& qlp);
    void docPhieuXuat(QuanLyPhieuXuat& qlp);
    void docNguoiDung(QuanLyNguoiDung& qlnd);

    void ghiHangHoa(const QuanLyHangHoa& qlhh);
    void ghiNhaCungCap(const QuanLyNhaCungCap& qlncc);
    void ghiPhieuNhap(const QuanLyPhieuNhap& qlpn);
    void ghiPhieuXuat(const QuanLyPhieuXuat& qlpx);
    void ghiNguoiDung(const QuanLyNguoiDung& qlnd);

public:
    void docTatCaDuLieu(QuanLyHangHoa& qlhh, QuanLyNhaCungCap& qlncc, QuanLyPhieuNhap& qlpn, QuanLyNguoiDung& qlnd);

    void ghiTatCaDuLieu(const QuanLyHangHoa& qlhh, const QuanLyNhaCungCap& qlncc, const QuanLyPhieuXuat& qlp, const QuanLyNguoiDung& qlnd);
};

#endif 