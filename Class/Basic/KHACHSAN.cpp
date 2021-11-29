#include <bits/stdc++.h>

using namespace std;

class Phong
{
	protected:
		double dongia;
		int songay;
	public:
		virtual double giaphong()
		{
			return 0;
		}
		virtual double Tinh_TienThue()
		{
			return giaphong() * songay;
		}
		virtual void Nhap_Phong();
};

void Phong::Nhap_Phong()
{
	dongia = giaphong();
	Tinh_TienThue();
	cout << "So ngay: ";
	cin >> songay;
}

class Phong_A: public Phong
{
	protected:
		double tien_DV;
	public:
		double giaphong()
		{
			return 80;
		}
		double Tinh_TienThue()
		{
			double temp = giaphong() * songay + tien_DV;
			if(songay >= 5)
				return temp - 0.1 * temp;
			else
				return temp;
		}
		void Nhap_Phong();
};

void Phong_A::Nhap_Phong()
{
	Phong::Nhap_Phong();
	Tinh_TienThue();
	cout << "Tien dich vu: ";
	cin >> tien_DV;
}

class Phong_B: public Phong
{
	public:
		double giaphong()
		{
			return 60;
		}
		double Tinh_TienThue()
		{
			double temp = giaphong() * songay;
			if(songay >= 5)
				return temp - 0.1 * temp;
			else
				return temp;
		}
};

class Phong_C: public Phong
{
	public:
		double giaphong()
		{
			return 40;
		}
		double Tinh_TienThue()
		{
			return giaphong() * songay;
		}
};

class QL_KHACHSAN
{
	protected:
		int size;
		Phong *DS[100];
	public:
		QL_KHACHSAN(int n = 0)
		{
			size = n;
		}
		void Nhap_DS();
		void Xuat_Tongtien();
};

void QL_KHACHSAN::Nhap_DS()
{
	for(int i = 0; i < size; i++)
	{
		string c;
		cout << "Phong loai: ";
		cin >> c;
		if(c == "A")
		{
			Phong_A *p = new Phong_A;
			p->Nhap_Phong();
			DS[i] = p;
		}
		else if(c == "B")
		{
			Phong_B *q = new Phong_B;
			q->Nhap_Phong();
			DS[i] = q;
		}
	}
}

void QL_KHACHSAN::Xuat_Tongtien()
{
	for(int i = 0; i < size; i++)
	{
		cout << DS[i]->Tinh_TienThue() << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	QL_KHACHSAN a(n);
	a.Nhap_DS();
	a.Xuat_Tongtien();
	return 0;
}
