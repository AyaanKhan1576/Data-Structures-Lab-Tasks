#pragma once
#include<iostream>
#include<cstring>
#include<string>
using namespace std;


template<class T>
class Node
{
public:
    T data;
    Node* next;

    Node()
    {
        data = -1;
        next = NULL;
    }

    Node(T x, Node* y)
    {
        data = x;
        next = y;
    }
};

template<class T>
class Stack
{
public:
    Node<T>* top;
    Node<T>* current;

    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return 1;

        return 0;
    }

    void push(const T DataItem)
    {
        Node<T>* ptr = new Node<T>;
        Node<T>* ptr2 = new Node<T>;
        ptr->data = DataItem;
        ptr2 = top;
        top = ptr;
        top->next = ptr2;
    }

    T peek()
    {
        if (isEmpty())
            return -1;

        return top->data;
    }

    void pop()
    {
        Node<T>* ptr = new Node<T>;
        ptr = top;
        top = top->next;
        delete ptr;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    ~Stack()
    {
        clear();
    }
};

string convertDecToBin(int val1)
{
    Stack<int> stack2;
    int temp = val1;
    string final;
    int val2;
    while (temp >= 1)
    {
        val2 = temp % 2;
        stack2.push(val2);
        temp /= 2;
    }

    while (!stack2.isEmpty())
    {

        final.append(std::to_string(stack2.peek()));
        stack2.pop();
    }

    return final;
}

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << "Values have been pushed. now peeking and popping with Pointer based implementation\n";
    while (!stack.isEmpty())
    {
        cout << stack.peek() << endl;
        stack.pop();
    }

    int val1;
    cout << "\nTask 03\n";
    cout << "Enter your value to convert to binary\n";
    cin >> val1;

    cout << "Decimal Value: " << val1 << endl;
    cout << "Binary Value: " << convertDecToBin(val1) << endl;
    

    return 0;
}