#include <iostream>
using namespace std;

int main(){
    int someNumber = 4;
    int otherNumber = 6;
    int sum = someNumber + otherNumber;
    string message;
    if (sum != 11) {
        message = "You cannot count";
        sum = 11;
    }
    else {
        message = "You count just fine";
    }
    // print whether things went well or not
    cout<<message<<endl;
    // Exit main program
    return 0;
}