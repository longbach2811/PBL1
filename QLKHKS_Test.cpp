#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class Date
{
private:
    int Ngay;
    int Thang;
    int Nam;

public:
    Date();
    Date(int, int, int);
    ~Date();
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
};
Date::Date() : Ngay(0), Thang(0), Nam(0)
{
}

Date::~Date()
{
}

ostream &operator<<(ostream &os, const Date &d)
{
    os << d.Ngay << "/" << d.Thang << "/" << d.Nam;
    return os;
}

istream &operator>>(istream &is, Date &d)
{
	do {
		cout <<"Ngay: ";
		is >> d.Ngay;
	}
	while (d.Ngay > 31);
	do  {
		cout << "Thang: ";
		is >> d.Thang;
	}
	while (d.Thang > 12);
	cout <<"Nam: ";
	is >> d.Nam;
    return is;
}

class KhachHang
{
protected:
    int MaPhong;
    string Name;
    string cmnd;
    int SoNguoi;
    Date NgayNhan;
    Date NgayTra;
    double GiaPhong;
public:
    KhachHang();
    ~KhachHang();
	virtual void nhap();
	virtual void xuat();
    int &GetMaPhong();
    void SetMaPhong(const int &);
    int &GetSoNguoi();
    void setSoNguoi(const int &nguoi);
    double &GetgiaPhong();
    void SetGiaPhong(const double &giaPhong);
};
KhachHang::KhachHang() : MaPhong(0), Name(""), cmnd(""), NgayNhan(Date()), NgayTra(Date())
{
}
KhachHang::~KhachHang() {}

void KhachHang::nhap()
{	
    cout << "Nhap ten khach hang: ";
    cin >> this->Name;
    cout << "Nhap so CMND khach hang: ";
    cin >> this->cmnd;
    cout << "So nguoi: ";
    cin >> this->SoNguoi;
    cout << "Ngay nhan phong: ";
    cin >> this->NgayNhan;
    cout << "Ngay tra phong: ";
    cin >> this->NgayTra;
}
void KhachHang::xuat()
{
    cout << this->MaPhong << "\t\t" << this->Name << "\t\t   " << this->cmnd;
    cout << "\t   " << this->NgayNhan << "\t\t\t" << this->NgayTra << "\t\t" << this->SoNguoi << "\t\t"<<this->GiaPhong << "000"
         << endl;
}

int &KhachHang::GetMaPhong()
{
    return (this->MaPhong);
}

