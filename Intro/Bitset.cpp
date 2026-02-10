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
 
    int index = 0;
    bitset<4> allSet("1111"), allUnset;
 //Boolalpha method is used to extract or print the textual format of Boolean values. if value is true then, while printing the value "true" will get printed and if value is false then "false"
    cout << "\nallSet.any() value: " << boolalpha << allSet.any() ;
 
    cout << "\nallSet.all() value: " << allSet.all() ;
 
    cout << "\nallSet.none() value: " << allSet.none() ;
 
    cout << "\nallSet.test() at index 0: " << noboolalpha
         << allSet.test(index) ;
 
    cout << "\nallSet.size() value: " << allSet.size() ;
 
    cout << "\nValue of allUnset on before using set(): " << allUnset;
    allUnset.set(index);
    cout << "\nValue of allUnset on after using set(): "
         << allUnset ;
 
    cout << "\nValue of allSet on before using reset(): "
         << allSet ;
    allSet.reset(index);
    cout << "\nValue of allSet on after using reset(): "
         << allSet ;
 
    // declaring an empty string
    string bitString;
    // using to_string() method to assign value to empty string
    bitString = allSet.to_string();
    cout << "\nbitString: " << bitString ;
 
    cout << "\nUnsigned Long value: " << allSet.to_ulong();
    
    bitset<4> bitset1("1001"), bitset2("1010"),result;
 
    cout <<"\nBitset1: "<<bitset1 << "\nBitset2: "<< bitset2<<"\n" <<result ;
 
    cout << "\nAccessing bit value at index 1 of bitset1: "
         << bitset1[1] ;
 
    cout << "\nBitwise AND using &: "<< (result = bitset1 & bitset2) ;
    cout << "\nBitwise AND using &=: " << (bitset1 &= bitset2);
 
    bitset1 = 9; 
    cout << "\nBitwise OR using &: "<< (result = bitset1 | bitset2) ;
    cout << "\nBitwise OR using &=: " << (bitset1 |= bitset2) ;
 
    cout << "\nBitwise NOT: " << (result = ~bitset1) ;
 
    bitset1 = 9;
    cout << "\nBitwise XOR: " << (bitset1 ^= bitset2) ;
 
    bitset1 = 9;
    cout << "\nBinary leftshift on bitwise1: "<< (bitset1 <<= 1) ;
    
    bitset1 = 9;
    cout << "\nBinary rightshift on bitwise1: "<< (bitset1 >>= 1) ;
    return 0;
}
