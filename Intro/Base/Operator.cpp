// Binary Operators
#include <iostream>
using namespace std;
int main()
{
    int a = 8, b = 3;
 
    cout <<"\na + b : " << (a + b);
    cout <<"\na - b : " << (a - b);
    cout <<"\na * b : " << (a * b);
    cout <<"\na / b : " << (a / b);
    cout <<"\na % b : " << (a % b);
 
    // compare operator
    cout<<"\na == b is :" << (a == b);
    cout <<"\na > b is :"<<(a > b);
    cout << "\na >= b is : " << (a >= b) ;
    cout<< "\na < b is : " <<(a < b) ;
    cout << "\na <= b is : " << (a <= b) ;
    
    // true
    cout << "\na != b is : " << (a != b) ;
    cout << "\na && b is : " << (a && b) ;
   
    // Logical OR operator
    cout << "\na ! b is : " << (a >b) ;
    // Logical NOT operator
    cout << "\n!b is : " << (!b) ;
    
    // Binary AND operator
    cout << "\na & b is : " << (a & b) ;
    cout << "\na | b is : " << (a | b) ;
    // Binary XOR operator
    cout << "\na ^ b is : " << (a ^ b) ;
 
    cout << "\na<<1 is : " << (a << 1) ;
    cout << "\na>>1 is : " << (a >> 1) ;
 
    // One’s Complement operator
    cout << "\n~(a) is : " <<~(a) ;
    cout << "\n~(-a) is : " <<~(-a) ;
    cout << "\na : " << a ;
   
    cout << "\na += b is : " << (a += b) ;
    cout << "\na -= b is : " << (a -= b) ;
    cout << "\na *= b is : " << (a *= b) ;
    cout << "\na /= b is : " << (a /= b) ;
    
    cout<< "\nTernary operator: ";
    (a & b)? cout<< "\nTrue ":cout<< "\nFalse";
    (a && b)? cout<< "\nTrue ":cout<< "\nFalse";
}
