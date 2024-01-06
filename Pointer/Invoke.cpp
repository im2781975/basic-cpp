#include <iostream>
using namespace std;

int add(int x, int y){
    return x + y; 
    }
int multiply(int x, int y) { 
    return x * y;
    }
// Function that takes a pointer
int invoke(int x, int y, int (*func)(int, int)){
    return func(x, y);
    }
int main()
{
    cout << "\nAddition of 20 and 10 is: ";
    cout << invoke(20, 10, &add) ;
 
    cout << "\nMultiplication of 20  and 10 is: ";
    cout << invoke(20, 10, &multiply)  ;
 
    return 0;
}