void KhachHang::SetMaPhong(const int &s)
{
    this->MaPhong = s;
}
int &KhachHang::GetSoNguoi()
{
    return this->SoNguoi;
}
void KhachHang::setSoNguoi(const int &nguoi)
{
    this->SoNguoi = nguoi;
}
double &KhachHang::GetgiaPhong()
{
    return this->GiaPhong;
}
void KhachHang::SetGiaPhong(const double &giaPhong)
{
    this->GiaPhong = giaPhong;
}
class PhongThuong : public KhachHang
{
private:
    double DonGiaThuong;

public:
    void nhap();
    void xuat();
};
enum DonGiaThuong
{
    Thuong1 = 500,
    Thuong2 = 550,
    Thuong3 = 600,
    Thuong4 = 650,
    Thuong5 = 700
};
void PhongThuong::nhap()
{
    int k;
    k = this->GetMaPhong();
    if ((k >= 101) && (k <= 115))
    {
        this->DonGiaThuong = Thuong1;
    }
    if ((k >= 201) && (k <= 215))
    {
        this->DonGiaThuong = Thuong2;
    }
    if ((k >= 301) && (k <= 315))
    {
        this->DonGiaThuong = Thuong3;
    }
    if ((k >= 401) && (k <= 415))
    {
        this->DonGiaThuong = Thuong4;
    }
    if ((k >= 501) && (k <= 515))
    {
        this->DonGiaThuong = Thuong5;
    }
    cout << "Nhap ten khach hang: ";
    cin >> this->Name;
    cout << "Nhap so CMND khach hang: ";
    cin >> this->cmnd;
    cout << "So nguoi: ";
    cin >> this->SoNguoi;
    cout << "Ngay nhan phong: ";
    cin >> NgayNhan;
    cout << "Ngay tra phong: ";
    cin >> NgayTra;
    this->SetGiaPhong(this->DonGiaThuong*this->GetSoNguoi());
}
void PhongThuong::xuat()
{
    cout << this->MaPhong << "\t\t" << this->Name << "\t\t" << this->cmnd;
    cout << "\t\t"<< this->NgayNhan << "\t\t" << this->NgayTra << "\t\t" << this->SoNguoi <<"\t\t" <<this->DonGiaThuong << "000"
         << endl;
}
class PhongVip : public KhachHang
{
private:
    double DonGiaVip;
    double PhuThu;

public:
    void nhap();
    void xuat();
};
enum DonGiaVip
{
    VIP1 = 600,
    VIP2 = 650,
    VIP3 = 700,
    VIP4 = 750,
    VIP5 = 800
};
void PhongVip::nhap()
{
    int k;
    k = this->GetMaPhong();
    if ((k >= 116) && (k <= 130))
    {
        this->DonGiaVip = VIP1;
    }
    if ((k >= 216) && (k <= 230))
    {
        this->DonGiaVip = VIP2;
    }
    if ((k >= 316) && (k <= 330))
    {
        this->DonGiaVip = VIP3;
    }
    if ((k >= 416) && (k <= 440))
    {
        this->DonGiaVip = VIP4;
    }
    if ((k >= 516) && (k <= 550))
    {
        this->DonGiaVip = VIP5;
    }
    cout << "Nhap ten khach hang: ";
    cin >> this->Name;
    cout << "Nhap so CMND khach hang: ";
    cin >> this->cmnd;
    cout << "So nguoi: ";
    cin >> this->SoNguoi;
    cout << "Ngay nhan phong: ";
    cin >> NgayNhan;
    cout << "Ngay tra phong: ";
    cin >> NgayTra;
    this->PhuThu = 50;
    this->SetGiaPhong(this->GetSoNguoi() * (this->DonGiaVip + this->PhuThu));
}
void PhongVip::xuat()
{
    cout << this->MaPhong << "\t\t" << this->Name << "\t\t   " << this->cmnd;
    cout << "\t\t" << this->NgayNhan << "\t\t" << this->NgayTra << "\t\t" << this->SoNguoi << "\t\t" << this->DonGiaVip << "000"
         << endl;
}
class QLPhong
{
private:
    static QLPhong *_instance;
    QLPhong();
    KhachHang *DSPhong;
    int SoLuongPhong;

public:
    static QLPhong *instance();
    ~QLPhong();
    void Add(const KhachHang &);
    void Remove(const int &);
    void NhapDSPhong();
    void XuatDSPhong();
    KhachHang &operator[](int &);
};
QLPhong::QLPhong()
{
    this->DSPhong = NULL;
    this->SoLuongPhong = 0;
}

QLPhong::~QLPhong()
{
    delete[] this->DSPhong;
}

void QLPhong::Add(const KhachHang &p)
{
    if (this->SoLuongPhong == 0)
    {
        this->DSPhong = new KhachHang[this->SoLuongPhong + 1];
        this->DSPhong[this->SoLuongPhong] = p;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->SoLuongPhong];
        for (int i = 0; i < this->SoLuongPhong; i++)
        {
            temp[i] = this->DSPhong[i];
        }
        delete[] this->DSPhong;
        this->DSPhong = new KhachHang[this->SoLuongPhong + 1];
        for (int i = 0; i < this->SoLuongPhong; i++)
        {
            this->DSPhong[i] = temp[i];
        }
        this->DSPhong[this->SoLuongPhong] = p;
    }
    this->SoLuongPhong++;
    cout << "=>Da them phong thanh cong." << endl;
}

QLPhong *QLPhong::_instance = NULL;

QLPhong *QLPhong::instance()
{
    if (QLPhong::_instance == NULL)
    {
        QLPhong::_instance = new QLPhong();
    }
    return QLPhong::_instance;
}

