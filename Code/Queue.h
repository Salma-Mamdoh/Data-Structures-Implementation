#pragma once
#include<bits/stdc++.h>
using namespace std;
//guard 
#ifndef QUEUE_H
#define QUEUE_H

template<class elementType>
class Queue {
private:
    elementType* newQueue;       //array to store queue elements
    int Front;                 //points to the front element in the queue (if any)
    int Rear;                 //points to the last element in the queue
    int size;
    int capacity;
public:
    Queue(int x);
    void Enqueue(elementType item);
    elementType Dequeue();
    int Size();
    bool IsEmpty();
    void clear();
    void print();
    void sortQueue(Queue<elementType>& q);
    elementType front();
};
#endif
template<class elementType>
inline Queue<elementType>::Queue(int x)
{
        Front = Rear = 0;
        capacity = x;
        size = 0;
        newQueue = new elementType[x];
}

template<class elementType>
inline void Queue<elementType>::Enqueue(elementType item)
{

    if (capacity == Rear) {
        cout<<"Queue is full\n";
        return;
    }

    // insert element at the rear
    else {
        newQueue[Rear] = item;
        Rear++;
        size++;
    }
}

template<class elementType>
inline elementType Queue<elementType>::Dequeue()
{
    if (Front == -1) {
        cout << "Queue is Empty" << endl;
    }
    elementType z = newQueue[Front];
    for (int i = 0; i < size; i++) {
        newQueue[i] = newQueue[i + 1];
    }
    Rear--;
    size--;
    if (size == 0) {
        Front = 0;
        Rear = 0;
    }
    return z;
}

template<class elementType>
inline int Queue<elementType>::Size()
{
    return size;
}

template<class elementType>
inline bool Queue<elementType>::IsEmpty()
{
    return size == 0;
}

template<class elementType>
inline void Queue<elementType>::clear() {
    Front = 0;
    Rear = 0;
    size = 0;
}
template<class elementType>
inline void Queue<elementType>::print() {
    for (int i = 0; i < size; i++) {
        cout << newQueue[i] << " ";
    }
    cout << "\n";
}
template<class elementType>
inline void Queue<elementType>::sortQueue(Queue<elementType>& q)
{
    if (q.Size() == 0 || q.Size() == 1)
        return;
    else {
        int n = q.Size();
        int count = 0;
        elementType x = q.Dequeue();
        sortQueue(q); // get last element and compare 
        while (q.front() < x && count < n)
        {
            q.Enqueue(q.Dequeue());
            count++;
        }
        q.Enqueue(x);
        if (count == n)
            return;

        count = 0;
        while (q.front() >= x && count < n)
        {
            q.Enqueue(q.Dequeue());
            count++;
        }
    }
}


template<class elementType>
inline elementType Queue<elementType>::front()
{
    if (Front == -1) {
        cout << "Queue is Empty" << endl;
        return 0;
    }
    return newQueue[Front];
}