#include <iostream> 
#include <typeinfo> 
using namespace std; 
int main() 
{ 
    int num = 10; 
    double numDouble = static_cast<double>(num); 
 
    cout << typeid(num).name() << endl; 
    // typecasting 
    cout << typeid(static_cast<double>(num)).name() << endl; 
    cout << typeid(numDouble).name() << endl; 
  
    return 0; 
}