KhachHang &QLPhong::operator[](int &i)
{
    return *(this->DSPhong + i);
}
void QLPhong::Remove(const int &input)
{
    int kt = 0;
    for (int i = 0; i < this->SoLuongPhong; i++)
    {
        if (this->DSPhong[i].GetMaPhong() == input)
        {
            for (int j = i; j < this->SoLuongPhong - 1; j++)
            {
                this->DSPhong[j] = this->DSPhong[j + 1];
            }
            kt = 1;
            this->SoLuongPhong--;
            break;
        }
    }
    if (kt == 1)
    {
        cout << "Da xoa thanh cong." << endl;
    }
    else
        cout << "=>Phong can xoa khong ton tai." << endl;
}
void QLPhong::NhapDSPhong()
{	
    int n;
    KhachHang *khachhang;
    cout <<"==============================DANH SACH PHONG:=============================="<<endl;
	cout <<"***********************Phong thuong tang 1 (101-115)************************"<<endl;
	cout <<"************************Phong VIP tang 1 (116-130)**************************"<<endl;
	cout <<"***********************Phong thuong tang 2 (201-215)************************"<<endl;
	cout <<"************************Phong VIP tang 2 (216-230)**************************"<<endl;
	cout <<"***********************Phong thuong tang 3 (301-315)************************"<<endl;
	cout <<"************************Phong VIP tang 3 (316-330)**************************"<<endl;
	cout <<"***********************Phong thuong tang 4 (401-415)************************"<<endl;
	cout <<"************************Phong VIP tang 4 (416-430)**************************"<<endl;
	cout <<"***********************Phong thuong tang 5 (501-515)************************"<<endl;
	cout <<"************************Phong VIP tang 5 (516-530)**************************"<<endl;
	cout <<"============================================================================"<<endl;
	cout <<"============================================================================"<<endl;
    cout << "Nhap ma phong: ";
    cin >> n;
    if ((n >= 101) && (n <= 115) || (n >= 201) && (n <= 215) || (n >= 301) && (n <= 315) || (n >= 401) && (n <= 415) || (n >= 501) && (n <= 515))
    {
        khachhang = new PhongThuong;
        khachhang->SetMaPhong(n);
        khachhang->nhap();
        QLPhong::instance()->Add(*khachhang);
    }
    if ((n >= 116) && (n <= 130) || (n >= 216) && (n <= 230) || (n >= 316) && (n <= 330) || (n >= 416) && (n <= 430) || (n >= 516) && (n <= 530))
    {
        khachhang = new PhongVip;
        khachhang->SetMaPhong(n);
        khachhang->nhap();
        QLPhong::instance()->Add(*khachhang);
    }
}
void QLPhong::XuatDSPhong()
{	
    cout << "=========================================DANH SACH KHACH HANG=================================================" << endl;
    cout << "Phong\t"
         << "\tTen khach hang"
         << "\t\t\tCMND"
         << "\t\tNgay nhan phong"
         << "\t\tNgay tra phong"
         << "\t\tSo nguoi"
         << "\tGia phong\t" << endl;
    int n = this->SoLuongPhong;
    for (int i = 0; i < n; i++)
    {
        this->DSPhong[i].xuat();
        cout << endl;
    }
}
int main()
{
    int chon;
    int c;
    do
    {	
        cout << "==============================================QUAN LY KHACH HANG==============================================" << endl;
        cout << "==================================================Trang chu:==================================================" << endl;
        cout << "==                              1. Them khach hang:                                                         ==" << endl;
        cout << "==                              2. Danh sach khach hang:                                                    ==" << endl;
        cout << "==                              3. Xoa khach hang:                                                          ==" << endl;
        cout << "==                              4. Thoat chuong trinh:                                                      ==" << endl;
        cout << "==============================================================================================================" << endl;
        cout << "==============================================================================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon)
        {
        case 1:{
            QLPhong::instance()->NhapDSPhong();
            cout <<"------------------------------------------------------" <<endl;
            //{
			time_t now = time(0);
   			cout << "Number of sec since 1/1/1970:" << now << endl;
			tm *ltm = localtime(&now);
   			cout << "Year: " << 1900 + ltm->tm_year << endl;
   			cout << "Month: " << 1 + ltm->tm_mon<< endl;
   			cout << "Day: " << ltm->tm_mday << endl;
   			cout << "Time: "<< ltm->tm_hour << ":";
   			cout << 1 + ltm->tm_min << ":";
   			cout << 1 + ltm->tm_sec << endl;
			//} link: https://codelearn.io/sharing/5-phut-tim-hieu-date-va-time-trong-cpp
            break;
        }
        case 2:
            QLPhong::instance()->XuatDSPhong();
            break;
        case 3:
        {
            cout << "Nhap ma phong can xoa: ";
            cin >> c;
            QLPhong::instance()->Remove(c);
            break;
        }
        case 4:
            cout << "Tam biet! ";
            break;
        default:
            cout << "chon sai vui long nhap lai ! ";
            break;
        }
    } while (chon != 4);
    return 0;
}
