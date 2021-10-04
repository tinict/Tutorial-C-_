#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;
#define Max 100

class DaThuc
{
	private:
		int Size;
		int a[Max];
	public:
		DaThuc(int i = 1)
		{
			Size = i;
		}
		void nhap();
		void xuat();
		DaThuc cong(DaThuc b);
		DaThuc Ip_DT(int x,int i);
		int get_DT(int i);
		DaThuc tru(DaThuc b);
};

int DaThuc::get_DT(int i)
{
	return a[i];
}

DaThuc DaThuc::Ip_DT(int x, int i)
{
	return a[i] = x;
}

void DaThuc::nhap()
{
	for(int i = 0; i <= Size; i++)
		cin >> a[i];
}

void DaThuc::xuat()
{
	for(int i = 0 ; i <= Size; i++)
	{
		if(i == 0)
			cout << a[i] << " + " ;
		else if(i == Size)
			cout << a[i] << "x^" << i;
		else
			cout << a[i] << "x^" << i << " + " ;
	}
}

DaThuc DaThuc::cong(DaThuc b)
{
	DaThuc c(Size);
	for(int i = 0; i <= Size; i++)
	{
		int t = a[i] + b.get_DT(i);
		c.Ip_DT(t,i);
	}
	return c;
}

int main()
{
	DaThuc dt1(4), dt2(4), dt(4);
	dt1.nhap();
	dt2.nhap();
	dt = dt1.cong(dt2);
	dt.xuat();
	return 0;
}

