#include <bits/stdc++.h>

using namespace std;

class Date
{
	protected:
		int d, m, y;
	public:
		Date(int d = 1, int m = 1, int y = 1)
		{
			this->d = d;
			this->m = m;
			this->y = y;
		}
		void Ip_Date();
		int get_D();
		int get_M();
		int get_Y();
		int re_Date(); // tra ve ngay cuar cac thang trong nam
		int d_D(Date a); // khoang cach giua 2 moc thoi gian
		bool check_leapyear(); // kiem tra nam nhuan
};

void Date::Ip_Date()
{
	cout << "Ngay: ";
	cin >> d;
	cout << "Thang: ";
	cin >> m;
	cout << "Nam: ";
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

bool Date::check_leapyear()
{
	if(y % 4 == 0 && y  % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}

int Date::re_Date()  //re_Date(month,year)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	else if(m == 2)
	{
		if(check_leapyear() == 1) return 29;
		else return 28;
	}
}

int Date::d_D(Date a)
{
	int t = 0;
	int f1 = re_Date() - d, f2 = a.re_Date() - a.d;
	int k = a.y - y + 1;
	Date b;
	for(int i = y; i <= a.y; i++)
	{
		if(k != 1)
		{
			if(i == y)
			{
				for(int j = m ; j <= 12; j++)
				{
					b.m = j;
					b.y = i;
					t += b.re_Date();
				}
			}
			else if(i == a.y)
			{
				for(int q = 1; q <= a.m ; q++)
				{
					b.m = q;
					b.y = i;
					t += b.re_Date();
				}
			}
			
			else
			{
				for(int p = 1; p <= 12; p++)
				{
					b.m = p;
					b.y = i;
					t += b.re_Date();
				}
			}
		}
		else
		{
			for(int r = m ; r <= a.m; r++)
			{
				b.m = r;
				b.y = i;
				t += b.re_Date();
			}
		}
	}
	return t - re_Date() + f1 - f2;
}

class SinhVien: public Date
{
	protected:
		string Masv, Hodem, Ten, sdt;
		double dtb;
	public:
		SinhVien()
		{
			this->Masv = " ";
			this->Hodem = " ";
			this->Ten = " ";
			this->sdt = " ";
			this->dtb = 0;	
		}
		void Ip_SinhVien();
		void Show_SinhVien();	
		string get_MaSV();
		string get_HoDem();
		string get_Ten();
		string get_SDT();
		double get_dtb();
		int operator > (SinhVien);
		int operator >= (SinhVien);
		int operator < (SinhVien);
};

void SinhVien::Ip_SinhVien()
{
	cin.ignore();
	cout << "Ma sinh vien: ";
	getline(cin,Masv);
	cout << "Ho dem: ";
	getline(cin,Hodem);
	cout << "Ten: ";
	getline(cin,Ten);
	cout << "[Ngay/Thang/Nam] sinh" << endl;
	cout << "Ngay: ";
	cin >> d;
	cout << "Thang: ";
	cin >> m;
	cout << "Nam: ";
	cin >> y;
	cin.ignore();
	cout << "So dien thoai: ";
	getline(cin,sdt);
	cout << "Diem trung binh: ";
	cin >> dtb;
}

void SinhVien::Show_SinhVien()
{
	cout << setw(5) << Masv << setw(20) << Hodem + " " + Ten << setw(10) << d << "-" << m << "-" << y << setw(15) << sdt << setw(10) << dtb << endl;
}

string SinhVien::get_MaSV()
{
	return Masv;
}

string SinhVien::get_HoDem()
{
	return Hodem;
}

string SinhVien::get_Ten()
{
	return Ten;
}

string SinhVien::get_SDT()
{
	return sdt;
}

double SinhVien::get_dtb()
{
	return dtb;
}

int SinhVien::operator > (SinhVien B)
{
	Date temp;
	Date day_1(d, m, y);
	Date day_2(B.get_D(), B.get_M(), B.get_Y());
	if(temp.d_D(day_1) < temp.d_D(day_2))
		return 1;
	return 0;
}

int SinhVien::operator >=(SinhVien B)
{
	if(dtb >= B.dtb)
		return 1;
	return 0;
}

int SinhVien::operator <(SinhVien B)
{
	if(Ten < B.Ten)
		return 1;
	else if(Ten == B.Ten)
		if(Hodem < B.Hodem)
			return 1;
	else
		return 0;
}

class QL_SINHVIEN
{
	protected:
		SinhVien SV[100];
		int size;
	public:
		QL_SINHVIEN(int n = 0)
		{
			size = n;
		}
		void Sort_Name();
		void Sort_DTB();
		void Show_QLSinhVien();
		void Ip_QLSinhVien();
		void Search_MSV(string);
		void find_NgaySinh();
		void Max_dtb();
		void In_Vithu();
};

void QL_SINHVIEN::Ip_QLSinhVien()
{
	for(int i = 0; i < size; i++)
		SV[i].Ip_SinhVien();
}

void QL_SINHVIEN::Sort_DTB()
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(SV[i].get_dtb() < SV[j].get_dtb())
			{
				SinhVien temp = SV[i];
				SV[i] = SV[j];
				SV[j] = temp;
			}
		}
	}
}

