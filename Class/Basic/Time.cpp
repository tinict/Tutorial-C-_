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
		bool chuanhoa();
		Time hamgiatang(int,int,int);
		Time hamdieuchinh(int gio, int phut, int giay);
		void xuat();
};

void Time::Ip_Time()
{
	cout << "h: ";
	cin >> h;
	cout << "m: ";
	cin >> m;
	cout << "s: ";
	cin >> s;
	while(chuanhoa() != true)
	{
		cout << "Thoi gian ban nhap sai ! Moi ban nhap lai :" << endl;
		cout << "h: ";
		cin >> h;
		cout << "m: ";
		cin >> m;
		cout << "s: ";
		cin >> s;
	}
}

bool Time::chuanhoa()
{
	if(s >= 0 and s < 60)
		if(m >= 0 and m <= 60)
			if(h >= 0 and h <= 24)
				return true;
	return false;
}

Time Time::hamgiatang(int gio, int phut, int giay)
{
	Time t;
	t.s = s + giay;
	t.m = t.s / 60 + m + phut;
	t.s = t.s % 60; 
	t.h = t.m / 60 + h + gio;
	t.m = t.m % 60;
	return t;
}

Time Time::hamdieuchinh(int gio, int phut, int giay)
{
	Time t;
}

void Time::xuat()
{
	cout << h << "h " << m << "m " << s << "s" << endl;
}

int main()
{
	Time t;
	t.Ip_Time();
	t.hamdieuchinh(2,3,4);
	t.xuat();
	Time t1;
	t1 = t.hamgiatang(1,2,3);
	t1.xuat();
	return 0;
}

