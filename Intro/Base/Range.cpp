// macros for data types 
#include<iostream> 
#include<limits.h> 
#include<float.h>
using namespace std; 
int main() 
{ 
    cout<<"range[char]: "<<CHAR_MIN << " -- " << CHAR_MAX; 
    
    cout << "\nrange[short_char] : " << SCHAR_MIN <<" -- "<< SCHAR_MAX; 
    
    cout << "\nrange[unsigned_char] : " << 0 << " -- " << UCHAR_MAX; 
  
    cout << "\nrange[short_int] : " << SHRT_MIN << " -- " << SHRT_MAX; 
    
    cout <<"\nrange[unsigned_short_int] : " << 0 << " -- " << USHRT_MAX; 
    
    cout << "\nrange[int] : " << INT_MIN << " -- " << INT_MAX; 
    cout << "\nrange[unsigned int] : " << 0 << " -- " << UINT_MAX; 
    
    cout << "\nrange[long int] : " << LONG_MIN << " -- " << LONG_MAX; 
    
    cout << "\nrange[unsigned long int] : " << 0 << " -- " << ULONG_MAX; 
    
    cout << "\nrange[long long int] : " << LLONG_MIN << " -- " << LLONG_MAX; 
    
    cout << "\nrange[unsigned long long int] : " << 0 << " -- " << ULLONG_MAX; 
  
    cout << "\nrange[float] : " << FLT_MIN << " -- " << FLT_MAX; 
    
    cout << "\nrange[negative float] : " << -FLT_MIN << " -- " << -FLT_MAX; 
    
    cout << "\nrange[double ranges] : " << DBL_MIN << " -- " << DBL_MAX; 
    
    cout << "\nrange[negative double] : " << -DBL_MIN << " -- " << DBL_MAX; 
   return 0; 
}
