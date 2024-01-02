//implicit conversion 
#include <iostream> 
using namespace std; 
int main() 
{ 
    int x = 10; 
    char y = 'a'; 
    double d=1.2 ;
    x = x + y; 
    // x is implicitly converted to float 
    float z = x + 1.0; 
    cout << "x = " << x << endl 
         << "y = " << y << endl 
         << "z = " << z << endl; 
    //Explicit conversion from double to int 
    int sum = (int)d + 1; 
    cout << "Sum = " << sum; 
    return 0; 
} 
