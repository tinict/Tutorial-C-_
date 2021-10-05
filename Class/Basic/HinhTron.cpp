#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Hinhtron
{
	private:
		double x,y,R;
	public:
		Hinhtron()
		{
			x = y = R = 0;
		}
		void ip_ht();
		void op_ht();
		double get_x();
		double get_y();
		double get_R();
};

void Hinhtron::ip_ht()
{
	cout << "Hoanh do: ";
	cin >> x;
	cout << "Tung do: ";
	cin >> y;
	cout << "Ban kinh hinh tron: ";
	cin >> R;
}

void Hinhtron::op_ht()
{
	if(y == 0 and x != 0)
		cout << "(" << x << " , " << y <<")" << " , " << "R = " << R << endl;
}

double Hinhtron::get_x()
{
	return x;
}

double Hinhtron::get_y()
{
	return y;
}

double Hinhtron::get_R()
{
	return R;
}

class node
{
	public:
		Hinhtron data;
		node *next;
};

class List
{
	private:
		node *f;
	public:
		node *createNode(Hinhtron x);
		void createList();
		void addTail(Hinhtron x);
		void ip_list();
		void op_list();
};

node *List::createNode(Hinhtron x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void List::createList()
{
	f = NULL;
}

void List::addTail(Hinhtron x)
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

void List::ip_list()
{
	char c;
	Hinhtron x;
	do
	{
		x.ip_ht();
		c = getch();
		cin.ignore();
		addTail(x);
	}
	while(c != 27);
}

void List::op_list()
{
	node *p = f;
	while(p != NULL)
	{
		p->data.op_ht();
		p = p->next;	
	}	
}

int main()
{
	List l;
	l.ip_list();
	l.op_list();
	return 0;
}

