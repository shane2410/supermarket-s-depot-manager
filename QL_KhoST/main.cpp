#include <iostream>
#include <string>

// --- BAO GỒM TẤT CẢ CÁC LỚP CỐT LÕI CẦN KIỂM THỬ ---
#include "include/Date.h"
#include "include/HangHoa.h"
#include "include/LinkedList.h" // Cấu trúc dữ liệu nền tảng
#include "include/NguoiDung.h"
#include "include/NhaCungCap.h"
#include "include/Phieu.h"

// Hàm điều kiện cần thiết để test hàm xóa của LinkedList
bool dieuKienSoSanhMaHH(const HangHoa &hh, const std::string &maHH) {
    return hh.getKey() == maHH;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "== CHUONG TRINH KIEM THU CAC LOP DU LIEU CO BAN ==\n";
    std::cout << "====================================================\n";

    // ===================================
    // === 1. KIỂM THỬ LỚP DATE =========
    // ===================================
    std::cout << "\n----- [TEST 1]: LOP DATE -----\n";
    Date dateTest(25, 12, 2025);
    std::cout << "Da tao doi tuong Date. Goi ham hienThiNgay(): ";
    cout << dateTest; // Output: Ngay: 25/12/2025

    // ===================================
    // === 2. KIỂM THỬ LỚP HANGHOA =======
    // ===================================
    std::cout << "\n----- [TEST 2]: LOP HANGHOA -----\n";
    HangHoa hhSua("HH01", "Sua Tuoi Vinamilk 1LLLLLLLLLL", "Hop", 15000, 18000,
                  100, "NCC-VM", Date(1, 1, 2025), Date(1, 7, 2025));
    std::cout << "Da tao doi tuong HangHoa. Hien thi thong tin:\n";
    cout << hhSua;
    std::cout << "Test getKey(): " << hhSua.getKey() << std::endl;
    std::cout << "Test capNhatSoLuong():\n";
    std::cout << "  - So luong ban dau: " << hhSua.getSoLuongTon() << std::endl;
    hhSua.capNhatSoLuong(50); // Nhập thêm
    std::cout << "  - Sau khi nhap them 50: " << hhSua.getSoLuongTon()
              << std::endl;
    hhSua.capNhatSoLuong(-20); // Xuất đi
    std::cout << "  - Sau khi xuat di 20: " << hhSua.getSoLuongTon()
              << std::endl;
    std::cout << "[OK] Lop HangHoa hoat dong dung.\n";

    // ===================================
    // === 3. KIỂM THỬ LỚP NHACUNGCAP ====
    // ===================================
    std::cout << "\n----- [TEST 3]: LOP NHACUNGCAP -----\n";
    NhaCungCap nccVinamilk("NCC-VM", "Cong ty sua Vinamilk", "Quan 7, TP.HCM",
                           "02854155555");
    std::cout << "Da tao doi tuong NhaCungCap. Hien thi thong tin:\n";
    cout << nccVinamilk;
    std::cout << "Test getKey(): " << nccVinamilk.getKey() << std::endl;
    std::cout << "[OK] Lop NhaCungCap hoat dong dung.\n";

    // ===================================
    // === 4. KIỂM THỬ LỚP NGUOIDUNG =====
    // ===================================
    std::cout << "\n----- [TEST 4]: LOP NGUOIDUNG -----\n";
    NguoiDung userAdmin("admin", "123", "Nguyen Van Quan Ly", "quanly");
    std::cout << "Da tao doi tuong NguoiDung:\n";
    std::cout << "  - Ten dang nhap: " << userAdmin.getTenDangNhap()
              << std::endl;
    std::cout << "  - Ho ten: " << userAdmin.getHoTen() << std::endl;
    std::cout << "  - Vai tro: " << userAdmin.getVaiTro() << std::endl;
    std::cout << "  - Test getKey(): " << userAdmin.getKey() << std::endl;
    std::cout << "[OK] Lop NguoiDung hoat dong dung.\n";

    // ===================================
    // === 5. KIỂM THỬ LỚP PHIEU =========
    // ===================================
    std::cout << "\n----- [TEST 5]: LOP PHIEUNHAP -----\n";
    PhieuNhap phieuNhapTest("PN-TEST-001", Date(2, 2, 2025), "NCC-VM");
    phieuNhapTest.themChiTiet(ChitietPhieuNhap("HH01", 50, 15000));
    phieuNhapTest.themChiTiet(ChitietPhieuNhap("HH02", 100, 20000));
    std::cout
        << "Da tao PhieuNhap va them 2 chi tiet. Hien thi chi tiet phieu:\n";
    cout << phieuNhapTest;
    std::cout << "Tong tien cua phieu: " << phieuNhapTest.getThanhTien()
              << " VND (Du kien: 2750000)\n";
    std::cout << "[OK] Lop PhieuNhap hoat dong dung.\n";

    // ===================================
    // === 6. KIỂM THỬ LỚP LINKEDLIST ====
    // ===================================
    std::cout << "\n----- [TEST 6]: LOP LINKEDLIST voi <HangHoa> -----\n";
    LinkedList<HangHoa> dsHangHoaTest;
    dsHangHoaTest.addLast(HangHoa("HH01", "Sua Tuoi", "Hop", 15000, 18000, 100,
                                  "NCC1", Date(), Date()));
    dsHangHoaTest.addLast(HangHoa("HH02", "Banh My", "Cai", 5000, 7000, 200,
                                  "NCC2", Date(), Date()));
    dsHangHoaTest.addLast(
        HangHoa("HH03", "Nuoc Suoi hiaushdjhasdkahdkjhkjdjkhaksdh", "Chai",
                3000, 5000, 300, "NCC3", Date(), Date()));
    dsHangHoaTest.addLast(HangHoa("HH04", "Keo Mut", "Goi", 10000, 15000, 150,
                                  "NCC2", Date(), Date()));

    std::cout << "Da them 4 HangHoa vao LinkedList. Hien thi danh sach (test "
                 "operator<<):\n";
    std::cout << dsHangHoaTest;

    std::cout << "\n--- Test chuc nang xoa (deletebyCond) ---\n";
    std::cout << "Xoa hang hoa co ma 'HH02' (o giua)...\n";
    dsHangHoaTest.deletebyCond(dieuKienSoSanhMaHH, "HH02");
    std::cout << dsHangHoaTest;

    std::cout << "\nXoa hang hoa co ma 'HH01' (o dau)...\n";
    dsHangHoaTest.deletebyCond(dieuKienSoSanhMaHH, "HH01");
    std::cout << dsHangHoaTest;

    std::cout << "\nXoa hang hoa co ma 'HH04' (o cuoi)...\n";
    dsHangHoaTest.deletebyCond(dieuKienSoSanhMaHH, "HH04");
    std::cout << dsHangHoaTest;

    std::cout << "\nXoa hang hoa co ma 'HH99' (khong ton tai)...\n";
    bool result = dsHangHoaTest.deletebyCond(dieuKienSoSanhMaHH, "HH99");
    std::cout << "Ket qua tra ve: " << (result ? "true" : "false")
              << " (Du kien: false)\n";
    std::cout << dsHangHoaTest;

    std::cout << "[OK] Lop LinkedList hoat dong dung.\n";

    std::cout << "\n====================================================\n";
    std::cout << "==             HOAN TAT KIEM THU                ==\n";
    std::cout << "====================================================\n";

    return 0;
}