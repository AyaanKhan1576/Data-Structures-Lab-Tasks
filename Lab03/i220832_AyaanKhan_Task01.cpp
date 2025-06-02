#include<iostream>
using namespace std;

class Stack
{
public:
	int arr[1000];
	int top;

	Stack()
	{
		top = -1;
		//for (int i = 0; i < 1000; i++)
		//{
		//	arr[i] = -1;
		//}
	}

	bool isEmpty()
	{
		if (top <= -1)
		{
			return 1;
		}

		return 0;
	}

	void push(int x)
	{
		if (top >= 999)
		{
			cout << "Stack full\n";
		}

		top++;
		arr[top] = x;
	}

	int pop()
	{
		if (!isEmpty())
		{
			int temp = arr[top];
			top--;
			return temp;
		}
	}

	int peek()
	{
		if (!isEmpty())
		{
			cout << arr[top] << endl;
			return arr[top];
		}

		cout << "Stack is empty\n";
	}
};

//int main()
//{
//	Stack stack;
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    stack.push(4);
//    stack.push(5);
//	cout << "Values have been pushed. now peeking and popping\n";
//    while (!stack.isEmpty())
//    {
//		stack.peek();
//        stack.pop();
//    }
//}