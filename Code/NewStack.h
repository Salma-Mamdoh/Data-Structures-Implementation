#pragma once
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
// guard
#ifndef NEWSTACK_H
#define NEWSTACK_H
const int si = 1e4;
class ISFull {};
class ISEmpty {};
template<class elementType>
class newStack {
public:
	newStack();
	int  StackSize();
	bool IsEmpty() const;
	void Push(elementType item);
	elementType Pop();
	void clearStack();
	elementType Top() const;
	void print();

private:
	elementType top;
	elementType arr[si];
	int Size;
};
#endif
template<class elementType>
inline newStack<elementType>::newStack()
{
	top = -1;
	Size = 0;

}


template<class elementType>
inline int newStack<elementType>::StackSize()
{
	return Size;
}

template<class elementType>
inline bool newStack<elementType>::IsEmpty() const
{
	return (top == -1);
}



template<class elementType>
inline void newStack<elementType>::Push(elementType item)
{
	if (top >= si - 1)cout << "this stack is full \n";
	else {
		top++;
		arr[top] = item;
		Size++;
	}
}

template<class elementType>
inline elementType newStack<elementType>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is actually full";
	}
	else {
		elementType z= arr[top];
		top--;
		Size--;
		return z;
	}
}

template<class elementType>
inline elementType newStack<elementType>::Top() const
{
	return arr[top];
}

template<class elementType>
inline void newStack<elementType>::print()
{
	for (int i = Size-1; i >=0 ; i--) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template<class elementType>
inline void newStack<elementType>::clearStack()
{
	top = -1;
	Size = 0;
}
