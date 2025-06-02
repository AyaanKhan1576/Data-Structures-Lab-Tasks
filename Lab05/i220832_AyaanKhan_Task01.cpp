#include<iostream>
using namespace std;

class Queue
{
public:
	int* arr;
	int front;
	int rear;
	int size;
	int count;

	Queue()
	{
		size = 10;
		arr = new int[size];
		front = 0;
		rear = -1;
		count = 0;
	}

	Queue(int x)
	{
		size = x;
		arr = new int[size];
		front = 0;
		rear = -1;
		count = 0;

	}

	bool is_empty()
	{
		if (count == 0)
		{
			return 1;
		}

		return 0;
	}

	bool is_full()
	{
		if (count >= size)
		{
			return 1;
		}

		return 0;
	}

	void enqueue(int x)
	{
		if (is_full())
		{
			cout << "Queue is full\n";
		}

		rear = (rear + 1) % size;
		count++;
		arr[rear] = x;
	}

	int dequeue()
	{
		if (is_empty())
		{
			cout << "Empty queue\n";
			return -1;
		}

		int final;

		final = arr[front];
		front = (front + 1) % size;
		count--;
		return final;
	}

	int Front()
	{
		if (!is_empty())
		{
			return arr[front];
		}

		cout << "Empty queue\n";
	}

};

//int main()
//{
//	cout << "Initialising queue 1,2,3,4,5\n";
//	Queue q1;
//	q1.enqueue(1);
//	q1.enqueue(2);
//	q1.enqueue(3);
//	q1.enqueue(4);
//	q1.enqueue(5);
//
//	cout << "Testing front: " << q1.Front() << endl;
//	cout << "Testing Is_Empty(): ";
//	if (!q1.is_empty())
//		cout << "Not Empty\n";
//	else
//		cout << "Empty\n";
//
//	cout << "Dequeuing all elements and printing them then testing is empty\n";
//	while (!q1.is_empty())
//	{
//		cout << q1.dequeue() << endl;
//	}
//
//	cout << "Testing Is_Empty(): ";
//	if (!q1.is_empty())
//		cout << "Not Empty\n";
//	else
//		cout << "Empty\n";
//	
//	return 0;
//}