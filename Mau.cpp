#include <bits/stdc++.h>

using namespace std;

class PHONG
{
	protected:
		int songay;
		double dongia;
	public:
		virtual double dongia_LP()
		{
			return 0;
		}
		virtual double Tinhtienthuephong()
		{
			return dongia * songay;
		}
		virtual void Nhap_Phong();
		virtual string PHANLOAI()
		{
			return " ";
		}
};

void PHONG::Nhap_Phong()
{
	cout << "So ngay: ";
	cin >> songay;
	dongia = dongia_LP();
	Tinhtienthuephong();
}

class Phong_A: public PHONG
{
	protected:
		double tien_DV;
	public:
		string PHANLOAI()
		{
			return "A";
		}
		double dongia_LP()
		{
			return 80;
		}
		double Tinhtienthuephong()
		{
			if(songay >= 5)
			{
				return (dongia_LP() * songay + tien_DV) * 0.9;
			}
			else
			{
				return dongia_LP() * songay + tien_DV;
			}
		}
		void Nhap_Phong();
};

void Phong_A::Nhap_Phong()
{
	cout << "So ngay: ";
	cin >> songay;
	cout << "Tien dich vu: ";
	cin >> tien_DV;
	dongia = dongia_LP();
	Tinhtienthuephong();
}

class Phong_B: public PHONG
{
	public:
		string PHANLOAI()
		{
			return "B";
		}
		double dongia_LP()
		{
			return 60;
		}
		double Tinhtienthuephong()
		{
			if(songay >= 5)
			{
				return dongia_LP() * songay * 0.9;
			}
			else
			{
				return dongia_LP() * songay;
			}
		}
};

class Phong_C: public PHONG
{
	public:
		string PHANLOAI()
		{
			return "C";
		}
		double dongia_LP()
		{
			return 40;
		}
		double Tinhtienthuephong()
		{
			return dongia * songay;
		}
};

class QL_Phong
{
	protected:
		PHONG *DS[100]; // con tro
		int size; // chi so phan tu
	public:
		QL_Phong(int n = 0) // Ham tao
		{
			size = n;
		}
		void Nhap_DS();
		void Xuat_DS();
};

void QL_Phong::Nhap_DS()
{
	for(int i = 0; i < size; i++)
	{
		string t;
		cout << "Loai phong: ";
		cin >> t;
		if(t == "A")
		{
			Phong_A *p = new Phong_A; 
			p->Nhap_Phong(); 
			DS[i] = p;  
		}
		else if(t == "B")
		{
			Phong_B *p = new Phong_B; 
			p->Nhap_Phong(); 
			DS[i] = p;  
		}
		else
		{
			Phong_C *p = new Phong_C; 
			p->Nhap_Phong(); 
			DS[i] = p;  
		}
	}
}

void QL_Phong::Xuat_DS()
{
	cout << "Xuat so tien thue phong loai A" << endl;
	for(int i = 0 ; i < size; i++)
	{
		if(DS[i]->PHANLOAI() == "A")		
			cout << DS[i]->Tinhtienthuephong() << endl;
	}
	cout << "Xuat so tien thue phong loai B" << endl;
	for(int i = 0 ; i < size; i++)
	{
		if(DS[i]->PHANLOAI() == "B")		
			cout << DS[i]->Tinhtienthuephong() << endl;
	}
	cout << "Xuat so tien thue phong loai C" << endl;
	for(int i = 0 ; i < size; i++)
	{
		if(DS[i]->PHANLOAI() == "C")		
			cout << DS[i]->Tinhtienthuephong() << endl;
	}
}

int main()
{
	int n;
	cout << "So luong: ";
	cin >> n;
	QL_Phong a(n);
	a.Nhap_DS();
	a.Xuat_DS();
	return 0;
}
