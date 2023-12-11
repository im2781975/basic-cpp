#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    // uninitialized bitset object
    bitset<8> uninitializedBitset;
    //initialize with decimal number
    bitset<8> decimalBitset(15);
    // initialize with binary string
    bitset<8> stringBitset(string("1111"));
 
    cout << "\nUninitialized bitset: " <<uninitializedBitset;
    cout << "\nInitialized with decimal: " <<decimalBitset;
    cout << "\nInitialized with string: " << stringBitset ;
 
    return 0;
}
