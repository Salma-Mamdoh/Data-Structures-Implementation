#pragma once
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class ISFull{};
class ISEmpty {};
template<class elementType>
class newStack {
public:
	newStack(int Size);
	~newStack();
	int  Size();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(elementType item);
	void Pop();
	void clearStack();
	elementType Top() const;
	
private:
	int top;
	elementType* maxstack;
	int maxSize;
};

template<class elementType>
inline newStack<elementType>::newStack(int Size)
{
	maxstack = new elementType[Size];
	top = -1;
	maxSize = Size;

}

template<class elementType>
inline newStack<elementType>::~newStack()
{
	delete [] maxstack;
}

template<class elementType>
inline int newStack<elementType>::Size()
{
	return maxSize;
}

template<class elementType>
inline bool newStack<elementType>::IsEmpty() const
{
	return (top == -1);
}

template<class elementType>
inline bool newStack<elementType>::IsFull() const
{
	return (top==maxSize-1);
}

template<class elementType>
inline void newStack<elementType>::Push(elementType item)
{
	if (IsFull())
	{
		cout << "Stack is full";
	}
	else {
		top++;
		maxstack[top] = item;
	}
}

template<class elementType>
inline void newStack<elementType>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is actually full";
	}
	else {
		top--;
	}
}

template<class elementType>
inline elementType newStack<elementType>::Top() const
{
	elementType element = maxstack[top];
	return maxstack[top];
}

template<class elementType>
inline void newStack<elementType>::clearStack() 
{
	top = -1;
}
