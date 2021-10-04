#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class node
{
	public:
		int data;
		node *next;
};

class Linkedlist
{
	private:
		node *head;
	public:
		node *createNode(int x);
		void createList();
		void addHead(int x);
		void addTail(int x);
		void Ip_list();
		void print_List();
};

node *Linkedlist::createNode(int x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void Linkedlist::createList()
{
	head = NULL;
}

void Linkedlist::addHead(int x)
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
	int n,x;
	cin>>n;
	for(int i = 0 ; i < n; i++)
	{
		cin >> x;
		addHead(x);
	}
}

void Linkedlist::print_List()
{
	node *p = head;
	while(p != NULL)
	{
		cout << p->data << " ";
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

