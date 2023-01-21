#include<iostream>
using namespace std;

class node
{	
	public:
	int data;
	node *next;
	
	node(int d)
	{
		this->data = d;
		this->next = NULL;
	}
	
		
};

void insertAttail(node *tail, int d, int element)
{
	if(tail->next == NULL)
	{
		node *temp = new node(d);
		temp->next = temp;
		tail = temp;
	}
	
	else
	{
		node *cur = tail;
		while(cur->data != element)
		{
			cur = cur->next;
		}
		node *temp = new node(d);
		temp->next = cur->next;
		cur->next = temp;
	}
}



void print(node *tail)
{
	node *temp = tail;
	do
	{
		cout << tail->data << "";
		tail = tail->next;
	}
	while(tail != temp);
	{
	cout << endl;
	}
}

int main()
{
	node * tail = NULL;
	insertAttail(tail,4,5);
	print(tail);
	
}