void QL_SINHVIEN::Sort_Name()
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(SV[i] < SV[j])
			{
				SinhVien temp = SV[i];
				SV[i] = SV[j];
				SV[j] = temp;
			}
		}
	}
}

void QL_SINHVIEN::Show_QLSinhVien()
{
	for(int i = 0; i < size; i++)
		SV[i].Show_SinhVien();
}

void QL_SINHVIEN::Search_MSV(string msv)
{
	int flag = 0;
	for(int i = 0; i < size; i++)
	{
		if(msv == SV[i].get_MaSV())
		{
			flag = 1;
			SV[i].Show_SinhVien();
		}
	}
	if(flag = 0)
		cout << "Ma sinh vien khong ton tai !" << endl;
}

void QL_SINHVIEN::find_NgaySinh()
{
	int flag = 0;
	Date check(20,5,2000);
	for(int i = 0; i < size; i++)
	{
		if(check.get_D() == 20 and check.get_M() == 5 and check.get_Y() == 2002)
		{
			flag = 1;
			SV[i].Show_SinhVien();
		}
	}
	if(flag == 0)
		cout << "Khong ton tai nhung sinh vien sinh ngay 20/5/2000 !" << endl;
}

void QL_SINHVIEN::Max_dtb()
{
	SinhVien Max = SV[0];
	for(int i = 0; i < size; i++)
		if(Max.get_dtb() < SV[i].get_dtb())
			Max = SV[i];
	Max.Show_SinhVien();
}

void QL_SINHVIEN::In_Vithu()
{
	Sort_DTB();
	SinhVien f = SV[0];
	int rank = 1;
	for(int i = 0; i < size; i++)
	{
		if(f.get_dtb() == SV[i].get_dtb())
		{
			SV[i].Show_SinhVien();
			cout << "Rank: " << rank << endl;
		}
		if(f.get_dtb() > SV[i].get_dtb())
		{
			f = SV[i];
			SV[i].Show_SinhVien();
			rank++;
			cout << "Rank: " << rank << endl;
		}
	}
}

int main()
{
	int n;
	cout << "So luong sinh vien: ";
	cin >> n;
	QL_SINHVIEN a(n);
	a.Ip_QLSinhVien();
	a.Sort_Name(); // sap xep theo thu tu tang ho dem va ten
	cout << "------------------------------------------------" << endl;
	a.Show_QLSinhVien();
	a.Sort_DTB(); // sap xep theo thu tu giam dan cua diem trung binh
	cout << "------------------------------------------------" << endl;
	a.Show_QLSinhVien();
	cout << "------------------------------------------------" << endl;
	string t;
	cin.ignore();
	cout << "Ma sinh vien can tim kiem: ";
	getline(cin,t);
	a.Search_MSV(t);
	cout << "------------------------------------------------" << endl;
	a.find_NgaySinh(); // tim kiem va in sinh vien 20/5/2000
	cout << "------------------------------------------------" << endl;
	a.Max_dtb(); // in ra thong tin sinh vien co diem trung binh cao nhat
	cout << "------------------------------------------------" << endl;
	a.In_Vithu(); // in ea vi thu cua sinh vien 
	cout << "------------------------------------------------" << endl;
	return 0;
}
