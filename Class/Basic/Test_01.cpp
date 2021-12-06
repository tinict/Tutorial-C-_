#include <bits/stdc++.h>

using namespace std;

class Canbo
{
	protected:
		string MaCB, HoTen, DonVi;
		double Hslg, BaoHiem;
	public:
		void Ip_CANBO();
		void Show_CANBO();
		double TinhLuong_CB();
		string get_DonVi();	 
};

void Canbo::Ip_CANBO()
{
	cout << "Ma Can Bo: ";
	getline(cin, MaCB);
	cout << "Ho va Ten: ";
	getline(cin, HoTen);
	cout << "Don Vi: ";
	getline(cin, DonVi);
	cout << "He so luong: ";
	cin >> Hslg;
	cout << "Bao hiem: ";
	cin >> BaoHiem;
}

void Canbo::Show_CANBO()
{
	cout << setw(0) << MaCB << setw(15) << HoTen << setw(15) << DonVi << setw(10) << Hslg << setw(15) << BaoHiem;
}

double Canbo::TinhLuong_CB()
{
	return Hslg * 1350000 - BaoHiem;
}

string Canbo::get_DonVi()
{
	return DonVi;
}

class Date
{
	private:
		int d, m, y;
	public:
		Date(int day = 1, int month = 1, int year = 1)
		{
			d = day;
			m = month;
			y = year;
		}
		void input_Date();
		void show();
		bool check_leapyear(int);
		bool check_DMY();
		void up_D(int k);
		int re_Date(int,int);
		int d_D(Date);
};

bool Date::check_leapyear(int k)
{
	if(k % 4 == 0 && k  % 100 != 0 || k % 400 == 0)
		return true;
	return false;
}

bool Date::check_DMY()
{
	if(check_leapyear(y) == 1)
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if(d <= 31) return 1;
			else return 0;
		}
		else if(m == 4 || m == 6 || m == 9 || m == 11)
		{
			if(d <= 30) return 1;
			else return 0;
		}
		if(m == 2)
		{
			if(d <= 28) return 1;
			else return 0;
		}
		else return 0;
	}
	else if(check_leapyear(y) == 0)
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if(d <= 31) return 1;
			else return 0;
		}
		if(m == 4 || m == 6 || m == 9 || m == 11)
		{
			if(d <= 30) return 1;
			else return 0;
		}
		if(m == 2)
		{
			if(d <= 28) return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void Date::input_Date()
{
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	while(check_DMY() == 0)
	{
		cout << "Nhap sai ! Moi nhap lai" << endl;
		cout << "Day: ";
		cin >> d;
		cout << "Month: ";
		cin >> m;
		cout << "Year: ";
		cin >> y;
	}
}

int Date::re_Date(int a, int b)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	else if(m == 2)
	{
		if(check_leapyear(b) == 1) return 29;
		else return 28;
	}
}

void Date::show()
{
	cout << d << "/" << m << "/" << y << endl;
}

void  Date::up_D(int k)
{
	while(1)
	{
		if(re_Date(m,y) - d >= k)
		{
			d += k;
			k = 0;
			if(d > re_Date(m,y))
			{
				m++;
				if(m > 12)
				{
					y++;
					m = m - 12;
				}
				d = d - re_Date(m,y);
			}
		}
		else if(re_Date(m,y) - d < k)
		{
			int t = re_Date(m,y) - d + 1;
			d += t;
			k -= t;
			d = d - re_Date(m,y);
			m++;
			if(m > 12)
			{
				y++;
				m = m - 12;
			}
		}
		if(k == 0)
			break;
	}
	show();
}

int Date::d_D(Date a)
{
	int t = 0;
	int f1 = re_Date(m,y) - d;
	int f2 = a.re_Date(a.m,a.y) - a.d;
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
					t += b.re_Date(j,y);
				}
			}
			else if(i == a.y)
			{
				for(int q = 1; q <= a.m ; q++)
				{
					b.m = q;
					t += b.re_Date(q,a.y);
				}
			}
			
			else
			{
				for(int p = 1; p <= 12; p++)
				{
					b.m = p;
					t += b.re_Date(p,i);
				}
			}
		}
		else
		{
			for(int r = m ; r <= a.m; r++)
			{
				b.m = r;
				t += b.re_Date(r,y);
			}
		}
	}
	return t - re_Date(m,y) + f1 - f2;
}

class Nhanvien : public Canbo
{
	protected:
		Date NgayHopDong;
	public:
		void Ip_NhanVien();
		void Show_NhanVien();
		int operator >(Nhanvien);
		Date get_NgayHD();
};

void Nhanvien::Ip_NhanVien()
{
	Ip_CANBO();
	cout << "Ngay hop dong" << endl;
	NgayHopDong.input_Date();
}

void Nhanvien::Show_NhanVien()
{
	Show_CANBO();
	cout << setw(15);
	NgayHopDong.show();
}

Date Nhanvien::get_NgayHD()
{
	return NgayHopDong;
}

int Nhanvien::operator >(Nhanvien nv)
{
	Date Default;
	if(Default.d_D(NgayHopDong) > Default.d_D(nv.NgayHopDong))
		return 1;
	return 0;
}

class QL_CANBO
{
	protected:
		int size;
		Nhanvien CB[50];
	public:
		QL_CANBO(int n = 0)
		{
			size = n;
		}
		void Ip_QLCB();
		void Sort();
		void Show_LUONG();
		void Show_QLCB();
};

void QL_CANBO::Ip_QLCB()
{
	for(int i = 0; i < size; i++)
	{
		cin.ignore();
		CB[i].Ip_NhanVien();
	}
}

void QL_CANBO::Sort()
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(CB[i] > CB[j])
			{
				Nhanvien temp = CB[i];
				CB[i] = CB[j];
				CB[j] = temp;
			}
		}
	}
}

void QL_CANBO::Show_LUONG()
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(CB[i].get_DonVi() == CB[j].get_DonVi())
			{
				CB[i].Show_NhanVien();
				cout << setw(5) << fixed << setprecision(1) << CB[j].TinhLuong_CB() << endl;
			}
		}
	}
}

void QL_CANBO::Show_QLCB()
{
	for(int i = 0; i < size; i++)
		CB[i].Show_NhanVien();
}

int main()
{
	int n;
	cout << "Nhap so luong can bo: ";
	cin >> n;
	QL_CANBO CB(n);
	CB.Ip_QLCB();
	CB.Sort();
	CB.Show_QLCB();
	CB.Show_LUONG();
	return 0;
}
