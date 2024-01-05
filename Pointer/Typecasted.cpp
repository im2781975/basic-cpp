// (int*)ptr - does type casting of void
// *((int*)ptr) dereferences the typecasted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x = 4;
    float y = 5.5;
    char z ='c';
    void* ptr;
    ptr = &x;
    
    cout<<"Integer variable is: "<< *((int*)ptr)<<"\n";
 
    ptr = &y;
    cout<<"Float variable is: "<< *((float*)ptr)<<"\n";
    
    ptr= &z;
    cout<<"char variable is: "<<*((char*)ptr);
    return 0;
}
