//Insert() | bucket_count() | load_factor() | max_size() | size() 
#include <iostream> 
#include <unordered_set> 
using namespace std; 
int main() 
{ 
    unordered_set<int> s; 
 
    s.insert(1); 
    s.insert(11); 
    s.insert(111); 
    s.insert(12); 
    s.insert(13); 
    
    cout<<"\n size is: "<<s.size();
    cout <<"\nbucket_count is: "
         <<s.bucket_count();
    cout<<"\nload factor is: "<<s.load_factor() ;
    cout<<"\nMax size is: "<<s.max_size();
 
    s.insert(2); 
    s.insert(22); 
    
    cout<<"\nAfter insertion size is : "<<s.size() ;
    cout <<"\nAfter insertion bucket count is: " << s.bucket_count() ;
    cout <<"\nAfter insertion load factor is: " <<s.load_factor() ;
    return 0; 
} 
