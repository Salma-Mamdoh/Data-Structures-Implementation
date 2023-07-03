#pragma once
#include<bits/stdc++.h>
using namespace std;
// guard
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
template<typename T>
class CircularLinkedList
{
private:
	struct node {
		T data;
		node* next;
	};
	int count;
	node* tail;
	node* head;
public:
	CircularLinkedList();
	void insertAtHead(T element);
	void insertAtEnd(T element);
	void insertAfter(node* Prev_node, T data);
	void insertAt(T element, int index);
	void removeAtHead();
	void removeAtEnd();
	void removeAt(int index);
	T retrieveAt(int index);
	void replaceAt(T newElement, int index);
	bool isExist(T element);
	bool isItemAtEqual(T element, int index);
	void Swap(int firstItemIdx, int secondItemIdx);
	bool isEmpty();
	int circularLinkedListSize();
	void clear();
	void print();
};
#endif

template<typename T>
inline CircularLinkedList<T>::CircularLinkedList()
{
	count = 0;
	tail =NULL;
}

template<typename T>
inline void CircularLinkedList<T>::insertAtHead(T element) // o(1)
{
	
	node* newnode = new node;
	newnode->data = element;
	if (isEmpty()) {
		tail = head = newnode;
		tail->next = tail;
	}
	else {
		newnode->next = tail->next;
		tail->next = newnode;
	}
	count++;
}

template<typename T>
inline void CircularLinkedList<T>::insertAtEnd(T element) // o(1)
{
	node* newnode = new node();
	newnode->data = element;
	if (isEmpty()) {
		tail = newnode;
		tail->next = tail;
	}
	else {
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
	count++;
}

template<typename T>
inline void CircularLinkedList<T>::insertAfter(node* Prev_node, T data) //o(1)
{
	if (Prev_node == NULL)cout << "There are no Previous node\n";
	else {
		node* newnode = new node();
		newnode->data = data;
		newnode->next = Prev_node->next;
		Prev_node->next = newnode;
	}
}

template<typename T>
inline void CircularLinkedList<T>::insertAt(T element, int index) // o(n)
{
	if (index<0 || index>count)cout << "This Index Is Out Of Range\n";
	else {
		if (index == 0)insertAtHead(element);
		else if (index == count)insertAtEnd(element);
		else {
			node* newnode = new node();
			newnode->data = element;
			node* curr = tail->next;
			for (int i = 1; i < index; i++) {
				curr = curr->next;
			}
			insertAfter(curr, element);
			count++;
		}
	}
}

template<typename T>
inline void CircularLinkedList<T>::removeAtHead() //o(1)
{
	if (isEmpty())cout << "This List is already Empty\n";
	else {
		if (tail->next == tail) {
			delete[] tail;
			tail = NULL;
		}
		else {
			node* curr = tail->next;
			tail->next = curr->next;
			delete[] curr;
		}
		count--;
	}
}

template<typename T>
inline void CircularLinkedList<T>::removeAtEnd() //o(n)
{
	if (isEmpty())cout << "This List is already Empty\n";
	else {
		if (tail->next == tail) {
			delete[] tail;
			tail = NULL;
		}
		else {
			node* curr = tail->next;
			while (curr->next != tail) {
				curr = curr->next;
			}
			curr->next = tail->next;
			tail = curr;

		}
		count--;
	}
}

template<typename T>
inline void CircularLinkedList<T>::removeAt(int index)
{
	if (index<0 || index>count)cout << "This index is Out of Range\n";
	else {
		if (index == 0)removeAtHead();
		else if (index == count)removeAtEnd();
		else {
			if (tail->next == tail) {
				delete[] tail;
				tail = NULL;
			}
			else {
				node* curr = tail->next;
				node* postcurr=curr->next;
				while (index > 2) {
					curr = curr->next;
					postcurr = curr->next;
					index--;
				}
				curr->next = postcurr->next;
				if (postcurr == tail) {
					tail = postcurr;
					delete postcurr;
				}

			}
			count--;
		}
	}
}

template<typename T>
inline T CircularLinkedList<T>::retrieveAt(int index) //o(n)
{
	if (index<0 || index>count)cout << "This index is out of Range\n";
	else {
		node* curr = tail->next;
		for (int i = 1; i <= index; i++) {
			curr = curr->next;
		}
		return curr->data;
	}
}

template<typename T>
inline void CircularLinkedList<T>::replaceAt(T newElement, int index) //o(n)
{
	if (index<0 || index>count)cout << "This index is out of Range\n";
	else {
		node* curr = tail->next;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		curr->data = newElement;
	}
}

template<typename T>
inline bool CircularLinkedList<T>::isExist(T element) //o(n)
{
	node* curr = tail->next;
	do {
		if (curr->data == element) {
			return true;
		}
		else {
			curr = curr->next;
		}
	} while (curr != tail->next);
	return false;
}

template<typename T>
inline bool CircularLinkedList<T>::isItemAtEqual(T element, int index) // o(n)
{
	if (index<0 || index>count)cout << "This index is out of Range\n";
	else {
		node* curr = tail->next;
		for (int i = 1; i <= index; i++) {
			curr = curr->next;
		}
		if (curr->data == element) {
			return true;
		}
		else {
			return false;
		}
	}
	
}

template<typename T>
inline void CircularLinkedList<T>::Swap(int firstItemIdx, int secondItemIdx)
{
	if (firstItemIdx<0 || firstItemIdx>count || secondItemIdx<0 || secondItemIdx>count)cout << "INValid indexes\n";
	else if (firstItemIdx == secondItemIdx)cout << "The 2 indexes for the same node\n";
	else {
		node* fnode = tail->next;
		node* prevfnode = tail->next;
		node* snode = tail->next;
		node* prevsnode = tail->next;
		for (int i = 1; i < firstItemIdx; i++) {
			fnode = fnode->next;
			prevfnode = fnode;
		}
		fnode = fnode->next;
		for (int i = 1; i < secondItemIdx; i++)
		{
			snode = snode->next;
			prevsnode = snode;
		}
		snode = snode->next;
		if (prevfnode != NULL) {
			prevfnode->next = snode;
		}
		if (prevsnode != NULL) {
			prevsnode->next = fnode;
		}
		node* temp = snode->next;
		snode->next = fnode->next;
		fnode->next = temp;
		
	}
}

template<typename T>
inline bool CircularLinkedList<T>::isEmpty()
{
	return (count==0);
}

template<typename T>
inline int CircularLinkedList<T>::circularLinkedListSize()
{
	return count;
}

template<typename T>
inline void CircularLinkedList<T>::clear()
{
	if (tail != NULL) {
		node* temp, * current;
		current = tail->next;
		while (current != tail) {
			temp = current->next;
			free(current);
			current = temp;
		}
		free(tail);
		tail = NULL;
	}
	count = 0;
}

template<typename T>
inline void CircularLinkedList<T>::print()
{
	if (isEmpty())cout << "This List is Empty\n";
	else {
		node* curr =tail->next;
		do {
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != tail->next);
		cout << "\n";
	}
}
