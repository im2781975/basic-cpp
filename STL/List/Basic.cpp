#include<bits/stdc++.h>
using namespace std;
void print(list<int>& l) {
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
}
int main() {
    list<int> l1, l2;
    for (int i = 1; i < 10; i++) {
        l1.push_back(i * 2);
        l2.push_back(i * 3);
    }
    
    cout << "1st list is: ";
    print(l1);
    
    cout << "\n2nd list is: ";
    print(l2);
    
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
    
    cout << "\nimposed reverse(): ";
    l1.reverse();
    print(l1);
    
    cout << "\nimposed sort(): ";
    l1.sort();
    print(l1);
}
