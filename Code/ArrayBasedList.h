#pragma once
#include<bits/stdc++.h>
using namespace std;
// guard
#ifndef ARRAYBASEDLIST_H
#define ARRAYBASEDLIST_H

template<class elementType>
class  arrayBasedList
{
private:
    int* arr;
    int arrSize;
    int maxSize;
public:
    arrayBasedList(int size = 5);
    ~arrayBasedList();
    void insert(elementType item);
    void insertAt(elementType element, int index);
    elementType retrieveAt(int index);
    void removeAt(int index);
    void replaceAt(elementType newElement, int index);
    bool isItemAtEqual(elementType element, int index);
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void clear();
    void print();
};
#endif
template<class elementType>
arrayBasedList< elementType>::arrayBasedList(int size)
{
    if (size <= 0)
    {
        cout << " Wrong Size, will initialize with 5 " << endl;
        maxSize = 5;
    }
    else
        maxSize = size;

    arrSize = 0;
    arr = new elementType[maxSize];
}

template<class elementType>
arrayBasedList< elementType>::~arrayBasedList()
{
    delete[] arr;
}

template<class elementType>
void arrayBasedList< elementType>::insert(elementType item)
{
    if (isFull())
        cout << " The List is Full " << endl;
    else
        arr[arrSize++] = item;
}

template<class elementType>
void arrayBasedList< elementType>::insertAt(elementType element, int index)
{
    if (isFull())
        cout << " The List is Full " << endl;
    else if (index < 0 || index > arrSize)
        cout << "Out of Range " << endl;
    else
    {
        for (int i = arrSize; i > index; i--)
            arr[i] = arr[i - 1];	//shift right

        arr[index] = element;
        arrSize++;
    }
}

template<class elementType>
elementType arrayBasedList< elementType>::retrieveAt(int index) {
    if (index < 0 || index >= arrSize) {
        cout << "Index Out of Range " << endl;
    }
    return arr[index];
}

template<class elementType>
void arrayBasedList< elementType>::removeAt(int index)
{
    if (index < 0 || index >= arrSize)
        cout << "The index is out of range" << endl;
    else
    {
        for (int i = index; i < arrSize - 1; i++)
            arr[i] = arr[i + 1];

        arrSize--;
    }
}

template<class elementType>
void arrayBasedList< elementType>::replaceAt(elementType newElement, int index)
{
    if (index < 0 || index >= arrSize)
        cout << "Out of Range " << endl;
    else
        arr[index] = newElement;
}

template <typename elementType>
bool arrayBasedList<elementType>::isItemAtEqual(elementType element, int index) {
    if (index < 0 || index >= arrSize) {
        return false;
    }
    return arr[index] == element;
}

template <typename elementType>
bool arrayBasedList<elementType>::isEmpty()
{
    return (arrSize == 0);
}

template <typename elementType>
bool arrayBasedList<elementType>::isFull()
{
    return (arrSize == maxSize);
}

template <typename elementType>
int arrayBasedList<elementType>::listSize()
{
    return arrSize;
}

template <typename elementType>
int arrayBasedList<elementType>::maxListSize()
{
    return maxSize;
}

template<class elementType>
void arrayBasedList< elementType>::clear()
{
    arrSize = 0;
}

template<class elementType>
void arrayBasedList< elementType>::print()
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}



