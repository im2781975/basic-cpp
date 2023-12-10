//insert() 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display_elements(unordered_set<int> &uset) 
{
    unordered_set<int>::iterator it;
    for(it=uset.begin(); it!=uset.end(); it++)
    {
        cout<<*it<<" ";
    }
}
int main() 
{
    unordered_set<int>uset;
    
    //Inserts the value 1 into the unordered set. The insert function returns a pair where the first element is an iterator pointing to the inserted element (or the existing one if the value is already present), and the second element is a boolean indicating whether the insertion was successful.
    cout<<"\nuset.insert(1).second:  "<<uset.insert(1).second ;
    
    //first is the iterator to the inseted element, if the element not present in the uset, 
      cout<<"\n*(uset.insert(1).first): "<<*(uset.insert(1) .first) ;

    //if the element already in the uset, then it points to that element
    cout<<"\nuset.insert(1).second:  "<<uset.insert(1).second ;

      cout<<"\n*(uset.insert(1).first): "<<*(uset.insert(1).first) ;

    cout<<"\nuset.insert(2).second: "<<uset.insert(2).second ;
    
    //on successful insertion it's true else false.

      cout<<"\n*(uset.insert(2).first): "<<*(uset.insert(2).first) ;
      
    cout<<"\nelements are the unordered set : ";
      display_elements(uset);

      return 0;
}
