#include <iostream>
#include <iterator>
#include <set>
using namespace std;
 
int main()
{
    set<int, greater<int> > s1;
 
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    s1.insert(50);
    s1.insert(10);
 
    set<int, greater<int> >::iterator itr;
    cout << "\nset s1 is : ";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    // assigning the elements from s1 to s
    set<int> s(s1.begin(), s1.end());
    cout << "\nset s after assign from s1 is : ";
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
 
    // remove all elements up to 30 in s2
    cout<<"\nset s after removal of elements less than 30:";
    s.erase(s.begin(),s.find(30));
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    int num;
    num = s.erase(50);
    cout <<"\ns.erase(50) : "<< num << "\nremoved: ";
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout<<"\ns1.lower_bound(40) : "<< *s1.lower_bound(40) ;
    
    cout<<"\ns1.upper_bound(40) : "<< *s1.upper_bound(40);

    cout<<"\ns.lower_bound(40) : "<< *s.lower_bound(40) ;
    
    cout<<"\ns.upper_bound(40) : "<< *s.upper_bound(40) ;
    cout<<"\ns.size(): "<<s.size();
    if(s.find(2)!=s.end())
        cout<<"\n2 found";
    else
        cout<<"\nNot found";
    return 0;
}
