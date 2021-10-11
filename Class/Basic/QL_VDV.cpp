#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		void Ip_Time();
		void Op_Time();
		int get_h();
		int get_m();
		int get_s();
};

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

class VDV
{
	private:
		int ms;
		string hten;
		Time thoigianxp;
		Time thoigiankt;
	public:
		void inf_VDV();
		int get_ms();
		void Print();
		int KC_time(Time a, Time b);
		Time get_thoigianxp();
		Time get_thoigiankt();
};

Time VDV::get_thoigianxp()
{
	return thoigianxp;	
} 

Time VDV::get_thoigiankt()
{
	return thoigiankt;
}



int VDV::KC_time(Time a,Time b)
{
	int g = a.get_h() - b.get_h();
	int p = abs(a.get_m() - b.get_m());
	int ss = abs(a.get_s() - b.get_s());
	return g*120 + p*60 + ss;
}

int VDV::get_ms()
{
	return ms;
}

void VDV::inf_VDV()
{
	cout << "Ma so: ";
	cin >> ms;
	cin.ignore();
	cout << "Ho va Ten: ";
	getline(cin,hten);
	cout << "Thoi gian xuat phat " << endl;
	thoigianxp.Ip_Time();
	cout << "Thoi gian ket thuc " << endl;
	thoigiankt.Ip_Time();
}

void VDV::Print()
{
	cout << ms << "\t\t" << hten << "\t\t";
	thoigiankt.Op_Time();
	cout << "\t\t";
	thoigiankt.Op_Time();
	cout << endl;
}

#define Max 50

class QL_VDV
{
	private:
		int n;
		VDV a[Max];
	public:
		QL_VDV(int sl = 0)
		{
			n = sl;
		}
		void inf();
		void sort_VDV();
		void print_VDV();
		void Max_VDV();
		int Min_Time();
		void Rank();
};

void QL_VDV::inf()
{
	for(int i = 0; i < n; i++)
		a[i].inf_VDV();	
}

void QL_VDV::sort_VDV()
{
	for(int i = 0 ; i < n - 1; i++)
	{
		for(int j = i + 1 ; j < n; j++)
		{
			if(a[i].get_ms() > a[j].get_ms())
			{
				VDV t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void QL_VDV::print_VDV()
{
	sort_VDV();
	for(int i = 0 ; i < n; i++)
		a[i].Print();
}

void QL_VDV::Max_VDV()
{
	float TB = 0;
	for(int i = 0 ; i < n; i++)
		TB += a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp());
	TB = (float)TB/n;
	for(int i = 0 ; i < n; i++)
		if(a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp()) < TB)
			a[i].Print();
}

int QL_VDV::Min_Time()
{
	int Min = 0;
	for(int i = 0 ; i < n; i++)
		if(Min > a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp()))
			Min = a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp());
	return Min;
}

void QL_VDV::Rank()
{
	int rank = Min_Time();
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1 ; j < n; j++)
		{
			if(a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp()) > a[j].KC_time(a[j].get_thoigiankt(),a[j].get_thoigianxp()))
			{
				VDV t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(int i = 0 ; i < n; i++)
	{
		int j = 1;
		if(rank == a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp()))
		{
			a[i].Print();
			cout << "Rank: " << j << endl;
		}
		else if(rank < a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp()))
		{
			rank = a[i].KC_time(a[i].get_thoigiankt(),a[i].get_thoigianxp());
			j++;
			a[i].Print();
			cout << "Rank: " << j << endl;
		}
	}
}

int main()
{
	int n;
	cout << "So luong van dong vien: ";
	cin >> n;
	QL_VDV a(n);
	a.inf();
	a.print_VDV();
	a.Max_VDV();
	return 0;
}

