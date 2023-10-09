#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string reverseString(string input) {
    reverse(input.begin(), input.end());
    return input;
}

int main() {
    string example = "Hi im Michael";
    reverseString(example);
    cout << example;
}