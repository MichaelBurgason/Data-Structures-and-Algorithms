#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* link;
    Node(int data) {
        this->data = data;        // assign data
        this->link = NULL; // assign pointer to default of NULL
    }
};

class LinkedList {
    Node* head;
    Node* tail;
    int totalNodes;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    void append(int element) {

        Node* newNode = new Node(element);
        // append inserts an element at the end of a Linked List
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }
        tail->link = newNode;
        tail = newNode;
        totalNodes++;
    }

    void preAppend(int element) {
        Node* newNode = new Node(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }
        newNode->link = head;
        head = newNode;
        totalNodes++;
    }

    void insertNode(int element, int position) {
        if (position < 0) {
            cout << "invalid Position" << endl;
            return;
        }
        else if (position == 0) {
            preAppend(element);
            return;
        }
        else if (position >= totalNodes) {
            append(element);
        }

        Node* newNode = new Node(element);
        Node* prev = head;

        for (int i = 0; i < position; i++) {
            prev = prev->link;
        }
        newNode->link = prev->link;
        prev->link = newNode;
        totalNodes++;
    }

    void removeNode(int position) {
        if (position < 1 || position > totalNodes) {
            cout << "[Warning] Node cannot be Deleted" << endl;
            return;
        }
        Node* temp = head;
        if (position == 1) {
            head = head->link;
            delete temp;
            totalNodes--;
            return;
        }
        // traverse to the position just before the node that is to be deleted
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->link;
        }

        // check if the temp or pointer reference is null or not
        // if it is true it means that the node which is to be deleted is not
        // present
        if (temp == NULL || temp->link == NULL) {
            return;
        }
        Node* link = temp->link->link;
        delete (temp->link);
        temp->link = link;
        totalNodes--;
        return;
    }

    void display() {
        if (head == NULL) {
            cout << "list is empty" << endl;
        }
        Node* temp = head;
        for (int i = 0; i < totalNodes; i++) {
            cout << temp->data << "---->";
            temp = temp->link;
        }
        cout << endl;
    }

    int get(int index) {
        // Check if the index is valid
        if (index < 0 || index >= totalNodes) {
            // Handle invalid index case: throw an exception or return a sentinel
            // value.
            cout << "Invalid index!" << endl;
            throw out_of_range("Index out of bounds!");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->link;
        }

        return current->data;
    }

    int find(int data) {
        Node* current = head;
        for (int i = 0; i < totalNodes; i++) {
            if (current->data == data) {
                return i;
            }
            else if (current->link == NULL) {
                break;
            }
            current = current->link;
        }
        cout << "Bruh aint no MATCHING INDCIE";
        cout << endl;
        return -1;
    }
};

int main() {
    LinkedList l;
    // appending elements
    cout << "Appending Node:" << endl;
    l.append(2);
    l.append(4);
    l.append(6);
    l.append(8);
    l.append(10);

    // displaying elements
    l.display();

    cout << "Inserting Node:" << endl;

    l.insertNode(3, 2);
    l.display();
    l.insertNode(1, 0);
    l.display();

    cout << "Delete Node:" << endl;
    l.removeNode(4);
    l.removeNode(1);
    l.removeNode(5);

    l.display();

    cout << "Get Node: 2" << endl;
    cout << l.get(2) << endl;

    cout << "Find Node 8:" << endl;
    cout << l.find(8) << endl;

    return 0;
}
