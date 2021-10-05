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
		void Ip_Info();
		void Op_Info();
};

void NhanVien::Ip_Info()
{
	cin.ignore();
	cout << "Manv: ";
	cin >> Manv;
	cout << "Hoten: ";
	cin >> Hoten;
	cout << "Sdt: ";
	cin >> Sdt;
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
	int n;
	NhanVien x;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		x.Ip_Info();
		addTail(x);
	}
}

void List::Op_List()
{
	while(f != NULL)
	{
		f->data.Op_Info();
		f = f->next;
	}
}

int main()
{
	List l;
	l.Ip_List();
	l.Op_List();
	return 0;
}

