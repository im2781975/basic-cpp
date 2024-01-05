#include <iostream> 
#include <unordered_set> 
 
using namespace std; 
int main()
{ 
    unordered_set <string> uset; 
    uset.insert("Welcome"); 
    uset.insert("To"); 
    uset.insert("Here"); 

    auto itr1 = uset.cbegin();
    advance(itr1, 1);
    auto itr2 = uset.begin(); 
    cout << "First element in the container is: " << *itr1; 
    cout << "\nFirst element in the bucket is: " << *itr2; 
    cout <<"\nElements of uset is: ";
    for(auto it=uset.cbegin(); it!=uset.cend(); it++)
        cout <<*it <<" ";
    return 0; 
} 
