#include <bits/stdc++.h>
using namespace std;
int main()
{
    string::iterator itr;
    string::reverse_iterator rit;
    string s = "GeeksforGeeks";
    
    itr = s.begin();
    cout << "Pointing to the start of the string:"<< *itr<<"\n";
    
    itr = s.end() - 1;
    cout << "Pointing to the end of the string: "<<*itr<<"\n";
    
    rit = s.rbegin();
    cout << "Pointing to the last character of the string: " << *rit <<"\n";
    
    rit = s.rend() - 1;
    cout << "Pointing to the first character of the string: " << *rit <<"\n";
    return 0;
}
