#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    int value;

    // Default constructor
    MyClass() {
        value = 0; // Initialize value to 0 or any default value
        cout << "Default constructor called\n";
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        value = other.value; // Copy the value from 'other' to the new object
        cout << "Copy constructor called\n";
    }
};

int main() {
    MyClass obj1;      // Default constructor initializes obj1
    obj1.value = 10;   // Set value of obj1

    // Initialize obj2 by copying obj1
    MyClass obj2 = obj1; // This calls the copy constructor

    cout << "obj1.value: " << obj1.value << "\n";
    cout << "obj2.value: " << obj2.value << "\n";
    return 0;
}


