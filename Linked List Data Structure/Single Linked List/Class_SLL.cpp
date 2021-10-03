#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
	private:
		int data; // xet kieu du lieu la so nguyen
		Node *next;
	public:
		Node *f =NULL;
		Node *createNode(int x); // Tao 1 node 
		Node *addHead(int x);
		Node *addTail(int x);
		Node *Ip_List();
		void print_List();
};

Node *Node::createNode(int x) // Tao 1 node 
{
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

Node *Node::addHead(int x)
{
	if(f == NULL)
	{
		f = createNode(x);
		return f;
	}
	else if(f != NULL)
	{
		Node *temp = createNode(x);
		temp->next = f;
		f = temp;
		return f;
	}	
}

Node *Node::addTail(int x)
{
	if(f == NULL)
	{
		f = createNode(x);
		return f;
	}
	else if(f != NULL)
	{
		Node *p = f;
		Node *temp = createNode(x);
		while(p->next != NULL)
			p=p->next;
		p->next = temp;
		p = temp;
		return f;
	}
}

Node *Node::Ip_List()
{
	int n,x;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		cin >> x;
		f = addTail(x);
	}
	return f;
}

void Node::print_List()
{
	Node *p = f;
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	Node f;
	f.Ip_List();
	f.print_List();
	return 0;
}

