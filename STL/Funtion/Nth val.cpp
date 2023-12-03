//nth_element 
#include <iostream> 
#include <algorithm> 
using namespace std; 
bool comp(int a, int b) 
{ 
    return (a < b); 
} 
int main() 
{ 
    int v[]{ 3, 2, 10, 45, 33, 56, 23, 47 }, i; 
    int n=sizeof(v) /sizeof( v[0]);
    
    cout<<"Before sort: ";
    for (i = 0; i < 8; ++i) 
        cout << v[i] << " "; 

    nth_element(v, v + 4, v + n); 
    // Since, n is 5 so 5th element should be sorted 
    cout<<"\nAfter sort v[5]: ";
    for (i = 0; i < 8; ++i) 
        cout << v[i] << " "; 
    
    nth_element(v, v + 5, v + n, comp); 
    cout<<"\nAfter sort v[6]: ";
    for (i = 0; i < 8; ++i) 
        cout << v[i] << " "; 
    
    nth_element(v, v + 2, v + n); 
    cout<<"\nAfter sort v[3]: ";
    for (i = 0; i < 3; ++i)  
        cout << v[i] << " "; 
    
    cout<<"\n2nd largest element is : ";
    nth_element(v, v + 1, v + 8, greater<int>()); 
    for (i = 0; i < 3; ++i)  
        cout << v[i] << " "; 
        
    return 0; 
} 
