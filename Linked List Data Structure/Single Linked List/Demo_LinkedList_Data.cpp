#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Info
{
	private:
		int age;
		string s;
		string sdt;
	public:
		void ip_info();
		void op_info();
};

void Info::ip_info()
{
	cin >> age;
	fflush(stdin);
	getline(cin,s);
	getline(cin,sdt);
}

void Info::op_info()
{
	cout << age << " " << s << " " << sdt << endl;
}

class node
{
	public:
		Info data;
		node *next;
};

class Linkedlist
{
	private:
		node *head;
	public:
		node *createNode(Info x);
		void createList();
		void addHead(Info x);
		void addTail(int x);
		void Ip_list();
		void print_List();
};

node *Linkedlist::createNode(Info x)
{
	node *temp = new node();
	temp -> data = x;
	temp -> next = NULL;
	return temp;
}

void Linkedlist::createList()
{
	head = NULL;
}

void Linkedlist::addHead(Info x)
{
	if(head == NULL)
		head = createNode(x);
	else if(head != NULL)
	{
		node *temp = createNode(x);
		temp->next = head;
		head = temp;
	}
}

void Linkedlist::Ip_list()
{
	createList();
	int n;
	Info x;
	cin>>n;
	for(int i = 0 ; i < n; i++)
	{
		x.ip_info();
		addHead(x);
	}
}

void Linkedlist::print_List()
{
	node *p = head;
	while(p != NULL)
	{
		p->data.op_info();
		p = p->next;
	}
}

int main()
{
	Linkedlist f;
	f.Ip_list();
	f.print_List();
	return 0;
}

