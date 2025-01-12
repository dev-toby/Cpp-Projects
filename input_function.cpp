#include <iostream>
using namespace std;

int main() {
   string name;
   int age;
   char sex;
    //prompt the user for input
    cout<< "enter your name: ";
    // Take multiple input using cin
    cin>> name;
    cout<< "enter your age: ";
    cin>> age;
    cout<< "enter your sex: ";
    cin>> sex;
    // Print out
    cout<< "Name: " << name <<endl;
    cout<< "age: " << age <<endl; 
    cout<< "sex: " << sex <<endl; 
    return 0;
}