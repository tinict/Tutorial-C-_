#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class NhanVien
{
	private:
		string Manv;
		string Hoten;
		int Sdt;
	public:
		NhanVien()
		{
			Manv = "NULL";
			Hoten = "NULL";
			Sdt = 0;
		}
		void Ip_Info();
		void Op_Info();
		string get_MNV();
		int len();
		string get_Hoten();
		NhanVien get_NV();
};

int NhanVien::len()
{
	return Manv.length();
}

string NhanVien::get_Hoten()
{
	return Hoten;
}

string NhanVien::get_MNV()
{
	return Manv;
}

void NhanVien::Ip_Info()
{
	cout << "Manv: ";
	getline(cin,Manv);
	if(Manv.length() != 0)
	{
		cout << "Hoten: ";
		cin >> Hoten;
		cout << "Sdt: ";
		cin >> Sdt;
		cin.ignore();
	}
}

void NhanVien::Op_Info()
{
	cout << Manv << "\t\t" << Hoten << "\t\t" << Sdt << endl;
}

class node
{
	public:
		NhanVien data;
		node *next;
};

class List
{
	private:
		node *f; // first
	public:
		node *createNode(NhanVien x);
		void createList();
		void addHead(NhanVien x);
		void addTail(NhanVien x);
		void Ip_List();
		void Op_List();
		void sort();
		void Search_MSV();
};

node *List::createNode(NhanVien x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void List::createList()
{
	node *f = NULL;
}

void List::addHead(NhanVien x)
{
	if(f == NULL)
		f = createNode(x);
	else if(f != NULL)
	{
		node *temp = createNode(x);
		temp->next = f;
		f = temp;
	}
}

void List::addTail(NhanVien x)
{
	if(f == NULL)
		f = createNode(x);
	else if(f != NULL)
	{
		node *temp = createNode(x);
		node *p = f;
		while(p->next != NULL)
			p = p->next;
		p->next = temp;
	}
}

void List::Ip_List()
{
	NhanVien x;
	while(1)
	{
		x.Ip_Info();
		if(x.len() == 0)
			break;
		addTail(x);
	}
}

void List::Op_List()
{
	node *p = f;
	while(p != NULL)
	{
		p->data.Op_Info();
		p = p->next;
	}
}

void List::sort()
{
	for(node *i = f; i->next != NULL; i = i->next)
	{
		for(node *j = i->next; j != NULL; j = j->next)
		{
			if(i->data.get_Hoten() > j->data.get_Hoten())
			{
				NhanVien t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
}

void List::Search_MSV()
{
	string m;
	cin >> m;
	node *p = f;
	while(p->data.get_MNV() != m)
		p = p->next;
	p->data.Op_Info();
}

int main()
{
	List l;
	l.Ip_List();
	l.sort();
	l.Op_List();	
	l.Search_MSV();
	return 0;
}

