#include <bits/stdc++.h>

using namespace std;

class CANBO
{
	protected:
		string hoten;
		int age;
		int sex;
		string address;
	public:
		virtual void Ip_info();
		virtual void Op_info();
		virtual string donvi();
		string get_hten();
};

void CANBO::Ip_info()
{
	cout << "Ho va Ten: ";
	getline(cin, hoten);
	cout << "Age: ";
	cin >> age;
	cout << "Sex: ";
	cin >> sex;
	cin.ignore();
	cout << "Dia chi: ";
	getline(cin, address);
}

void CANBO::Op_info()
{
	cout << setw(15) << hoten << setw(10) << age << setw(10) << sex << setw(10) << address << endl;
}

string CANBO::donvi()
{
	return " ";
}

string CANBO::get_hten()
{
	return hoten;
}

class CONGNHAN: public CANBO
{
	protected:
		int bac;
	public:
		void Ip_info();
		void Op_info();
		string donvi();
};

string CONGNHAN::donvi()
{
	return "cong nhan";
}

void CONGNHAN::Ip_info()
{
	CANBO::Ip_info();
	cout << "Bac: ";
	cin >> bac;
	cin.ignore();
}

void CONGNHAN::Op_info()
{
	cout << setw(15) << hoten << setw(10) << age << setw(10) << sex << setw(10) << address << setw(10) << bac << endl;
}

class KYSU: public CANBO
{
	protected:
		string nganhdaotao;
	public:
		void Ip_info();
		void Op_info();
		string donvi();
};

string KYSU::donvi()
{
	return "ky su";
}

void KYSU::Op_info()
{
	cout << setw(15) << hoten << setw(10) << age << setw(10) << sex << setw(10) << address << setw(10) << nganhdaotao << endl;
}

void KYSU::Ip_info()
{
	CANBO::Ip_info();
	cout << "Nganh dao tao: ";
	getline(cin, nganhdaotao);
}

class NHANVIEN: public CANBO
{
	protected:
		string congviec;
	public:
		void Ip_info();
		void Op_info();
		string donvi();
};

string NHANVIEN::donvi()
{
	return "nhan vien";
}

void NHANVIEN::Op_info()
{
	cout << setw(15) << hoten << setw(10) << age << setw(10) << sex << setw(10) << address << setw(10) << congviec << endl;
}

void NHANVIEN::Ip_info()
{
	CANBO::Ip_info();
	cout << "Cong viec: ";
	getline(cin, congviec);
}

class QLCB
{
	protected:
		CANBO *CB[100];
		int size;
	public:
		QLCB(int n = 0)
		{
			size = n;
		}
		void Ip_QLCB();
		void Op_QLCB();
		void add_CB();
		void Search_HoTen(string);
		void Exit();
};

void QLCB::Ip_QLCB()
{
	cin.ignore();
	for(int i = 0; i < size; i++)
	{
		cout << "Can bo: ";
		string cb;
		getline(cin,cb);
		if(cb == "cong nhan")
		{
			CONGNHAN *p = new CONGNHAN;
			p->Ip_info();
			CB[i] = p;
		}
		else if(cb == "ky su")
		{
			KYSU *p = new KYSU;
			p->Ip_info();
			CB[i] = p;
		}
		else if(cb == "nhan vien")
		{
			NHANVIEN *p = new NHANVIEN;
			p->Ip_info();
			CB[i] = p;
		}
	}
}

void QLCB::add_CB()
{
	int n;
	cout << "So luong can bo them vao: ";
	cin >> n;
	this->size += n;
	int j = 0;
	for(int i = 0; i < size - 2; i++)
		CB[j++] = CB[i];
	cin.ignore();
	for(int i = size - n; i < size; i++)
	{
		cout << "Can bo: ";
		string cb;
		getline(cin,cb);
		if(cb == "cong nhan")
		{
			CONGNHAN *p = new CONGNHAN;
			p->Ip_info();
			CB[i] = p;
		}
		else if(cb == "ky su")
		{
			KYSU *p = new KYSU;
			p->Ip_info();
			CB[i] = p;
		}
		else if(cb == "nhan vien")
		{
			NHANVIEN *p = new NHANVIEN;
			p->Ip_info();
			CB[i] = p;
		}
	}
}

void QLCB::Op_QLCB()
{
	for(int i = 0; i < size; i++)
		if(CB[i]->donvi() == "cong nhan")
			CB[i]->Op_info();
	for(int i = 0; i < size; i++)
		if(CB[i]->donvi() == "ky su")
			CB[i]->Op_info();
	for(int i = 0; i < size; i++)
		if(CB[i]->donvi() == "nhan vien")
			CB[i]->Op_info();
}

void QLCB::Search_HoTen(string hten)
{
	for(int i = 0; i < size; i++)
		if(hten == CB[i]->get_hten())
			CB[i]->Op_info();
}

void QLCB::Exit()
{
	exit(0);
}

int main()
{
	int n;
	cout << "So luong can bo: ";
	cin >> n;
	QLCB a(n);
	a.Ip_QLCB();
	a.add_CB();
	a.Op_QLCB();
	cout << "Tim kiem ho va ten" << endl;
	cout << "Ho ten: ";
	string hten;
	getline(cin,hten);
	a.Search_HoTen(hten);
	a.Exit();
	return 0;
}
