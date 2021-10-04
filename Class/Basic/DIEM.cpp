#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;
#define Max 2

class DIEM
{
	private:
		int diem[Max];
	public:
		void nhap();
		void xuat();
		double Kc(DIEM x);
};

void DIEM::nhap()
{
	for(int i = 0 ; i < Max ; i++)
		cin >> diem[i];
}

void DIEM::xuat()
{
	for(int i = 0 ; i < Max ; i++)
		cout << diem[i] << " ";
}

double DIEM::Kc(DIEM x)
{
	double sum = 0;
	for(int i = 0 ; i < Max; i++)
		sum += pow(diem[i] - x.diem[i],2);
	return sqrt(sum);
}

int main()
{
	DIEM d,d1;
	d.nhap();
	d1.nhap();
	//d.xuat();
	cout << d.Kc(d1);
	return 0;
}

