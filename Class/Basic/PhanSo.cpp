#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class PhanSo
{
	private:
		int t, m;
	public:
		void input_ps();
		void show();
		void cong(PhanSo);
		void tru(PhanSo);
		void nhan(PhanSo);
		void chia(PhanSo);
		int UCLN(int x, int y);
};

void PhanSo::input_ps()
{
	cout << "Tu: "; 
	cin >> t;
	cout << "Mau: ";
	cin >> m;
}

int PhanSo::UCLN(int x, int y)
{
	if(x == 0 || y == 0) return 1;
	if(x == y) return x;
	if(x > y) return UCLN(x-y, y);
	if(x < y) return UCLN(x, y-x);
}

void PhanSo::show()
{
	if(t == 0)
		cout << "Result: " << 0 << endl;
	else if(m == 1)
		cout << "Result: " << t << endl;
	else if(m == 0)
		cout << "Khong the thuc hien" << endl;
	else
		cout << "Result: " << t << "/" << m << endl;
}

void PhanSo::cong(PhanSo a)
{
	PhanSo b;
	b.t = (t*a.m + a.t*m) / UCLN(abs(t*a.m + a.t*m),abs(a.m * m));
	b.m = (a.m * m) / UCLN(abs(t*a.m + a.t*m),abs(a.m * m));
	b.show();
}

void PhanSo::tru(PhanSo a)
{
	PhanSo b;
	b.t = (t*a.m - a.t*m) / UCLN(abs(t*a.m - a.t*m),abs(a.m * m));
	b.m = (a.m * m) / UCLN(abs(t*a.m - a.t*m),abs(a.m * m));
	b.show();
}

void PhanSo::nhan(PhanSo a)
{
	PhanSo b;
	b.t = (t*a.t) / UCLN(abs(t*a.t),abs(m*a.m));
	b.m = (m*a.m) / UCLN(abs(t*a.t),abs(m*a.m));
	b.show();
}

void PhanSo::chia(PhanSo a)
{
	PhanSo b;
	b.t = (t*a.m) / UCLN(abs(t*a.m),abs(m*a.t));
	b.m = (m*a.t) / UCLN(abs(t*a.m),abs(m*a.t));
	b.show();
}

int main()
{
	PhanSo a, b;
	a.input_ps();
	b.input_ps();
	a.cong(b);
	a.tru(b);
	a.nhan(b);
	a.chia(b);
	return 0;
}

