#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		Time(int h = 0,int m = 0, int s = 0)
		{
			this->h = h;
			this->m = m;
			this->s = s;
		}
		void Ip_Time();
		void Op_Time();
		bool Standardize(); // Phuong thuc chuan hoa thoi gian
		Time Subtract(Time t); // Phuong thuc tru 1 thoi diem
		Time Sum(Time t); // Phuong thuc cong 2 thoi diem
		int get_h(); // Lay h ra
		int get_m(); // Lay m ra
		int get_s(); // Lay s ra
};

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

void Time::Ip_Time()
{
	cout << "h: ";
	cin >> h;
	cout << "m: ";
	cin >> m;
	cout << "s: ";
	cin >> s;
	while(Standardize() != true)
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

bool Time::Standardize()
{
	if(s >= 0 and s < 60)
		if(m >= 0 and m <= 60)
			if(h >= 0 and h <= 24)
				return true;
	return false;
}

Time Time::Sum(Time t)
{
	Time temp;
	temp.s = s + t.get_s();
	temp.m = temp.s / 60 + m + t.get_m();
	temp.s = temp.s % 60; 
	temp.h = temp.m / 60 + h + t.get_h();
	temp.m = temp.m % 60;
	return temp;
}

void Time::Op_Time()
{
	cout << h << "h " << m << "m " << s << "s" << endl;
}

Time Time::Subtract(Time t)
{
	Time temp;
	temp.s = t.get_s() - s;
	temp.m = t.get_m() - m;
	temp.h = t.get_h() - h;
	//temp.Op_Time();
	if(temp.get_s() < 0)
	{
		temp.s = 60 + temp.get_s();
		temp.m = -1 + temp.get_m();
	}
	//temp.Op_Time();
	if(temp.get_m() < 0)
	{
		temp.m = 60 + temp.get_m();
		temp.h = -1 + temp.get_h();
	}
	//temp.Op_Time();
	return temp;
}

int main()
{
	Time t1,t2;
	t1.Ip_Time(); // 1h2p3s
	t2.Ip_Time(); // 4h5p6s
	t1.Op_Time(); // 1h2p3s
	t2.Op_Time(); // 4h5p6s
	t1 = t1.Sum(t2); // t2 + t1 = 1h2p3s + 4h5p6s = 5h7p9s
	t1.Op_Time(); // 5h7p9s
	t1 = t2.Subtract(t1); // t1 - t2 = 5h7p9s - 4h5p6s = 1h2p3s
	t1.Op_Time(); // 1h2p3s
	return 0;
}

