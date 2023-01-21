#include<iostream>
using namespace std;

class Node
{
	
	public:
	int data;
	struct Node *next;
	struct Node *prev;	
	Node()
	{
		data = 10 ;
		next = NULL;
		prev = NULL;
	}
	
	Node(int d)
	{
		this -> data = d;
		this -> next = NULL;
		this -> prev = NULL;
	}
	
	// Traverse a linked list
	void print(Node * head)
	{
		Node * temp = head;
		while(temp != NULL)
		{
			cout << temp->data;
			temp = temp->next ;
			
		}
		
		cout <<endl;
	}
	
	//find length of linked list
	
	int getLength(Node *head)
	{
		int leng = 0 ;
		Node * temp = head ;
		
		while(temp != NULL)
		{
			leng ++ ;
			temp = temp->next ;
		}
		return leng;
	}
	
	void insertAthead(Node *head,int d)
	{
		Node *temp = new Node(d);
		temp -> next = head;
		head -> prev = temp;
		temp -> prev = NULL;
		head = temp;
	}
	
	void insertAttail(Node *tail,int d)
	{
		Node *temp = new Node(d);
		tail -> next = temp;
		temp -> prev = tail;
		temp -> next = NULL;
		tail = temp;

	}
	
	void insertAtanyposition(Node * tail,Node *head, int d, int position)
	{
		Node *temp = head;
		int cnt = 1;
		// insert start
		if(position == 1)
		{
			insertAthead(head, d);
			return;
		}
		
		while( cnt < position-1)
		{
			temp = temp -> next;
			cnt++ ;
		}
		
		// creating node to insert
		Node * toinsert = new Node(d);
		
		toinsert -> next = temp -> next;
		temp -> next -> prev = toinsert -> next;
		temp -> next = toinsert;
		toinsert -> prev = temp;
		
		
		// insert last
		if(temp -> next == NULL)
		{
			insertAttail(tail, d);
			return;
		}
	}
	
};

int main()
{
//	int foo[5] = {5,4,3,2,1};
//	int n = 5;
	
//	for(int i=0; i<n; i++)
//	{
//		cout << foo[i] << end l;
//	}
	
	Node * node1 = new Node(2);
	Node * head = node1 ;
	Node * tail = node1;
	print(head);
	
//	cout << node1->getLength(head);
	
	node1->insertAthead(head,16);
	node1->print(head);

	node1->insertAttail(tail,14);
	node1->print(tail);
	
	
	
}