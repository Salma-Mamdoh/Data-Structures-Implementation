// Data Strucure Assignment 2.cpp :
#include"DoublyLinkedList.h"
#include"CircularLinkedList.h"
#include"ArrayBasedList.h";
#include"NewStack.h";
#include"Queue.h"
#include"stackQueue.h"
#include"singleLinkedList.h"
#include <bits/stdc++.h>
using namespace std;
//Generate Binary Numbers from 1 to N
string to_binary(int n) {
    string str;
    while (n > 0) {
        str += char((n & 1) + '0');
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
void SolveGenerateBinaryFrom1TON(int n) {
    Queue<string>q1(1000);
    int x = 1;
    while (x <= n) {
        q1.Enqueue(to_binary(x));
        x++;
    }
    while (!q1.IsEmpty()) {
        cout << q1.front() << " ";
        q1.Dequeue();
    }
    cout << "\n";
}
//Longest Valid Parentheses
void SolveLongestValidParentheses(string input) {
    if (input.empty()) {
        cout << "output will be 0" << " " << "\n";
    }
    else {
        string str = "";
        newStack<char>st;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(')st.Push(input[i]);
            else {
                if (!st.IsEmpty() && st.Top() == '(') {
                    str += "()";
                    st.Pop();
                }
            }
        }
        cout << "output will be " << str.length() << " " << str << "\n";
    }
}
//Convert the Infix Expression to Postfix Expression
bool isOperator(char o) {
    if (o == '+' || o == '-' || o == '*' || o == '/' || o == '^') {
        return true;
    }
    else return false;
}
int getoprationweight(char c) {
    int w = -1;
    if (c == '+' || c == '-') {
        w = 1;
    }
    else if (c == '*' || c== '/') {
        w = 2;
    }
    else if (c == '^') {
        w = 3;
    }
    return w;
}
int highprority(char c1, char c2) {
    int w1 = getoprationweight(c1);
    int w2 = getoprationweight(c2);
    if (w1 >= w2)return true;
    else return false;
}
void SolveConverttheInfixExpressiontoPostfixExpression(string input) {
    newStack<char>st;
    string postfix = "";
    for (int i = 0; i < input.length(); i++) {
        if (isOperator(input[i])) {
            if (!st.IsEmpty() && st.Top() != '(' && highprority(st.Top(), input[i]) ){
                while (!st.IsEmpty() && highprority(st.Top(), input[i])) {
                    postfix += st.Top();
                    st.Pop();
                }
            }
            st.Push(input[i]);
        }
        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            postfix += input[i];
        }
        else if (input[i] == '(') {
            st.Push('(');
        }
        else if (input[i] == ')') {
            while (st.Top() != '(') {
                postfix += st.Top();
                st.Pop();
            }
            st.Pop();//for )
        }
    }
    while (!st.IsEmpty()) {
        postfix += st.Top();
        st.Pop();
    }
    cout << "The output is " << postfix << "\n";
}
int main()
{
    cout << "----------------------------tests for Array Based list  ------------------------\n";
    arrayBasedList<int> arr1(6);
    arr1.insert(10);
    arr1.insert(20);
    arr1.insert(30);
    arr1.insertAt(5, 0);
    arr1.print();
    cout << arr1.isItemAtEqual(20, 2) << endl;
    cout << arr1.isEmpty() << endl;
    cout << arr1.maxListSize() << endl;
    cout << arr1.isFull() << endl;
    cout << arr1.listSize() << endl;
    arr1.removeAt(1);
    arr1.print();
    cout << arr1.listSize() << endl;
    arr1.replaceAt(8, 0);
    arr1.print();
    cout << arr1.retrieveAt(1) << endl;
    arr1.clear();
    cout << arr1.listSize() << endl;
    cout << "----------------------------tests for Doubly Linked List ------------------------\n";
    DoublyLinkedList<int>d1;
    d1.insertAtHead(15);
    d1.insertAtTail(8);
    d1.insertAtHead(9);
    d1.forwardTraversal();
    d1.insertAt(2, 1);
    d1.forwardTraversal();
    d1.backwardTraversal();
    d1.removeAtHead();
    d1.removeAtTail();
    d1.forwardTraversal();
    d1.insertAt(6, 1);
    d1.forwardTraversal();
    d1.removeAt(1);
    d1.forwardTraversal();
    cout<<d1.retrieveAt(1)<<"\n";
    d1.replaceAt(9, 1);
    d1.forwardTraversal();
    cout << d1.isEmpty() << "\n";
    cout << d1.isExist(9) << "\n";
    cout << d1.isItemAtEqual(9, 1) << "\n";
    cout << d1.isItemAtEqual(99, 1) << "\n";
    //d1.clear();
    cout << d1.doubleLinkedListSize() << "\n";
    d1.insertAtHead(155);
   // d1.insertAtHead(95);
    d1.forwardTraversal();
    d1.reverse();
    d1.forwardTraversal();
    d1.insertAtHead(15);
    d1.insertAtTail(9);
    d1.insertAtHead(60);
    d1.forwardTraversal();
    d1.Swap(1,3);
    d1.forwardTraversal();
    cout << "---------------------------------tests for circular linked list ------------------\n";
    CircularLinkedList<int> c1;
    c1.insertAtHead(5);
    c1.insertAtEnd(16);
    c1.insertAtHead(8);
    cout << c1.circularLinkedListSize()<<"\n";
    c1.insertAt(12, 1);
    c1.insertAtHead(86);
    c1.print();
    c1.removeAtHead();
    c1.removeAtEnd();
    c1.print();
    c1.removeAt(2);
    c1.print();
    cout << c1.retrieveAt(1)<<"\n";
    c1.replaceAt(60000, 0);
    c1.print();
    cout << c1.isExist(1200) << " " << c1.isExist(5) << "\n";
    cout << c1.isItemAtEqual(5, 1)<<" "<<c1.isItemAtEqual(3,2)<<"\n";
    //c1.clear();
    c1.insertAtHead(59);
    c1.insertAtEnd(166);
    c1.insertAtHead(88);
    c1.print();
    c1.Swap(1, 3);
    c1.print();
    cout << "----------------------------tests for Stack  ------------------------\n";
    newStack<int> s1;
    s1.Push(3);
    s1.Push(5);
    cout<<s1.Top()<<"\n";
    cout<<s1.Pop()<<"\n";
    s1.Push(10);
    s1.print();
    cout<<s1.IsEmpty()<<"\n";
    s1.clearStack();
    cout << s1.IsEmpty() << "\n";
    cout << "----------------------------tests for StackQueue  ------------------------\n";
    stackQueue sq1;
    sq1.Push(15);
    sq1.Push(17);
    sq1.Push(118);
    sq1.print();
    sq1.Pop();
    sq1.print();
    cout << "----------------------------tests for Queue  ------------------------\n";
    Queue<int>q1(100);
    q1.Enqueue(10);
    q1.Enqueue(15);
    q1.print();
    cout<<q1.Dequeue()<<"\n";
    cout << q1.IsEmpty() << "\n";
    cout << q1.front() << "\n";
    cout << q1.Size() << "\n";
    q1.clear();
    cout << q1.IsEmpty() << "\n";
    q1.Enqueue(3);
    q1.Enqueue(1);
    q1.Enqueue(5);
    q1.Enqueue(2);
    q1.Enqueue(4);
    q1.print();
    q1.sortQueue(q1);
    q1.print();
    cout << "-------------------------test Generate Binary Numbers from 1 to N problem--------------\n";
    SolveGenerateBinaryFrom1TON(3);
    SolveGenerateBinaryFrom1TON(5);
    SolveGenerateBinaryFrom1TON(10);
    cout << "-------------------------test Longest Valid Parentheses--------------\n";
    SolveLongestValidParentheses("(()");
    SolveLongestValidParentheses(" ");
    SolveLongestValidParentheses(")()())");
    cout << "-------------------------test Convert the Infix Expression to Postfix Expression--------------\n";
    SolveConverttheInfixExpressiontoPostfixExpression("X^Y / (5*Z) + 2");
    SolveConverttheInfixExpressiontoPostfixExpression("A + B * C + D");
    SolveConverttheInfixExpressiontoPostfixExpression(" (A + B) * (C + D)");
    cout << "-------------------- Single Linked List -----------------------" << endl;
    singleLinkedList<int>sll, sll2, sll3, sll4, sll5, sll6;
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(90);
    sll.insertAt(30, 2);
    sll.print();
    sll.swap(1, 2);
    sll.print();
    sll.replaceAt(80, 1);
    cout << sll.retrieveAt(1) << endl;
    sll.print();
    sll.removeAt(2);
    sll.print();
    cout << sll.isItemAtEqual(80, 1) << endl;
    sll.isExist(30);
    sll.removeAtHead();
    sll.removeAt(1);
    sll.removeAtTail();
    cout << sll.isEmpty() << endl;
    sll.print();
    cout << sll.linkedListSize() << endl;
    sll.clear();

    cout << "------------------- Combine Nodes Between Zeros----------------------" << endl;
    sll2.insertAtTail(0);          //[0, 3, 1, 0, 4, 5, 2, 0]
    sll2.insertAtTail(3);
    sll2.insertAtTail(1);
    sll2.insertAtTail(0);
    sll2.insertAtTail(4);
    sll2.insertAtTail(5);
    sll2.insertAtTail(2);
    sll2.insertAtTail(0);
    sll2.print();
    sll2.combineNodesBetweenZeros();
    sll2.print();

    cout << "--------------------Merge K Sorted Linked Lists-----------------------" << endl;
    sll3.insertAtHead(1);
    sll3.insertAtTail(4);
    sll3.insertAtTail(5);
    sll4.insertAtHead(1);
    sll4.insertAtTail(3);
    sll4.insertAtTail(4);
    sll5.insertAtHead(2);
    sll5.insertAtTail(6);
    node<int>* arr[3] = { sll3.gethead(),sll4.gethead(),sll5.gethead() };
    sll6.addToMerge(arr, 3);

    return 0;

}

