#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class DIEM 
{
	private:
		int x,y;
	public:
		void get_x();
		void get_y();
		void nhap();
		void xuat();
		bool check_td(int a , int b);
};

void DIEM::get_x()
{
	cout << "Hoanh do: ";
	cin >> x;
}

void DIEM::get_y()
{
	cout << "Tung do: ";
	cin >> y;
}

void DIEM::nhap()
{
	get_x();
	get_y();
}

bool DIEM::check_td(int a , int b)
{
	if(b == 0)
		return true;
	return false;
}

void DIEM::xuat()
{
	if(check_td(x,y) == 1)
		cout << "(" << x << " , " << y  << ")" << endl;
}

void arr_diem(DIEM s[], int n)
{
	for(int i = 0 ; i < n ; i++)
		s[i].nhap();
}

void arr_xuatdiem(DIEM s[], int n)
{
	for(int i = 0 ; i < n ; i++)
		s[i].xuat();
}

int main()
{
	int n;
	cout << "So diem: ";
	cin >> n;
	DIEM s[n];
	arr_diem(s,n);
	arr_xuatdiem(s,n);
	return 0;
}

