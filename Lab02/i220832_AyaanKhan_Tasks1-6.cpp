#pragma once
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
		next = NULL;
	}

	Node(int x)
	{
		data = x;
		next = NULL;
	}

	void setData(int x)
	{
		data = x;
	}

	void setNext(Node* ptr)
	{
		next = ptr;
	}

	int getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}
};


class SLinkedList
{

public:
	Node* head;
	Node* current;

	SLinkedList()
	{
		head = NULL;
		current = NULL;
	}

	void insert(int x)
	{
		Node* ptr = new Node;
		ptr->data = x;

		if (head == NULL)
		{
			head = ptr;
			return;
		}

		current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = ptr;
	}

	void insertAtHead(int x)
	{
		Node* ptr = new Node;
		ptr->data = x;
		ptr->next = head;
		head = ptr;
	}

	bool isEmpty()
	{
		if (head == NULL)
			return 1;

		return 0;
	}

	//Q5: isFull() is not needed as list has no fixed size or capacity and new element can always be added

	void update(int val1, int val2)
	{
		current = head;

		while (current != NULL)
		{
			if (current->data == val1)
			{
				current->data = val2;
				return;
			}

			current = current->next;
		}
	}

	void InsertAtIndex(int x, int idx)
	{
		Node* ptr = new Node;
		ptr->data = x;

		if (idx < 0)
		{
			return;
		}

		if (idx == 0)
		{
			ptr->next = head;
			head = ptr;
		}

		int count = 0;
		current = head;

		while (current != NULL && count < idx)
		{
			count++;
			current = current->next;
		}

		if (!current)
		{
			return;
		}

		ptr->next = current->next;
		current->next = ptr;
	}

	void remove(int x)
	{
		Node* previous = NULL;
		current = head;

		int count = 0;

		while (current != NULL)
		{
			if (current->data == x)
				break;

			previous = current;
			current = current->next;
			count++;
		}

		if (current != NULL && previous == NULL)
		{
			head = current->next;
			delete current;
		}

		else if (current != NULL && previous != NULL)
		{
			previous->next = current->next;
			delete current;
		}
	}

