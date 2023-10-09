/* Implementing Queue DataStructure using linked list
Queue works on the principle of FIFO(first-in-first-out)
hence the function we are implementing are:
1. enqueu() to denote the queue is forming hence all the node added from head.
2. dequeu() removes the first element that was inserted at the starting.
3. display() show all the elements in the queue.

    50-->20-->30-->20-->10
lastElement         firstElement
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node* last, * first;
    int totalElements;

public:
    Queue() {
        this->first = NULL;
        this->last = NULL;
        totalElements = 0;
    }
    void enqueu(int data) {
        Node* newNode = new Node(data);
        if (last == NULL && first == NULL) {
            last = newNode;
            first = newNode;
            totalElements++;
        }
        last->next = newNode;
        last = newNode;
        totalElements++;
    }

    int dequeu() {
        if (first == NULL) {
            return NULL;
        }
        int firstValue = first->data;
        Node* oldFront = first;
        first = first->next;
        delete (oldFront);
        totalElements--;
        return firstValue;
    }

    void display() {
        if (first == NULL) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = first;
        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueu(10);
    q.enqueu(20);
    q.enqueu(30);
    q.enqueu(40);
    q.enqueu(50); // 10->20->30->40->50

    cout << q.dequeu() << endl; // 20->30->40->50
    q.display();
}

