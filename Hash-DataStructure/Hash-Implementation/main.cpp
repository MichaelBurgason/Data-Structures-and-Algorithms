/* Implementation of Hashing data structure */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int ARRAY_SIZE = 128;


/* creating a class called hash node which will have two properties
1. Key
2. Value
*/

class HashNode {
public:
    int key;
    int value;

    //creating the constructor
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashTable {
    HashNode** arr;// declaring the array of the hash node
public:

    HashTable() {
        arr = new HashNode * [ARRAY_SIZE]; // creating an array of hash nodes (128 nodes)
        for (int i = 0; i < ARRAY_SIZE; i++) {
            arr[i] = NULL;  //This ensures the memory is cleared, and doesnt have garbage from earlier use.
        }
    }

    //create a functiuon for interting the key, using open addressing
protected:
    int hashFunction(int key) {
        return key % ARRAY_SIZE;
    }
public:
    //function for inserting an element. (this is where the actual "open addressing" takes place.)
    void insertElement(int key, int value) {
        int location = hashFunction(key);
        while (arr[location] != NULL && arr[location]->key != key) {
            location = hashFunction(location + 1);
        }
        if (arr[location] != NULL) {
            delete arr[location];
        }
        arr[location] = new HashNode(key, value);
    }

    int get(int key) {
        int location = hashFunction(key);
        while (arr[location] != NULL && arr[location]->key != key) {
            location = hashFunction(location + 1);
        }
        if (arr[location] == NULL) {
            return -1;
        }
        return arr[location]->value;
    }


    void removeElement(int key) {
        int location = hashFunction(key);
        if (arr[location] == NULL) {
            cout << "No Element Found" << endl;
            return;
        }
        while (arr[location] != NULL) {
            if (arr[location]->key == key) {
                break;
            }
            location = hashFunction(location + 1);
        }
        delete arr[location];
        cout << "Element Deleted" << endl;
    }


    void display() {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (arr[i] != NULL) {
                cout << arr[i]->key << "--->" << arr[i]->value << endl;
            }
        }
    }
};

int main() {
    HashTable h;
    h.insertElement(1, 1);
    h.insertElement(2, 2);
    h.insertElement(2, 3);
    h.insertElement(2, 8);  // note then when displayed the value of key->2 should be only 8.
    h.insertElement(12, 21);

    h.display();

    cout << h.get(2);

    return 0;

}

