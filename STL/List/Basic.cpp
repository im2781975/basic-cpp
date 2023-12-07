//front() | back() | push_front() | push_back() | pop_front() | pop_back() | reverse() | sort() insert() | Delete() |remove_if() |unique() | swap() | splice() 
#include<bits/stdc++.h>
using namespace std;
void print(list<int>& l) {
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
}

/*void print(list<int>&l)
{
    list<int>::iterator it;
    it=l.begin();
    while(it!=l.end())
    {
        cout<<*it<<" ";
        it++;
    }
} */

void Insert(list<int>&l, int index , int value)
{
    auto it=l.begin();
    advance(it,index);
    l.insert(it,value);
}

void Delete(list<int>&l , int index)
{
    auto it = l.begin();
    advance(it , index);
    l.erase(it);
}
int main() {
    list<int> l1, l2;
    list<int>::iterator it;
    for (int i = 1; i < 10; i++) {
        l1.push_back(i * 2);
        l2.push_back(i * 3);
    }
    
    cout << "1st list is: ";
    print(l1);
    
    cout << "\n2nd list is: ";
    print(l2);
    
    l1.swap(l2);
    cout<<"\nImposed swap() l1: ";
    print(l1);
    
    cout<<"\nImposed swap() l2: ";
    print(l2);
    
    it=l1.begin();
    advance(it,2);
    l1.unique();
    cout<<"\nImposed unique: ";
    print(l1);
    
    l1.splice(it,l2);
    cout<<"\nImposed splice: ";
    print(l1); 
    cout << "\nlist1 front: " << l1.front();
    cout << "\nlist1 back: " << l1.back();
    
    cout << "\nimposed pop_front(): ";
    l1.pop_front();
    print(l1);
    
    cout << "\nimposed pop_back(): ";
    l1.pop_back();
    print(l1);
    
    cout << "\nimposed push_front(): ";
    l1.push_front(15);
    print(l1);
    
    cout << "\nimposed push_back(): ";
    l1.push_back(15);
    print(l1);
    
    cout << "\nimposed insert(): ";
    Insert(l1,1,100);
    print(l1);
    
    cout << "\nimposed Delete(): ";
    Delete(l1,2);
    print(l1);
    
    cout << "\nimposed reverse(): ";
    l1.reverse();
    print(l1);
    
    cout << "\nimposed sort(): ";
    l1.sort();
    print(l1);
    
    cout<<"\nImposed remove_if(): ";
    l1.remove_if([](int x){return x%2!=0;});
    print(l1);
    
    cout<<"\nSize of list 1 is: "<<l1.size();
}
