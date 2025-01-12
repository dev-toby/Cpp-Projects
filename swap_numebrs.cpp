#include <iostream>
using namespace std;

int main() {
    int a =  2, b = 3;
    cout<< "before swapping a = " << a << " , b = " << b <<endl;
    // temprary variable
    int temp;
    // applying swapping code
    temp = a;
    a = b;
    b = temp;
    cout<< "after swappign a = " << a << " ,  b = " << b <<endl;
    return 0;
}