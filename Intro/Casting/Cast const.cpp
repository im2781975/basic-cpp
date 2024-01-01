// const_cast 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    const int number = 5; 
    const int* ptr = &number; 

    int* nonConstPtr = const_cast<int*>(ptr); 
    *nonConstPtr = 10; 
    cout << "Modified number: " << *nonConstPtr; 
  
    return 0; 
}
