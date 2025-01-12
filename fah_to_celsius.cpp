#include <iostream>
using namespace std;

// formula to convert from fah to celsius
float conversion (float n)
{
    return(n - 32.0) * 5.0/9.0;
}

int main() {
    float n =  50;
    cout<< "fah to celsius = "<< conversion(n);
    return 0;
}