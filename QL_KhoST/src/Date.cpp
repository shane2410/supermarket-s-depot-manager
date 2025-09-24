#include <iostream>
#include "../include/Date.h"
using namespace std;

istream &operator>>(istream &is, Date &d)
{
    cout << "Nhap ngay thang nam (dd/mm/yyyy): ";
    Date temp;
    char slash;
    is >> temp.ngay;
    is >> slash;
    is >> temp.thang;
    is >> slash;
    is >> temp.nam;
    if (slash == '/' && temp.hopLe(temp.ngay, temp.thang, temp.nam))
    {
        d = temp;
    }
    else
    {
        cout << "Ngay thang nam khong hop le. Gan mac dinh 1/1/1900" << endl;
        d.ngay = 1;
        d.thang = 1;
        d.nam = 1900;
    }
    return is;
}
ostream &operator<<(ostream &os, Date d)
{
    os << d.ngay << "/" << d.thang << "/" << d.nam;
    return os;
}
