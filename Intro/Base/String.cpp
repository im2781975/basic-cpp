#include <iostream> 
#include <ios> 
#include <limits> 
using namespace std; 
int main() 
{ 
    int x; 
    char str[80]; 
    cout << "Enter a number and string:\n"; 
    cin >> x; 
  
    // clear buffer before taking  new line 
    cin.ignore();
    cin.getline(str, 80); 
    cout << "You have entered:\n"; 
    cout << x << "\n"; 
    cout << str << "\n"; 
  
    return 0; 
}
