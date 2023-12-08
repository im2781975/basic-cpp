#include <bits/stdc++.h>
using namespace std;

typedef unordered_multimap<string, int> unit;

void printUmm(unit umm) {
    unit::iterator it = umm.begin();
 
    for (; it != umm.end(); it++) {
        cout << "\n"<< it->first << " " << it->second ;
    }
}
int main() {
    unit umm1;
    
    unit umm2 = {
        {"A", 1 }, { "B", 2 },
        { "A", 10 }, { "C", 7 },
        { "D", 9 }, { "C", 6 },
        { "A", 1 } 
        
    };
    umm1 = umm2;
    cout<<"\nmultimap 1 is: ";
    printUmm(umm1);
 
    if (umm2.empty())
        cout << "\nmultimap 2 is empty";
    else
        cout << "\nmultimap 2 is'nt empty";
 
    cout << "\nSize of multimap 1 is " << umm1.size() ;
    
    string key = "A";
    unit::iterator it = umm1.find(key);
    if (it != umm1.end()) {
        cout << "\nkey '" << key << "' is there in multimap 1";
    } else {
        cout << "\nkey '" << key << "' isn't there in multimap 1";
    }
    // count returns the count of the total number of pairs
    int cnt = umm1.count(key);
    cout << "\ntotal values associated with '" << key
         << "' are " << cnt ;
    cout<<"\nmultimap 2 is: ";
    printUmm(umm2);
    umm2.insert(make_pair("D", 11));
    umm2.insert({ { "E", 12 }, { "F", 33 } });
    umm2.insert(pair<string,int>("G",11));
    cout << "\nAfter insertion :";
    printUmm(umm2);
 
    umm2.erase("A");
    cout << "\nAfter deletion of A: ";
    printUmm(umm2);

    umm1.clear();
    umm2.clear();
 
    if (umm2.empty())
        cout << "\nmultimap 2 is empty";
    else
        cout << "\nmultimap 2 is'nt empty";
}
