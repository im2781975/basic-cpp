// static_cast to cast 'to and 
// from' the void pointer
#include <iostream> 
using namespace std; 
int main() 
{ 
    float f = 3.5; 
    int i=10;
    // using cast operator 
    int b = static_cast<int>(f); 
    void* v = static_cast<void*>(&i);
    int* ip = static_cast<int*>(v);
    cout << *ip<< "\n"<<b;
} 
