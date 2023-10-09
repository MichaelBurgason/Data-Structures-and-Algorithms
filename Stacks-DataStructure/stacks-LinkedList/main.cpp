/* This program is made to implement stack using linked list
The functions that will be used for implementing stack are:
1. push() ==> preAppend()
2. pop() ==> removeFromBeginning()
3. display()
*/

#include <bits/stdc++.h>
using namespace std;



//creating a node class to start the Linked list implimentation
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (top == NULL) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            cout << "sorry, there is nothing to pop" << endl;
            return NULL;
        }
        int value = top->data; // grab calue of top
        Node* current = top; //grab current top so it can be cleared from memory
        top = top->next; // set old top next to new top
        delete(current);

        return value;
    }

    void display() {
        if (top == NULL) {
            cout << "underflow? empty stack?" << endl;
            return;
        }
        Node* temp = top;
        for (int i = 0; temp != NULL; i++) {
            cout << top->data << endl;
            temp = temp->next;
        }
        delete(temp);
    }

};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl; //removes 30
    s.display();

    return 0;
}