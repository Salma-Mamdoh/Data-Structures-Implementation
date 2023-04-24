// Data Strucure Assignment 2.cpp :
#include"DoublyLinkedList.h"
#include"CircularLinkedList.h"
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
    queue<string>q1;
    int x = 1;
    while (x <= n) {
        q1.push(to_binary(x));
        x++;
    }
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
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
        stack<char>st;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(')st.push(input[i]);
            else {
                if (!st.empty() && st.top() == '(') {
                    str += "()";
                    st.pop();
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
    stack<char>st;
    string postfix = "";
    for (int i = 0; i < input.length(); i++) {
        if (isOperator(input[i])) {
            if (!st.empty() && st.top() != '(' && highprority(st.top(), input[i]) ){
                while (!st.empty() && highprority(st.top(), input[i])) {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(input[i]);
        }
        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            postfix += input[i];
        }
        else if (input[i] == '(') {
            st.push('(');
        }
        else if (input[i] == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();//for )
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    cout << "The output is " << postfix << "\n";
}
int main()
{
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

}

