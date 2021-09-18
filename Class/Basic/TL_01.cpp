#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class sach
{
	private:
		string masach,tensach,tentg;
		int soluong;
		string nxb;
	public:
		void nhap();
		void xuat();
};

void sach::nhap()
{
	cout << "Ma sach: ";
	getline(cin,masach);
	cout << "Ten sach: ";
	getline(cin,tensach);
	cout << "Ten tac gia: ";
	getline(cin,tentg);
	cout << "So luong: ";
	cin >> soluong;
	cin.ignore();
	cout << "Nha xuat ban: ";
	getline(cin,nxb);
}

void sach::xuat()
{
	cout << masach << "\t\t" << tensach << "\t\t" << tentg << "\t\t" << soluong << "\t\t" << nxb << endl;
}

int main()
{
	sach s;
	s.nhap();
	s.xuat();
	return 0;
}

