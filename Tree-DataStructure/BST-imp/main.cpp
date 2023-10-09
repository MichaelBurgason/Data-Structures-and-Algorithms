/* This program is based on the implementation of BST(binary search tree)
using linked list as our data-structure
now, the functions that BST can be introduced with are:
1. Insert() this function let us construct the binary search tree with the fact that the left subtree
   values from the node should be less and the right subtree values should be greater the node

2. lookup() this function let us return True or false if the given node exist or not.
3. remove() let us remove a node Note: we should always maintain the constraints of the BST after removal(hence
    it may also required to reorder some node.)
*/

#include <bits/stdc++.h>
using namespace std;



class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};



class binarySearchTree {
    Node* root;

public:
    binarySearchTree() {
        root = NULL;
    }

    void insertNode(int data) {
        Node* newNode = new Node(data);
        Node* temp = root; // a temperary pointer to allow is to traverse the tree

        Node* trail = NULL; // this will help us remember the trail.

        while (temp != NULL) {
            trail = temp;
            if (data < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }

        if (trail == NULL) {
            root = newNode; // this is if the tree is empty
        }
        else if (data < trail->data) {
            trail->left = newNode; // if data is less than trail, place it on the left
        }
        else {
            trail->right = newNode; // if data is greater than trail place newNode on right
        }
    }

    void deleteNode(int data) { //this has an edge case that I decided to not care about. if you try to delete the root it'll die. dont do that.
        if (root == NULL)
        {
            cout << "Tree Empty Please Insert values" << endl;
            return;
        }
        Node* temp = root; //pointer to root
        Node* parent = NULL; // pointer to parent of current node

        while (temp != NULL) {
            if (data < temp->data) {
                parent = temp;
                temp = temp->left;
            }
            else if (data > temp->data) {
                parent = temp;
                temp = temp->right;
            }
            else {

                if (temp->left == NULL && temp->right == NULL) { // this is the case for no children
                    cout << "We are deleteing a child node" << endl;
                    if (parent->left == temp) {
                        parent->left = NULL;
                    }
                    else {
                        parent->right = NULL;
                    }
                    delete(temp);
                    return;
                }
                if (temp->left == NULL || temp->right == NULL) { // this is the case for one child
                    cout << "Deleting a node with one child" << endl;
                    if (temp->left != NULL && data < parent->data) {
                        parent->left = temp->left;
                    }
                    if (temp->left != NULL && data > parent->data) {
                        parent->right = temp->left;
                    }
                    if (temp->right != NULL && data < parent->data) {
                        parent->left = temp->left;
                    }
                    if (temp->right != NULL && data > parent->data) {
                        parent->right = temp->left;
                    }
                    delete(temp);
                    return;
                }
                if (temp->left != NULL && temp->right != NULL) {
                    cout << "We are deleting a node with 2 children" << endl; //here we have two children, and need to find who should be promoted
                    Node* heir = temp->right;
                    if (heir->right == NULL && heir->left == NULL) { // instead of an heir it's kind of like the heir sliding into the kinds body... which I guess is still an heir
                        temp->data = heir->data;
                        temp->right = NULL;
                        delete(heir);
                        return;
                    }
                    if (heir->left == NULL && heir->right != NULL) {
                        temp->data = heir->data;
                        temp->right = heir->right;
                        delete(heir);
                        return;
                    }
                    while (heir->left != NULL) {
                        parent = heir;
                        heir = heir->left;
                    }
                    temp->data = heir->data;
                    parent->left = NULL;
                    delete(heir);
                    return;
                }
            }
        }

        cout << "Nothing found to delete" << endl;
        return;
    };

    bool lookup(int data)
    {
        if (root == NULL)
        {
            cout << "Tree Empty please Insert values" << endl;
            return false;
        }
        Node* temp = root;
        while (temp != NULL)
        {
            if (temp->data > data)
            {
                temp = temp->left;
            }
            else if (temp->data < data)
            {
                temp = temp->right;
            }
            else if (temp->data == data)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    { // this display function uses in-order traversal left->root->right
        /* here we are using stack data structure for traversing */
        stack<Node*> s;
        Node* temp = root;

        while (temp != NULL || s.empty() == false)
        {

            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left; // going towards left first
            }
            temp = s.top();
            cout << temp->data << "  "; // printing the left most data.
            s.pop();

            temp = temp->right; // going towards right.
        }
    }
};

int main()
{
    binarySearchTree b;
    /*    20
         /  \
        10   30
       /    /  \
      1    25  40   tree structure */

    b.insertNode(20);
    b.insertNode(10);
    b.insertNode(30);
    b.insertNode(25);
    b.insertNode(40);
    b.insertNode(1);

    b.display();
    cout << endl;

    b.deleteNode(30);
    b.display();

    return 0;
}
