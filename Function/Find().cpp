#include <iostream> 
#include <string> 
#include <unordered_set> 
 
using namespace std; 
int main() 
{ 
    unordered_set <string> uset={"geeks1","for","geeks2"}; 
    if (uset.find("geeks1") != uset.end()) 
        cout<<"\nElement found" ;
    else 
        cout << "\nElement not found" ;
    
    unordered_set<string>::hasher fn = uset.hash_function();
    
    cout << fn("geeks") << endl; 
    for (auto it = uset.begin(); it != uset.end(); it++) { 
        cout << *it << " "; 
    }

    return 0; 
} 
