#include<bits/stdc++.h>
using namespace std;

class SinhVien
{
	private:
		char msv[50], hten[50];
	public:
		void info();
		char *get_msv();
		char *get_hten();
		void show();
};

void SinhVien::info()
{
	cout << "Ma sinh vien: ";
	gets(msv);
	cout << "Ho va Ten: ";
	gets(hten);
}

char *SinhVien::get_msv()
{
	return msv;
}

void SinhVien::show()
{
	cout << msv << "\t\t\t" << hten << endl;
}

char *SinhVien::get_hten()
{
	return hten;
}

void arr_sv(SinhVien s[50], int n)
{
	for(int i = 0 ; i < n; i++)
	{
		//cin.ignore();
		s[i].info();
	}
}

void op_sv(SinhVien s[], int n)
{
	cout << "Ma Sinh Vien" << "\t\t" << "Ho va Ten" << endl;
	for(int i = 0 ; i < n ; i++)
		s[i].show();
}

void sort(SinhVien s[], int n)
{
	for(int i = 0 ; i < n - 1 ; i++)
	{
		for(int j = i + 1 ; j < n; j++)
		{
			if(strcmp(s[i].get_hten(), s[j].get_hten())> 0)
			{
				SinhVien t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
}

int main()
{
	SinhVien *s = new SinhVien[50];
	int n;
	cout << "So luong: ";
	cin >> n;
	cin.ignore();
	arr_sv(s,n);
	sort(s,n);
	op_sv(s,n);
 	return 0;
}


