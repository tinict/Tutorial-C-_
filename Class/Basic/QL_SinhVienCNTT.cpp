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
		int get_M();
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

int Date::get_D()
{
	return d;
}

int Date::get_M()
{
	return m;
}

int Date::get_Y()
{
	return y;
}

class SinhVien
{
	private:
		string msv;
		string hten;
		double diemthi;
		Date ngaynh;
	public:
		void Ip_SinhVien();
		Date get_Date();
		double get_tdiem();
		void Op_SinhVien();
};

Date SinhVien::get_Date()
{
	return ngaynh;
}

double SinhVien::get_tdiem()
{
	return diemthi;
}

void SinhVien::Ip_SinhVien()
{
	cout << "Ma so sinh vien: ";
	getline(cin,msv);
	cout << "Ho va ten: ";
	getline(cin,hten);
	cout << "Tong diem thi: ";
	cin >> diemthi;
	cout << "Ngay nhap hoc" << endl;
	ngaynh.Ip_Date();
}

void SinhVien::Op_SinhVien()
{
	cout << msv << "\t\t" << hten << "\t\t" << diemthi << "\t\t" << ngaynh.get_D() << "/" << ngaynh.get_M() << "/" << ngaynh.get_Y() << endl;
}

#define Max 100

class QL_SinhVien
{
	private:
		int sl;
		SinhVien a[Max];
	public:
		QL_SinhVien(int i = 0)
		{
			sl = i;
		}
		void Ip_QLSinhVien();
		void Sort_Date();
		void SumPoint_Max();
		void Rank();
};

void QL_SinhVien::Ip_QLSinhVien()
{
	for(int i = 0; i < sl; i++)
	{
		cin.ignore();
		a[i].Ip_SinhVien();
	}
}

void QL_SinhVien::Sort_Date()
{
	Date b;
	for(int i = 0 ; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(b.d_D(a[i].get_Date()) > b.d_D(a[j].get_Date()))
			{
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i = 0; i < sl; i++)
		a[i].Op_SinhVien();
}

void QL_SinhVien::SumPoint_Max()
{
	double MAX = 0;
	for(int i = 0; i < sl; i++)
	{
		if(a[i].get_tdiem() > MAX)
			MAX = a[i].get_tdiem();
	}
	for(int i = 0 ; i < sl; i++)
		if(a[i].get_tdiem() == MAX)
			a[i].Op_SinhVien();
}

void QL_SinhVien::Rank()
{
	for(int i = 0 ; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(a[i].get_tdiem() < a[j].get_tdiem())
			{
				SinhVien t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	double MAX = a[0].get_tdiem();
	for(int i = 0 ; i < sl; i++)
	{
		int index = 1;
		if(MAX == a[i].get_tdiem());
		else if(MAX < a[i].get_tdiem())
		{
			MAX = a[i].get_tdiem();
			index++;
		}
		if(index >= 1 and index <= 3)
			a[i].Op_SinhVien();
	}
}

int main()
{
	int n;
	cout << "So luong: ";
	cin >> n;
	QL_SinhVien a(n);
	a.Ip_QLSinhVien();
//	a.Sort_Date();
//	a.SumPoint_Max();
	a.Rank();
	return 0;
}

