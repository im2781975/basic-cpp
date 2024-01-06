#include <cstring> 
#include <iostream> 
using namespace std; 
int main() 
{ 
    int num = 5; 
    float* ptr; 
  
    ptr = new float[num]; 
    for (int i = 0; i < num; ++i) 
        *(ptr + i) = i; 
  
    cout << "Display the GPA of students:\n"; 
    for (int i = 0; i < num; ++i) 
        cout << "Student " << i + 1 << "->" << *(ptr + i) << "\n";
        
    delete[] ptr; 
    return 0; 
}
