#include<bits/stdc++.h>
#include"Queue.h"
#include"Stack.h"
using namespace std;

// Implement a Stack
class stackQueue {
private:
    queue<int> q1, q2;
public:
    void enqueue(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void dequeue() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
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
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << endl; // Output: 4
    s.pop();
    cout << s.top() << endl; // Output: 3
    s.pop();
    cout << s.top() << endl; // Output: 2
    s.pop();
    cout << s.top() << endl; // Output: 1
    s.pop();
    cout << s.empty() << endl; // Output: 1 (true)

    newQueue<int> q;
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(1);
    q.enqueue(4);

    sortQueue(q);

    while (!q.IsEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
	return 0;
}