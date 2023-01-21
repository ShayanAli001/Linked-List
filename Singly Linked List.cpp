#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(int d)
	{
		data = d;
		next = nullptr;
	}
};
class LinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void insertFirst(int d)
	{
		Node* temp = new Node(d);
		if (head==nullptr)
		{
			head = temp;
			head->next = nullptr;
		}
		else
		{
			temp->next = head;
			head = temp;

		}
	}
	void insertLast(int d)
	{
		if (head == nullptr)
		{
			insertFirst(d);
		}
		else
		{
			Node* newNode = new Node(d);
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = nullptr;
		}
	}
	void insertSpecific(int d)
	{
		int index, count = 0;
		cout << "Enter the index at which you want to add node: ";
		cin >> index;
		while (index < 0)
		{
			cout << "Invalid Index.\n";
			cout << "Enter index again: ";
			cin >> index;
		}
		Node* newNode = new Node(d);
		Node* temp = head;
		while (count != index-1)
		{

			count++;
			temp = temp->next;
		}
		if (head == nullptr)
		{
			insertFirst(d);
		}
		else
		{
			Node* temp2 = nullptr;
			Node* pre = nullptr;
			pre = temp;
			temp2 = temp->next;
			temp = newNode;
			pre->next = temp;
			temp->next = temp2;
		}

	}
	int countLength()
	{
		Node* temp = head;
		int count = 0;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void displayList()
	{
		Node* temp = head;
		while (temp!=nullptr)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << endl;
	}
};


int main()
{
	LinkedList l1;
	l1.insertFirst(12);
	l1.insertFirst(11);
	l1.insertFirst(10);
	l1.insertFirst(9);
	l1.insertLast(13);
	l1.insertLast(14);

	l1.displayList();
	cout << "Total Lists are: " << l1.countLength() << endl;
	l1.insertSpecific(20);
	cout << endl << endl;

	l1.displayList();
	cout << "Total Lists are: " << l1.countLength() << endl;

}