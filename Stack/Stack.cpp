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

class Stack
{
	private:
		node *f;
	public:
		node *createNode(int x);
		void createList();
		void Push(int x);
		int Top();
		void Pop();
		bool IsEmty();
		bool IsFull(int capacity = 0);
		int Size();
};

node *Stack::createNode(int x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void Stack::createList()
{
	f = NULL;	
}

void Stack::Push(int x)
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

int Stack::Top()
{
	int t = f->data;
	f = f->next;
	return t;
}

void Stack::Pop()
{
	node *p = f;
	node *temp = p->next;
	delete f;
	f = temp;
}

bool Stack::IsEmty()
{
	if(f == NULL)
		return false;
	return true;
} 

int Stack::Size()
{
	node *p = f;
	int count = 0;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

bool Stack::IsFull(int capacity)
{
	if(Size() == capacity)
		return true;
	return false;
}

int main()
{
	Stack l;
	l.Push(0);
	l.Push(1);
	cout << l.Top() << endl;
	cout << l.Top();
	return 0;
}

