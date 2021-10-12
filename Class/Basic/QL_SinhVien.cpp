#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Date
{
	private:
		int d;
		int m;
		int y;
	public:
		void DMY();
		int get_D();
		int get_M();
		int get_Y();
		void show_DMY();
};

void Date::DMY()
{
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
}

int Date::get_D()
{
	return d;
}

int Date::get_M()
{
	return m;
}

int Date::get_Y()
{
	return y;
}

void Date::show_DMY()
{
	cout << get_D() << "/" << get_M() << "/" << get_Y();
}

class SinhVien
{
	private:
		string Masv;
		string Hosv; // Ho dem
		string Tensv;
		Date Ngaysinh;
		int GioiTinh;
	public:
		void Ip_Masv();
		void Ip_Hosv();
		void Ip_Tensv();
		void Ip_Ngaysinh();
		void Ip_Gioitinh();
		string get_Masv();
		string get_Hosv();
		string get_Tensv();
		int get_GioiTinh();
		void get_Ngaysinh();
};

void SinhVien::Ip_Masv()
{
	cout << "Ma sinh vien: ";
	getline(cin,Masv);
}

string SinhVien::get_Masv()
{
	return Masv;
}

void SinhVien::Ip_Hosv()
{
	cout << "Ho: ";
	getline(cin,Hosv);
}

string SinhVien::get_Hosv()
{
	return Hosv;
}

void SinhVien::Ip_Tensv()
{
	cout << "ten sinh Vien: ";
	getline(cin,Tensv);
}

string SinhVien::get_Tensv()
{
	return Tensv;
}

void SinhVien::Ip_Ngaysinh()
{
	cout << "Ngay Sinh" << endl;
	Ngaysinh.DMY();
}

void SinhVien::get_Ngaysinh()
{
	Ngaysinh.show_DMY();
}

void SinhVien::Ip_Gioitinh()
{
	cout << "Gioi Tinh: ";
	cin >> GioiTinh;
}

int SinhVien::get_GioiTinh()
{
	return GioiTinh;
}

#define Max 100

class List_SinhVien
{
	private:
		int sluong;
		SinhVien a[Max];
	public:
		List_SinhVien(int n = 0)
		{
			sluong = n;
		}
		void ipList_SinhVien();
		void opList_SinhVien();
		bool check_MaSV(string ID);
		void Sort_SV();
		void Search_MSV();
		void Remove_SV(string ID);
		void add_SV();
};

bool List_SinhVien::check_MaSV(string ID)
{
	for(int i = 0 ; i < sluong - 1; i++)
		if(a[i].get_Masv() == ID)
			return false;
	return true;
}

void List_SinhVien::ipList_SinhVien()
{
	for(int i = 0; i < sluong; i++)
	{
		a[i].Ip_Masv();
		while(check_MaSV(a[i].get_Masv()) == false and i != 0)
		{
			cout << "Ma sinh vien da ton tai !" << endl;
			a[i].Ip_Masv();
		}
		a[i].Ip_Hosv();
		a[i].Ip_Tensv();
		a[i].Ip_Ngaysinh();
		a[i].Ip_Gioitinh();
		cin.ignore();
	}
}

void List_SinhVien::Sort_SV()
{
	for(int i = 0; i < sluong - 1; i++)
	{
		for(int j = i + 1; j < sluong; j++)
		{
			if(a[i].get_Tensv() > a[j].get_Tensv())
			{
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void List_SinhVien::opList_SinhVien()
{
	cout << "****************************************************************************************" << endl;
	cout << "Ma SV" << "\t\t" << "Ho dem" << "\t\t" << "Ten SV" << "\t\t" << "Ngay Sinh" << "\t\t" << "Gioi Tinh" << endl;
	for(int i = 0; i < sluong; i++)
	{
		cout << a[i].get_Masv() << "\t\t" << a[i].get_Hosv() << "\t\t" << a[i].get_Tensv() << "\t\t";
		a[i].get_Ngaysinh(); 
		cout << "\t\t\t" << a[i].get_GioiTinh() << endl;
	}
} 

void List_SinhVien::Search_MSV()
{
	string s;
	cout << "Search" << endl;
	cout << "Ma Sinh Vien: ";
	getline(cin,s);
	for(int i = 0 ; i < sluong; i++)
	{
		if(s == a[i].get_Masv())
		{
			cout << "****************************************************************************************" << endl;
			cout << "Ma SV" << "\t\t" << "Ho dem" << "\t\t" << "Ten SV" << "\t\t" << "Ngay Sinh" << "\t\t" << "Gioi Tinh" << endl;
			cout << a[i].get_Masv() << "\t\t" << a[i].get_Hosv() << "\t\t" << a[i].get_Tensv() << "\t\t";
			a[i].get_Ngaysinh(); 
			cout << "\t\t\t" << a[i].get_GioiTinh() << endl;
		}
	}
}

void List_SinhVien::Remove_SV(string ID)
{
	int j = 0;
	for(int i = 0; i < sluong; i++)
	{
		if(ID != a[i].get_Masv())
			a[j++] = a[i];
	}
	sluong--;
}

void List_SinhVien::add_SV()
{
	int j = 0;
	sluong++;
	a[sluong];
	for(int i = 0; i < sluong; i++)
	{
		if(i == sluong - 1)
		{
			a[i].get_Masv();
			while(check_MaSV(a[i].get_Masv()) == false and i != 0)
			{
				cout << "Ma sinh vien da ton tai !" << endl;
				a[i].Ip_Masv();
			}
			a[i].Ip_Hosv();
			a[i].Ip_Tensv();
			a[i].Ip_Ngaysinh();
			a[i].Ip_Gioitinh();
			cin.ignore();
		}
		else
			a[j++] = a[i];
	}
}

int main()
{
	List_SinhVien a(2);
	a.ipList_SinhVien();
	a.opList_SinhVien();
	a.add_SV();
	a.opList_SinhVien();
	//a.Search_MSV();
	//string ID;
	//getline(cin,ID);
	//a.Remove_SV(ID);
	//a.opList_SinhVien();
	return 0;
}
