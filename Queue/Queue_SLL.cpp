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

class Queue
{
	private:
		node *f;
	public:
		node *CreateNode(int x);
		void CreateList();
		void EnQueue(int x);
		int Front();
		void DeQueue();
		bool IsEmpty();
};

node *Queue::CreateNode(int x)
{
	node *temp = new node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void Queue::CreateList()
{
	f = NULL;
}

void Queue::EnQueue(int x)
{
	if(f == NULL)
		f = CreateNode(x);
	else if(f != NULL)
	{
		node *temp = CreateNode(x);
		node *p = f;
		while(p->next != NULL)
			p = p->next;
		p->next = temp;	
	}		
}

int Queue::Front()
{
	int x = f->data;
	f = f->next;
	return x;
}

void Queue::DeQueue()
{
	node *p = f;
	node *temp = p->next;
	delete f;
	f = temp;
}

bool Queue::IsEmpty()
{
	if(f == NULL)
		return false;
	return true;
}

int main()
{
	Queue q;
	cout << q.IsEmpty() << endl;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	//q.DeQueue();
	cout << q.Front();
	cout << q.Front();
	//cout << q.Front();
	return 0;
}

