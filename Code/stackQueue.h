#pragma once
#include<bits/stdc++.h>
#include"Queue.h"
using namespace std;
//guard 
#ifndef STACKQUEUE_H
#define STACQUEUE_H
class stackQueue {
private:
    Queue<int>q1=Queue<int>(100);
    Queue<int>q2=Queue<int>(100);
public:
    stackQueue() {
        
    }
    void Push(int x) {
        q1.Enqueue(x);
    }

    void Pop() {
       
        while (q1.Size() > 1) {
            q2.Enqueue(q1.front());
            q1.Dequeue();
        }
        q1 = q2;
    }
    void print() {
        q1.print();
    }

};
#endif