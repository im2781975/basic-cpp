#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[] = "GeeksforGeeks";
    char s2[] = "for";
    char* result;
    result = strstr(s1, s2);
  
    if (result != NULL) 
        cout << "\nSubstring found :" << result;
    else 
        cout << "\nSubstring not found";
    string str = "Geeks";
    //copy of two char startin from pos 3
    string r = str.substr(3, 2);
    cout << "\nString is: "<<r;
    
    string s = "dog:cat";
    int pos = s.find(":");

    string sub1 = s.substr(pos + 1);
    string sub2 = s.substr(0, pos);
    
    cout << "\nAfter colone String is: " << sub1;
    cout << "\nBefore colone String is: " << sub2;
    return 0;
}
