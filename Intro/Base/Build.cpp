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
    
    double pi = 3.14159783;
    cout.precision(5);
    cout << pi << "\n";
 
    cout.precision(7);
    cout << pi << "\n";
    
    char gfg[]="ibrahim";
    char ch='e';
    cout.write(gfg, 6);
    cout.put(ch);
    cout<<"\n"<<gfg;
    return 0; 
}
