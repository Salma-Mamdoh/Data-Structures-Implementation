#include<bits/stdc++.h>
using namespace std;
#include"Queue.h"
#include"Stack.h"
// Implement a Stack
class stackQueue {
private:
    newQueue<int> q1, q2;
public:
    void push(int x) {
        if (q1.IsEmpty()) {
            q1.enqueue(x);
        }
        else {
            while (!(q1.IsEmpty())) {
                q2.enqueue(q1.dequeue());
            }
            q1.enqueue(x);
            while (!(q2.IsEmpty()))
            {
                q1.enqueue(q2.dequeue());
            }
        }
    }

    void Pop() {
        q1.dequeue();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.IsEmpty();
    }

};

// Sorting a Queue
void sortQueue(newQueue<int>& q) {
    vector<int> v;
    while (!q.IsEmpty()) {
        v.push_back(q.front());
        q.dequeue();
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        q.enqueue(v[i]);
    }
}


int main() {
    stackQueue s;
    s.push(5);
    cout << s.top() << endl;

    return 0;
}



