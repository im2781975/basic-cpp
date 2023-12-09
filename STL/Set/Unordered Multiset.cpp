#include <bits/stdc++.h> 
using namespace std; 
 
typedef unordered_multiset<int>::iterator umit; 

void erase_one_entry(unordered_multiset<int>& ums,
                    int val)
{
    umit it = ums.find(val);
    
    if (it != ums.end())
       ums.erase(it);
}
void printUset(unordered_multiset<int> ums) 
{ 
    umit it = ums.begin(); 
    for (; it != ums.end(); it++) 
        cout << *it << " "; 
} 
int main() 
{ 
    unordered_multiset<int> ums1; 
    unordered_multiset<int> ums2( 
        {1,3,1,7, 2, 3, 4, 1, 6}); 
    ums1={ 2, 7, 2, 5, 0, 3, 7, 5}; 
    if (ums1.empty()) 
        cout << "\nunordered multiset 1 is empty"; 
    else
        cout << "\nunordered multiset1 isn't empty"; 
    cout << "\nSize of unordered multiset 2 is : "<< ums2.size();
    printUset(ums1); 
  
    ums1.insert(7); 
    printUset(ums1); 
  
    int val = 3; 
    if (ums1.find(val) != ums1.end()) 
        cout << "\nunordered multiset 1 contains " << val;
    else
        cout << "\nunordered multiset 1 does not contains " << val;
  
    val = 5; 
    int cnt = ums1.count(val); 
    cout <<"\n"<<val << " appears " <<cnt << " times in unordered multiset 1";
  
    val = 9; 
    //  if count return >0 value then element exist 
    //  otherwise not 
    if (ums1.count(val)) 
        cout<<"\nunordered multiset 1 contains " << val;
    else
        cout <<"\nunordered multiset 1 does not contains "
             << val;
  
    val = 1; 
    // equal_range returns a pair, where first is iterator 
    // to first position of val and second it iterator to 
    // last position to val 
    pair<umit, umit> erange_it = ums2.equal_range(val); 
    if (erange_it.first != erange_it.second) 
        cout << val << "\nappeared atleast once in unoredered _multiset: ";
  
    printUset(ums2); 
    ums2.erase(val);
    printUset(ums2); 
    erase_one_entry(ums1, val);
    printUset(ums1);
    ums1.clear(); 
    ums2.clear(); 
 
    if (ums1.empty()) 
        cout << "\nunordered multiset 1 is empty";
    else
        cout<<"\nunordered multiset 1 is not empty";
}