	void print()
	{
		current = head;

		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};
//
//Node* swapAdjacentNodes(Node* head)
//{
//	Node* previous = NULL;
//	Node* current = head;
//	Node* ptr = current->next;
//
//	if (!head || head->next == NULL) {
//		return head;
//	}
//
//	Node* next_ptr = NULL;
//	Node* temp = NULL;
//
//	while (current != NULL && current->next != NULL)
//	{
//		next_ptr = current->next;
//		temp = next_ptr->next;
//		current->next = temp;
//		next_ptr->next = current;
//
//		if (previous == NULL)
//		{
//			head = next_ptr;
//		}
//
//		if (previous != NULL)
//		{
//			previous->next = next_ptr;
//		}
//
//		previous = current;
//		current = temp;
//	}
//
//	return ptr;
//}

Node* swapAdjacentNodes(Node* head) 
{
	if (!head || !head->next) 
	{
		return head;
	}

	Node* newHead = head->next;
	Node* current = head;
	Node* previous = NULL;

	while (current && current->next) 
	{
		Node* next = current->next;
		Node* temp = next->next;
		next->next = current;
		current->next = temp;

		if (previous) 
		{
			previous->next = next;
		}

		previous = current;
		current = temp;
	}
	//cout << endl;
	head = newHead;
	//cout << head->data;
	return newHead;

}

void search(int x, Node* head)
{
	Node* current = new Node;
	current = head;
	//int count = 0;
	bool flag = 0;

	while (current != NULL)
	{
		if (current->data == x)
			flag = 1;

		current = current->next;
		//count++;
	}

	if (!flag)
	{
		cout<<"Number "<< x << " not found!\n";
	}
	else
	{
		cout << "Number found!: " << x << endl;
	}
}

SLinkedList groupOdds(SLinkedList& list3)
{
	Node* current = new Node;
	Node* prev = new Node;
	current = list3.head;
	prev = list3.head;
	SLinkedList odd;
	SLinkedList even;
	SLinkedList final;

	while (current != NULL)
	{
		if (current->data % 2 == 1)
		{
			odd.insert(current->data);
		}
		else
		{
			even.insert(current->data);
		}
		current = current->next;
	}

	current = odd.head;
	while (current != NULL)
	{
		final.insert(current->data);
		current = current->next;
	}

	current = even.head;
	while (current != NULL)
	{
		final.insert(current->data);
		current = current->next;
	}

	return final;
	
}

void checkPalindrome(SLinkedList list4)
{
	Node* start = list4.head;
	Node* current = list4.head;
	Node* end;
	SLinkedList temp;

	while (current != NULL)
	{
		temp.insertAtHead(current->data);
		current = current->next;
	}

	bool flag = 1;
	current = list4.head;
	end = temp.head;
	//cout << "temp";
	//temp.print();

	while (current->data == end->data)
	{
		int val1 = current->data;
		int val2 = end->data;
		if (current->next == NULL || end->next == NULL)
		{
			cout << "It is a palindrome\n";
			return;
		}

		current = current->next;
		end = end->next;
	}

	cout << "It is not a palindrome\n";
}

void reverseList(SLinkedList& list)
{
	Node* start = list.head;
	Node* current = list.head;
	Node* end;
	SLinkedList temp;

	while (current != NULL)
	{
		temp.insertAtHead(current->data);
		current = current->next;
	}

	current = list.head;
	end = temp.head;

	while (current != NULL)
	{
		current->data = end->data;
		current = current->next;
		end = end->next;
	}
}

void moveTailtoHead(SLinkedList& list)
{
	Node* current = list.head;
	Node* end;

	while (current->next->next != NULL)
	{
		current = current->next;
	}

	end = current->next;
	current->next = NULL;
	list.insertAtHead(end->data);
}



int main()
{
	//Task 01
	cout << "Task 1\n";
	SLinkedList list1;
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	list1.insert(4);
	list1.insert(5);
	list1.print();

	cout << endl;

	list1.head = swapAdjacentNodes(list1.head);
	list1.print();
	cout << endl;
	

	//Task 02
	cout << "Task 2\n";
	SLinkedList list2;
	list2.insert(1);
	list2.insert(2);
	list2.insert(3);
	list2.insert(4);
	list2.insert(5);
	list2.print();

	search(3, list2.head);
	search(6, list2.head);
	cout << endl;


	//Task 03
	cout << "Task 03\n";
	SLinkedList list3;
	list3.insert(1);
	list3.insert(2);
	list3.insert(3);
	list3.insert(4);
	list3.insert(5);
	list3.print();
	cout << endl;

	SLinkedList list4;
	list4 = groupOdds(list3);
	list4.print();
	cout << endl;


	//Task 04
	cout << "Task4\n";
	SLinkedList list5;
	list5.insert(1);
	list5.insert(2);
	list5.insert(3);
	list5.insert(4);
	list5.insert(5);
	list5.print();
	checkPalindrome(list5);

	cout << endl;

	SLinkedList list6;
	list6.insert(1);
	list6.insert(2);
	list6.insert(3);
	list6.insert(2);
	list6.insert(1);
	list6.print();
	checkPalindrome(list6);
	cout << endl;


	//Task 05
	cout << "Task 05\n";
	SLinkedList list7;
	list7.insert(1);
	list7.insert(2);
	list7.insert(3);
	list7.insert(4);
	list7.insert(5);
	//list7.print();

	cout << endl;

	reverseList(list7);
	list7.print();

	
	//Task 06
	cout << "\nTask 06\n";
	SLinkedList list8;
	list8.insert(1);
	list8.insert(2);
	list8.insert(3);
	list8.insert(4);
	list8.insert(5);
	list8.print();

	cout << endl;

	moveTailtoHead(list8);
	list8.print();

	return 0;
}


