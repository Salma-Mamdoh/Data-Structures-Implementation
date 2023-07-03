#pragma once
#include<bits/stdc++.h>
using namespace std;
// guard
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
template<typename T>
class DoublyLinkedList
{
private:
	struct node {
		T data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
	int count; // to count num of elements
public:
	DoublyLinkedList();
	void insertAtHead(T element);
	void insertAtTail(T element);
	void insertAt(T element, int index);
	void insertAfter(node* Prev_node , T data);
	void removeAtHead();
	void removeAtTail();
	void removeAt(int index);
	T retrieveAt(int index);
	void replaceAt(T newElement, int index);
	bool isExist(T element);
	bool isItemAtEqual(T element, int index);
	void Swap(int firstItemIdx, int secondItemIdx);
	void reverse();
	bool  isEmpty();
	int doubleLinkedListSize();
	void  clear();
	void  forwardTraversal();
	void  backwardTraversal();

};
#endif

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	count = 0;
	head = tail = NULL;
}

template<typename T>
inline void DoublyLinkedList<T>::insertAtHead(T element) // o(1)
{
	node* newnode = new node();
	newnode->data = element;
	if (count == 0) {
		head = tail = newnode;
		newnode->next = newnode->prev = NULL;
	}
	else {
		newnode->next = head;
		newnode->prev = NULL;
		head->prev = newnode;
		head = newnode;
	}
	count++;
}

template<typename T>
inline void DoublyLinkedList<T>::insertAtTail(T element) //o(1)
{
	node* newnode = new node();
	newnode->data = element;
	if (count == 0) {
		tail = head = newnode;
		newnode->next = newnode->prev = NULL;
	}
	else {
		newnode->next = NULL;
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	count++;
}

template<typename T>
inline void DoublyLinkedList<T>::insertAt(T element, int index) //o(n)
{
	if (index<0 || index>count)cout << "This Postion is Out Of Range\n";
	else {
		if (index == 0)insertAtHead(element);
		else if (index == count)insertAtTail(element);
		else {
			node* newnode = new node();
			newnode->data = element;
			node* curr = head;
			for (int i = 1; i < index; i++) {
				curr = curr->next;
			}
			insertAfter(curr, element);

			count++;
		}
	}
}

template<typename T>
inline void DoublyLinkedList<T>::insertAfter(node* Prev_node, T data) //o(1)
{
	if (Prev_node == NULL) cout << "There are no Pervious Node\n";
	else {
		node* newnode = new node();
		newnode->data = data;
		newnode->next = Prev_node->next;
		Prev_node->next = newnode;
		newnode->prev = Prev_node;
		if (newnode->next != NULL) {
			newnode->next->prev = newnode;
		}
	}
}

template<typename T>
inline void DoublyLinkedList<T>::removeAtHead() // o(1)
{
	if (isEmpty()) cout << "This Doubly Linked List is already Empty\n";
	else {
		node* curr = head;
		head = curr->next;
		head->prev = NULL;
		delete[] curr;
		count--;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::removeAtTail() // o(1)
{
	if (isEmpty()) cout << "This Doubly Linked List is already Empty\n";
	else {
		node* curr = tail;
		tail = curr->prev;
		tail->next = NULL;
		delete[] curr;
		count--;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::removeAt(int index) // o(n)
{
	if (index<0 || index>count)cout << "This Postion is Out Of Range\n";
	else {
		if (index == 0)removeAtHead();
		else if (index == count)removeAtTail();
		else {
			node* curr = head;
			for (int i = 1; i < index; i++) {
				curr = curr->next;
			}
			curr->next = curr->next->next;
			curr->next->prev = curr;
			count--;
		}
	}
}

template<typename T>
inline T DoublyLinkedList<T>::retrieveAt(int index) // o(n)
{
	if (index<0 || index>count)cout << "This Position is Out Of Range\n";
	else {
		node* curr = head;
		for (int i = 1; i <= index; i++) {
			curr = curr->next;
		}
		return curr->data;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::replaceAt(T newElement, int index) // o(n)
{
	if (index<0 || index>count)cout << "This Position is Out Of Range\n";
	else {
		node* curr = head;
		for (int i = 1; i <= index; i++) {
			curr = curr->next;
		}
		curr->data = newElement;
	}
	
}

template<typename T>
inline bool DoublyLinkedList<T>::isExist(T element) // o(n)
{
	node* curr = head;
	while (curr != NULL) {
		if (curr->data == element) {
			return true;
		}
		else {
			curr = curr->next;
		}
	}
	return false;
}

template<typename T>
inline bool DoublyLinkedList<T>::isItemAtEqual(T element, int index) // o(n)
{
	node* curr = head;
	for (int i = 1; i <= index; i++) {
		curr = curr->next;
	}
	if (curr->data == element)return true;
	else return false;
}

template<typename T>
inline void DoublyLinkedList<T>::Swap(int firstItemIdx, int secondItemIdx)
{
	if (firstItemIdx<0 || firstItemIdx>count || secondItemIdx<0 || secondItemIdx>count)cout << "INValid indexes\n";
	else if (firstItemIdx == secondItemIdx)cout << "The 2 indexes for the same node\n";
	else {
		node* fnode = head;
		node* snode = head;
		for (int i = 1; i <= firstItemIdx; i++) {
			fnode = fnode->next;
		}
		for (int i = 1; i <= secondItemIdx; i++) {
			snode = snode->next;
		}
		if (head == fnode)head = snode;
		if (head == snode)head = fnode;
		if (fnode->prev != NULL)fnode->prev->next = snode;
		if (snode->prev != NULL)snode->prev->next = fnode;
		if (fnode->next != NULL)fnode->next->prev = snode;
		if (snode->next != NULL)snode->next->prev = fnode;
		node* temp = fnode->next;
		fnode->next = snode->next;
		snode->next = temp;
		temp = fnode->prev;
		fnode->prev = snode->prev;
		snode->prev = temp;
	

	}


}

template<typename T>
inline void DoublyLinkedList<T>::reverse()//o(n)
{
	node* curr = head;
	node* leftcurr = tail;
	int x = 1;
	while (x<=count/2) {
		swap(curr->data, leftcurr->data);
		curr = curr->next;
		leftcurr = leftcurr->prev;
		x++;
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::isEmpty() // o(1)
{
	return (count==0);
}

template<typename T>
inline int DoublyLinkedList<T>::doubleLinkedListSize()  // o(1)
{
	return count;
}

template<typename T>
inline void DoublyLinkedList<T>::clear() // o(n)
{
	node* curr = new node();
	while (head != NULL) {
		count--;
		curr = head;
		head = head->next;
		delete curr;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::forwardTraversal() //Print from head to tail o(n)
{
	if (count == 0)cout << "This List is Empty\n";
	else {
		node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
}

template<typename T>
inline void DoublyLinkedList<T>::backwardTraversal() //Print from tail to head o(n)
{
	if (count == 0)cout << "This List is Empty\n";
	else {
		node* curr = tail;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->prev;
		}
		cout << "\n";
	}
}
