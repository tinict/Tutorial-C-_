#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;
#define Max 100

class Vecto
{
	private:
		int Size;
		int v[Max];
	public:
		void Nhap_Vecto(int n);
		void Xuat_Vecto();
		int get_Vecto(int i);
		double TichVH_Vecto(Vecto a);
		double Modul_Vecto(Vecto a);
};

int Vecto::get_Vecto(int i)
{
	return v[i];
}

void Vecto::Nhap_Vecto(int n)
{
	Size = n;
	for(int i = 0 ; i < Size; i++)
		cin >> v[i];
}

void Vecto::Xuat_Vecto()
{
	for(int i = 0 ; i < Size; i++)
		cout << v[i] << " ";
}

double Vecto::TichVH_Vecto(Vecto a)
{
	double sum = 0;
	for(int i = 0; i < Size; i++)
		sum += a.get_Vecto(i) + v[i];
	return sum;
}

double Vecto::Modul_Vecto(Vecto a)
{
	double sum = 0;
	for(int i = 0; i < Size; i++)
		sum += sum + pow(a.get_Vecto(i) - v[i],2);
	return sqrt(sum);
}

int main()
{
	Vecto a,b;
	a.Nhap_Vecto(5);
	b.Nhap_Vecto(5);
	cout << a.TichVH_Vecto(b) << endl;
	cout << a.Modul_Vecto(b) << endl;
	return 0;
}

