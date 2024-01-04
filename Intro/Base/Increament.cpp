#include <iostream> 
using namespace std; 
int z=10;
int main() 
{ 
    int z=5;
    int x = 5,y=10;
    
    cout << "x++ is : " << x++ ;
    cout << "\n++x is : " << ++x;
    
    cout << "\ny-- is : " << y-- ;
    cout << "\n--y is : " << --y ;
    
    cout <<"\nlocal access of z is: " << z;
    cout <<"\nGlobal access of z is: " <<::z;
    return 0; 
}
