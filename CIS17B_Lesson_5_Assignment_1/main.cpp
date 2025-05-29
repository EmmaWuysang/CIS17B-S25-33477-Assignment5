/* 
 * File:   main.cpp
 * Author: Emma Wuysang
 * Creator Notes: I used NetBeans, and I am not too sure but the compiler keeps abbreviating the different types! but d = double, i = int, Ss = string!
 * Created on May 28, 2025 4:25 PM
 * Purpose: Develop a Simple Storage Management System focusing on Templates !
 */


// libraries
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
using namespace std;

template<typename T> // generic template 
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for std::string
template<>
class Package<string> {
private:
    string item;
public:
    Package(string i) : item(i) {}
    void label() {
        cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

template<typename T, int Size>
class Box { // class box to contain items in an array
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const { // prints the box contents using a for loop
        cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};

template<typename T> // shipping items whether that be int or string
void shipItem(const T& item) {
    cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<> // shipping doubles and floats
void shipItem(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

// main program for running code
main(){
    Package<int> intPack(33); // assigned int
    intPack.label(); // for the first line of printed code, int-general output
    
    Package<string> bookPack("C++ Primer");
    bookPack.label(); // for the second line of sample output, string output
    
    double fTemp = 22.4; // initialize fTemp first
    Package<double*> fragilePack(&fTemp);
    fragilePack.label(); // third line of sample output, for floats
    
    // Adding to a box
    Box<string,3> boxForBooks;
    boxForBooks.addItem("The Pragmatic Programmer"); // first addition
    boxForBooks.addItem("Clean Code"); // second addition
    boxForBooks.printItems(); // print contents
    
    shipItem(2); // should produce int or 'i'
    string tempMsg = "Hey There!";
    shipItem(tempMsg); // should produce string or 'Ss'
    shipItem(22.5); // should produce the shipping temp 

    // exit the program!
    return 0;
}

// end of program and should follow sample output listed in program desc.