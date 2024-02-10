#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[] = "Ibrahim";
    cout <<"\nchar array is: "<<s ;

    string str("GeeksforGeeks");
    cout << "\nstr is :" <<str ;
    
    string g(5, 'g');
    cout << "\na: "<< g;

    char s1[]{'g', 'f', 'g', '\0'};
    char s2[4]{'g', 'f', 'g','\0'};
    char s3[4] = "gfg";
 
    cout << "\ns1 : " << s1 ;
    cout << "\ns2 : " << s2 ;
    cout << "\ns3 : " << s3 ;
    
    string st;
    cout << "\nEnter String: ";
    getline(cin,st);
    cout <<" \nString is :" << st ;
    
    //string obj is used for take multiple string.
    string a = " GeeksforGeeks to the Moon ";
    stringstream obj(a);
    // string to store words individually.
    string temp;
    cout << "\n" ;
    while (obj >> temp) {
        cout << temp << " ";
    }
    string x = "Geeksforgeeks";
    char* p = &x[0];

    while (*p != '\0') {
        cout << *p << " ";
        p++;
    }
    cout <<"\n";
    
    string b;
    cout<<"Enter string: ";
    while (getline(cin, b))
    {
        if (b.empty())
            break;
        cout << b << " ";
    }
    return 0;
}
