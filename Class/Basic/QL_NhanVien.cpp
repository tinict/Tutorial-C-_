#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Date
{
	private:
		int d,m,y;
	public:
		Date()
		{
			d = 0;
			m = 0;
			y = 0;
		}
		void Ip_Date();
		int get_D();
		int get_m();
		int get_Y();
		int re_Date();
		int d_D(Date a);
		bool check_leapyear();
};

bool Date::check_leapyear()
{
	if(y % 4 == 0 && y  % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}

int Date::re_Date()  //re_Date(month,year)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	else if(m == 2)
	{
		if(check_leapyear() == 1) return 29;
		else return 28;
	}
}

int Date::d_D(Date a)
{
	int t = 0;
	int f1 = re_Date() - d, f2 = a.re_Date() - a.d;
	int k = a.y - y + 1;
	Date b;
	for(int i = y; i <= a.y; i++)
	{
		if(k != 1)
		{
			if(i == y)
			{
				for(int j = m ; j <= 12; j++)
				{
					b.m = j;
					b.y = i;
					t += b.re_Date();
				}
			}
			else if(i == a.y)
			{
				for(int q = 1; q <= a.m ; q++)
				{
					b.m = q;
					b.y = i;
					t += b.re_Date();
				}
			}
			
			else
			{
				for(int p = 1; p <= 12; p++)
				{
					b.m = p;
					b.y = i;
					t += b.re_Date();
				}
			}
		}
		else
		{
			for(int r = m ; r <= a.m; r++)
			{
				b.m = r;
				b.y = i;
				t += b.re_Date();
			}
		}
	}
	return t - re_Date() + f1 - f2;
}

void Date::Ip_Date()
{
	cout << "Ngay: ";
	cin >> d;
	cout << "Thang: ";
	cin >> m;
	cout << "Nam: ";
	cin >> y;
}

Date::get_D()
{
	return d;
}

Date::get_m()
{
	return m;
}

Date::get_Y()
{
	return y;
}

class NhanVien
{
	private:
		string MaNV;
		string Hoten;
		int Hesoluong;
		int Hesophucap;
		Date NgayvaoCQ;
	public:
		void Ip_NhanVien();
		void Op_NhanVien();
		int get_hsluong();
		string get_Hoten();
		int get_Hesphucap();
		string get_MaNV();
		int Luong();
		int get_Ngay();
		int get_Thang();
		int get_Nam();
		Date get_Date();
};

Date NhanVien::get_Date()
{
	return NgayvaoCQ;
}

int NhanVien::get_Ngay()
{
	return NgayvaoCQ.get_D();
}

int NhanVien::get_Thang()
{
	return NgayvaoCQ.get_m();
}

int NhanVien::get_Nam()
{
	return NgayvaoCQ.get_Y();
}

void NhanVien::Ip_NhanVien()
{
	cout << "Ma Nhan Vien: ";
	getline(cin,MaNV);
	cout << "Ho va Ten: ";
	getline(cin,Hoten);
	cout << "He so luong: ";
	cin >> Hesoluong;
	cout << "He so phu cap: ";
	cin >> Hesophucap;
	cout << "Ngay vao co quan" << endl;
	NgayvaoCQ.Ip_Date();
}

string NhanVien::get_Hoten()
{
	return Hoten;
}

string NhanVien::get_MaNV()
{
	return MaNV;
}

int NhanVien::get_hsluong()
{
	return Hesoluong;
}

int NhanVien::get_Hesphucap()
{
	return Hesophucap;
}

void NhanVien::Op_NhanVien()
{
	cout << MaNV << "\t\t" << Hoten << "\t\t" << Hesoluong << "\t\t" << Hesophucap << "\t\t" << NgayvaoCQ.get_D() << "/" << NgayvaoCQ.get_m() << "/" << NgayvaoCQ.get_Y() << endl;
}

int NhanVien::Luong()
{
	return (Hesoluong + Hesophucap) * 1490000;
}

#define Max 50

class QL_NhanVien
{
	private:
		int sl;
		NhanVien a[Max];
	public:
		QL_NhanVien(int i = 0)
		{
			sl = i; 
		}
		void Ip_QLNhanVien();
		void NhanVien_Max();
		void Sort();
		void Op_QLNhanVien();
};

void QL_NhanVien::Ip_QLNhanVien()
{
	for(int i = 0 ; i < sl; i++)
	{
		cin.ignore();
		a[i].Ip_NhanVien();
	}
}

void QL_NhanVien::NhanVien_Max()
{
	cout << "***********************************************************************" << endl;
	int MAX = 0;
	for(int i = 0; i < sl; i++)
	{
		if(a[i].Luong() > Max)
			MAX = a[i].Luong();
	}
	for(int i = 0; i < sl; i++)
		if(a[i].Luong() == MAX)
			a[i].Op_NhanVien();
}

void QL_NhanVien::Sort()
{
	Date b;
	for(int i = 0 ; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(b.d_D(a[i].get_Date()) < b.d_D(a[j].get_Date()))
			{
				NhanVien t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void QL_NhanVien::Op_QLNhanVien()
{
	cout << "***********************************************************************" << endl;
	for(int i = 0 ; i < sl; i++)
		a[i].Op_NhanVien();
}

int main()
{
	int n;
	cout << "So luong nhan vien: ";
	cin >> n;
	QL_NhanVien a(n);
	a.Ip_QLNhanVien();
	cout << "Danh Sach Nhan Vien" << endl;
	a.Op_QLNhanVien();
	cout << "Nhan vien vao co quan" << endl;
	a.Sort();
	a.Op_QLNhanVien();
	cout << "Nhan Vien co luong lon nhat" << endl;
	a.NhanVien_Max();
	return 0;
}

