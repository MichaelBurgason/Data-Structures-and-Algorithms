/* Implementing dynamic array in c++ which is basically a vector STL library.
   but the below implementation of arrays in c++ is done by using class which will have the
   following functions.

    1. void push(int data): This function takes one element and inserts it at the last.
    2. void push(int data, int index): It inserts data at the specified index.
    3. int get(int index): It is used to get the element at the specified index.
    4. void pop(): It deletes the last element. Time complexity is O(1).
    5. int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1).
    6. int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
    7. void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector.

 */

#include <bits/stdc++.h>
using namespace std;
// THIS IS A VECOR IN C++

class DynamicArray {
    int* arr; // creates the array pointer
    int capacity;
    int totalNumbers;

public:
    DynamicArray() {
        arr = new int[2];
        capacity = 2;
        totalNumbers = 0;
    }

    void push(int data) {
        if (totalNumbers == capacity) { // time complexity of O(1)
            int* tempArr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                tempArr[i] = arr[i]; // copies the current elements into a new vector
                // (dynamic array)
            }
            delete[] arr; // deletes memory for arr
            capacity = capacity * 2;
            arr = tempArr;
        }
        arr[totalNumbers] = data;
        totalNumbers++;
    }

    void replace(int data, int index) { // time complexity of O(1)
        // replace the data at a certin index
        if (index == capacity) {
            push(data); // check for an end case
        }
        else {
            arr[index] = data; // insert data if not an endcase
        }
    }

    void insert(int data, int index) {
        //in this we slot the number in, and shift the others
        if (index == capacity) {
            push(data);
        }
        for (int i = totalNumbers; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = data;
        totalNumbers++;
    }

    int pop() {
        //returns number at end of array, and reduces it's size
        int element = arr[totalNumbers - 1];
        totalNumbers--;
        return element;
    }
    void erase(int index) {
        if (index > -1 && index < totalNumbers) {
            totalNumbers--;
            for (int j = index; j < totalNumbers; j++) {
                arr[j] = arr[j + 1];
            }

        }
    }
    int get(int index) {
        if (index > -1 && index < totalNumbers) {
            return arr[index];
        }
    }
    int length() {
        return totalNumbers;
    }
    void print() {
        for (int i = 0; i < totalNumbers; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray vectorArr;
    vectorArr.push(10);
    vectorArr.push(20);
    vectorArr.push(30);
    vectorArr.push(40);
    vectorArr.insert(50, 2);
    cout << "The Array is: ";
    vectorArr.print();

    int element = vectorArr.pop();
    cout << "Element Deleted: " << element << endl;
    cout << "The array after deletion is: ";
    vectorArr.print();

    vectorArr.erase(0);
    cout << "The array after deleting index-0 element: ";
    vectorArr.print();

    cout << "The size of array is: " << vectorArr.length() << endl;

    cout << "The memory address is: " << *vectorArr << endl;
    return 0;

}