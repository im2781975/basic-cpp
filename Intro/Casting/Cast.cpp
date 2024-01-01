#include <iostream> 
using namespace std; 
int main() 
{ 
    int number = 10;
    int* numberPointer = &number; 
  
    // Reinterpreting the pointer as a char pointer 
    char* charPointer 
        = reinterpret_cast<char*>(numberPointer); 
    double* doublePointer=reinterpret_cast<double*>(doublePointer);
    
    cout << "\nInteger Address: " << numberPointer ; 
    cout << "\nChar Address: "
         << reinterpret_cast<void*>(charPointer) ;
    cout<<"\nDouble pointer: "<<doublePointer ;
    
    const int a = 5; 
    const int* ptr = &a; 

    int* nonConstPtr = const_cast<int*>(ptr); 
    *nonConstPtr = 10; 
    cout << "\nModified number: " << *nonConstPtr <<"\n";
    
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << "\n";
    cout << *ch << "\n";
    cout << p << "\n";
    cout << ch << "\n";
    return 0; 
}
