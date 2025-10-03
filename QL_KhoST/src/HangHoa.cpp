#include "../include/HangHoa.h"

HangHoa::HangHoa() {
    this->maHH = "";
    this->tenHH = "";
    this->donViTinh = "";
    this->giaNhap = 0.0;
    this->giaBan = 0.0;
    this->soLuongTon = 0;
    this->maNCC = "";
}
HangHoa::~HangHoa() {}
string HangHoa::getMaHH() const { return this->maHH; }
string HangHoa::getTenHH() const { return this->tenHH; }
string HangHoa::getDonViTinh() const { return this->donViTinh; }
string HangHoa::getMaNCC() const { return this->maNCC; }
double HangHoa::getGiaNhap() const { return this->giaNhap; }
double HangHoa::getGiaBan() const { return this->giaBan; }
int HangHoa::getSoLuongTon() const { return this->soLuongTon; }
Date HangHoa::getNgaySanXuat() const { return this->ngaySanXuat; }
Date HangHoa::getHanSuDung() const { return this->hanSuDung; }
// set
void HangHoa::setMaHH(string maHH) { this->maHH = maHH; }
void HangHoa::setTenHH(string tenHH) { this->tenHH = tenHH; }
void HangHoa::setDonViTinh(string donViTinh) { this->donViTinh = donViTinh; }
void HangHoa::setMaNCC(string maNCC) { this->maNCC = maNCC; }
void HangHoa::setGiaNhap(double giaNhap) { this->giaNhap = giaNhap; }
void HangHoa::setGiaBan(double giaBan) { this->giaBan = giaBan; }
void HangHoa::setSoLuongTon(int soLuongTon) { this->soLuongTon = soLuongTon; }
void HangHoa::setNgaySanXuat(Date ngaySanXuat) {
    this->ngaySanXuat = ngaySanXuat;
}
void HangHoa::setHanSuDung(Date hanSuDung) { this->hanSuDung = hanSuDung; }
HangHoa::HangHoa(string maHH, string tenHH, string donViTinh, double giaNhap,
                 double giaBan, int soLuongTon, string maNCC, Date ngaySanXuat,
                 Date hanSuDung) {
    this->maHH = maHH;
    this->tenHH = tenHH;
    this->donViTinh = donViTinh;
    this->giaNhap = giaNhap;
    this->giaBan = giaBan;
    this->soLuongTon = soLuongTon;
    this->maNCC = maNCC;
    this->ngaySanXuat = ngaySanXuat;
    this->hanSuDung = hanSuDung;
}
//

void HangHoa::capNhatSoLuong(int soLuongThayDoi) {
    int soLuongMoi = this->soLuongTon + soLuongThayDoi;
    if (soLuongMoi < 0) {
        cout << "Lỗi: Số lượng mới không hợp lệ. " << endl;
        this->soLuongTon = 0;
    } else {
        this->soLuongTon = soLuongMoi;
    }
}

void HangHoa::printWrappedString(ostream &os, const string &str,
                                 size_t maxwidth, const string &padding) {
    stringstream textStream(str);
    string word, firstline;
    bool isFirstWord = true;

    while (textStream >> word) {
        if (firstline.length() + word.length() + 1 <= maxwidth) {
            if (!isFirstWord) {
                firstline += " ";
            }
            firstline += word;
            isFirstWord = false;
        } else {
            if (isFirstWord) {
                firstline = word;
                word = "";
            }
            break;
        }
    }
    os << left << setw(maxwidth) << firstline;
    string subsquentLine;
    isFirstWord = true;

    if (!word.empty()) {
        subsquentLine = word;
        isFirstWord = false;
    }
    while (textStream >> word) {

        if (subsquentLine.length() + word.length() + 1 <= maxwidth) {
            if (!isFirstWord) {
                subsquentLine += " ";
            }
            subsquentLine += word;
            isFirstWord = false;
        } else {
            os << endl << padding << setw(maxwidth) << subsquentLine;
            subsquentLine = word;
            isFirstWord = false;
        }
    }
    if (!subsquentLine.empty()) {
        os << endl << padding << setw(maxwidth) << subsquentLine;
    }
}

ostream &operator<<(ostream &os, const HangHoa &hh) {
    //  maHH, tenHH, donViTinh, giaNhap, giaBan, soLuongTon, maNCC, ngaySanXuat,
    //  hanSuDung
    int getw[] = {8, 20, 8, 12, 12, 8, 12, 9, 9};
    os << left << "| " << setw(getw[0]) << hh.getMaHH() << " | "
       << setw(getw[1]) << hh.getTenHH() << " | " << setw(getw[2])
       << hh.getDonViTinh() << " | " << setw(getw[3]) << hh.getGiaNhap()
       << " | " << setw(getw[4]) << hh.getGiaBan() << " | " << setw(getw[5])
       << hh.getSoLuongTon() << " | " << setw(getw[6]) << hh.getMaNCC() << " | "
       << right << setw(getw[7]) << hh.getNgaySanXuat() << " | "
       << setw(getw[8]) << hh.getHanSuDung() << " |" << endl;
    return os;
}

string HangHoa::getKey() const { return this->maHH; }