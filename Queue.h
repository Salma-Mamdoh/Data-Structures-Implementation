#pragma once
#include<bits/stdc++.h>
using namespace std;
template<class elementType>
class Queue {
private:
    elementType* newQueue;       //array to store queue elements
    int maxSize;                //maximum capacity of the queue
    int Front;                 //points to the front element in the queue (if any)
    int Rear;                 //points to the last element in the queue
    int size;
public:
    Queue(int size);
    ~Queue();
    void Enqueue(elementType item);
    void Dequeue();
    int Size();
    bool IsEmpty();
    bool IsFull();
    elementType front();
};
template<class elementType>
inline Queue<elementType>::Queue(int capa)
{
    maxSize = capa;
    Front = -1;
    Rear = 0;
    newQueue = new elementType[maxSize];
    size = 0;
}

template<class elementType>
inline Queue<elementType>::~Queue()
{
    delete[]newQueue;
}

template<class elementType>
inline void Queue<elementType>::Enqueue(elementType item)
{
    if (size == maxSize) {
        cout << "Queue is full" << endl;
        return;
    }
    if (Front == -1) {
        Front = 0;
    }
    newQueue[Rear] = item;
    Rear++;
    size++;
}

template<class elementType>
inline void Queue<elementType>::Dequeue()
{
    if (Front == -1) {
        cout << "Queue is Empty" << endl;
    }
    for (int i = 0; i < size; i++) {
        newQueue[i] = newQueue[i + 1];
    }
    Rear--;
    size--;
    if (size == 0) {
        Front= -1;
        Rear = 0;
    }
}

template<class elementType>
inline int Queue<elementType>::Size()
{
    return size;
}

template<class elementType>
inline bool Queue<elementType>::IsEmpty()
{
    return size==0;
}

template<class elementType>
inline bool Queue<elementType>::IsFull()
{
    return (size==maxSize);
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
