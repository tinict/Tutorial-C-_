#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		Time(int gio = 7, int phut = 30, int giay = 0)
		{
			h = gio;
			m = phut;
			s = giay;
		}
		void Ip_Time();
		void Op_Time();
		int get_h();
		int get_m();
		int get_s();
		Time Subtract(Time t);
};

Time Time::Subtract(Time t)
{
	Time t1;
	t1.s = t.get_s() - s;
	t1.m = t.get_m() - m;
	t1.h = t.get_h() - h;
	//t1.Op_Time();
	if(t1.get_s() < 0)
	{
		t1.s = 60 + t1.get_s();
		t1.m = -1 + t1.get_m();
	}
	//t1.Op_Time();
	if(t1.get_m() < 0)
	{
		t1.m = 60 + t1.get_m();
		t1.h = -1 + t1.get_h();
	}
	//t1.Op_Time();
	return t1;
}

void Time::Ip_Time()
{
	cout << "h: ";
	cin >> h;
	cout << "m: ";
	cin >> m;
	cout << "s: ";
	cin >> s;
}

void Time::Op_Time()
{
	cout << h << ":" << m << ":" << s;
}

int Time::get_h()
{
	return h;
}

int Time::get_m()
{
	return m;
}

int Time::get_s()
{
	return s;
}

class BaiThi
{
	private:
		string masv,hten;
		Time thoigianBD,thoigianKT;
		double diemthi;
	public:
		void Ip_BaiThi();
		void Op_BaiThi();
		string get_hten();
		Time get_TimeBD();
		Time get_TimeKT();
		double get_diemthi();
};

void BaiThi::Ip_BaiThi()
{
	cout << "Ma sinh vien: ";
	getline(cin,masv);
	cout << "Ho va Ten: ";
	getline(cin,hten);
	cout << "Thoi gian bat dau lam bai thi" << endl;
	thoigianBD.Ip_Time();
	cout << "Thoi gian ket thuc lam bai thi" << endl;
	thoigianKT.Ip_Time();
	cout << "Diem thi: ";
	cin >> diemthi;
}

void BaiThi::Op_BaiThi()
{
	cout << masv << "\t\t" <<  hten << "\t\t" << diemthi << "\t\t";
	thoigianBD.Op_Time();
	cout << "\t\t";
	thoigianKT.Op_Time();
	cout << endl;
}

string BaiThi::get_hten()
{
	return hten;
}

Time BaiThi::get_TimeBD()
{
	return thoigianBD;
}

Time BaiThi::get_TimeKT()
{
	return thoigianKT;
}

double BaiThi::get_diemthi()
{
	return diemthi;
}

#define Max 50

class QL_BaiThi
{
	private:
		int sl;
		BaiThi a[Max];
	public:
		QL_BaiThi(int i = 0)
		{
			sl = i;
		}
		void Ip_QLBaiThi(); // NHAP KHONG QUA 50 BAI THI
		void Sort_hten(); // SAP XEP THEO HO VA TEN CUA THI SINH THAM GIA
		void Sort_LateTimeBD(); // SAP XEP NHUNG THI SINH BAT DAU THAM GIA BAI THI MUON
		int KC_Time(Time t, Time check); // TINH KHOANG CACH GIUA 2 MOC THOI GIAN
		void Submit_Late(); // IN RA NHUNG NGUOI NOP BAI MUON
		void Submit_Soon_RankPointMax(); // IN RA NHUNG BAI NOP SOM COS DIEM NAM TU 8 DEN 10
};

void QL_BaiThi::Ip_QLBaiThi()
{
	for(int i = 0; i < sl; i++)
	{
		cin.ignore();
		a[i].Ip_BaiThi();
	}
}

void QL_BaiThi::Sort_hten()
{
	for(int i = 0; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(a[i].get_hten() > a[j].get_hten())
			{
				BaiThi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i = 0; i < sl; i++)
		a[i].Op_BaiThi();
}

int  QL_BaiThi::KC_Time(Time t1, Time check)
{
	Time temp = check.Subtract(t1);
	return temp.get_h() * 3600 + temp.get_m() * 60 + temp.get_s();
}

void QL_BaiThi::Sort_LateTimeBD()
{
	Time check;
	for(int i = 0; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(KC_Time(a[i].get_TimeBD(),check) < KC_Time(a[j].get_TimeBD(), check))
			{
				BaiThi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i = 0; i < sl; i++)
		a[i].Op_BaiThi();
}

void QL_BaiThi::Submit_Late()
{
	Time check;
	for(int i = 0; i < sl; i++)
		if(KC_Time(a[i].get_TimeKT(), check) > 3600)
			a[i].Op_BaiThi();
}

void QL_BaiThi::Submit_Soon_RankPointMax() 
{
	Time check;
	for(int i = 0; i < sl - 1; i++)
	{
		for(int j = i + 1; j < sl; j++)
		{
			if(KC_Time(a[i].get_TimeKT(), a[i].get_TimeBD()) > KC_Time(a[j].get_TimeKT(), a[j].get_TimeBD()))
			{
				BaiThi temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	int Min_Time = KC_Time(a[0].get_TimeKT(), a[0].get_TimeBD());
	for(int i = 0; i < sl; i++)
	{
		int j = 1;
		if(Min_Time == KC_Time(a[i].get_TimeKT(), a[i].get_TimeBD()))
		{
			if(a[i].get_diemthi() <= 10 and a[i].get_diemthi() >= 8)
			{
				a[i].Op_BaiThi();
				cout << "Rank: " << j << endl;
			}
		}
		else if(Min_Time < KC_Time(a[i].get_TimeKT(), a[i].get_TimeBD()))
		{
			Min_Time = KC_Time(a[i].get_TimeKT(), a[i].get_TimeBD());
			if(a[i].get_diemthi() <= 10 and a[i].get_diemthi() >= 8)
			{
				j++;
				a[i].Op_BaiThi();
				cout << "Rank: " << j << endl;
			}
		}
		
	}
}

int main()
{
	/*
	Time a(7,30,0);
	Time b(8,0,0);
	Time c;
	c = a.Subtract(b);
	b.Op_Time();
	a.Op_Time();
	c.Op_Time(); 
	*/
	int n;
	cout << "Nhap so luong bai thi tham gia: ";
	cin >> n;
	QL_BaiThi B(n);
	B.Ip_QLBaiThi();
	cout << "***************************" << endl;
	B.Sort_hten();
	cout << "***************************" << endl;
	B.Sort_LateTimeBD();
	cout << "***************************" << endl;
	B.Submit_Late();
	cout << "***************************" << endl;
	B.Submit_Soon_RankPointMax();
	return 0;
}
