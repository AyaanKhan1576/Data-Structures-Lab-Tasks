#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(T x)
	{
		data = x;
		next = NULL;
	}

	void setData(T x)
	{
		data = x;
	}

	void setNext(Node* ptr)
	{
		next = ptr;
	}

	T getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}
};

template <typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	Node<T>* current;
	int size;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		current = NULL;
		size = 0;
	}

	bool is_empty()
	{
		if (front == NULL)
		{
			return 1;
		}

		return 0;
	}

	void enqueue(T item)
	{
		Node<T>* ptr = new Node<T>(item);

		if (is_empty())
		{
			front = ptr;
			rear = ptr;
			return;
		}

		rear->setNext(ptr);
		rear = ptr;
		size++;
	}

	Queue(Queue<T>& ptr)
	{
		Node<T>* temp = ptr.front;
		front = NULL;
		rear = NULL;
		current = NULL;
		size = ptr.size;

		while (temp != NULL)
		{
			enqueue(temp->data);
			temp = temp->next;
		}
	}

	Queue& operator=(const Queue<T>& ptr) 
	{
		Node<T>* temp = ptr.front;
		front = NULL;
		rear = NULL;
		current = NULL;
		size = ptr.size;

		while (temp != NULL)
		{
			enqueue(temp->data);
			temp = temp->next;
		}

		return *this;
	}

	T Front()
	{
		if (is_empty())
			return -1;

		return front->getData();
	}

	int size2()
	{
		if (is_empty()) {
			return 0;
		}

		int count = 0;
		Node<T>* current = front;

		while (current != nullptr) {
			count++;
			current = current->next; 
		}

		return count;
	}

	T dequeue()
	{
		if (is_empty())
		{
			return -1;
		}

		T item_temp;
		Node<T>* temp = front;
		item_temp = temp->getData();
		front = front->next;
		delete temp;
		return item_temp;
	}

	void clear()
	{
		if (is_empty())
			return;

		while (!is_empty())
		{
			dequeue();
		}
	}

	void display()
	{
		Node<T>* ptr = front;
		while (!is_empty())
		{
			cout << Front() << endl;
			front = front->next;
		}
		front = ptr;
	}

	//T return_middle()
	//{
	//	int size3 = size / 2;
	//	int count = 0;

	//	while (count < size3)
	//	{
	//		count++;
	//		dequeue();
	//	}

	//	return Front();
	//}

	T return_middle()
	{
		Queue* q2 = new Queue(*this);
		Queue* temp = new Queue(*this);
		
		while (!q2->is_empty())
		{
			q2->dequeue();
			if (!q2->is_empty())
			{
				q2->dequeue();
				dequeue();
			}
		}

		int final = Front();
		*this = *temp;
		front = temp->front;
		rear = temp->rear;
		return final;
	}

};


int main()
{

	Queue<int> q1;
	cout << "Inserting values in Queue\n";
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	cout << "Testing Front: " << q1.Front();
	cout << endl;
	cout << "Displaying queue\n";
	q1.display();
	cout << "Finding middle value: ";
	//q1.return_middle();
	cout << q1.return_middle() << endl;
	cout << "Dequeing once. New queue\n";
	q1.dequeue();
	q1.display();


	
	return 0;
}