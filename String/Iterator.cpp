#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
    
    string::iterator it;
    string::reverse_iterator ip;
    cout << "\nString is: " << str ;
    
    cout << "\nString using forward iterators is : ";
    for (it = str.begin(); it != str.end(); it++){
        if(it == str.begin()) 
            *it='G';
        cout << *it;
    }

    cout << "\nString using reverse iterators is : ";
    for (ip = str.rbegin(); ip != str.rend(); ip++){
        if(ip == str.rbegin()) 
            *ip='S';
        cout << *ip;
    }

    cout << "\nString using constant forward iterator is :";
    for(auto pt = str.cbegin(); pt!=str.cend(); pt++){
    //if(it2 == str.cbegin()) 
        //*it2='G';
    //In the case of constant iterator modification isn't possible.Only increament & decreament is possible.
        cout << *pt;
    }
 
    cout << "\nString using constant reverse iterator is :";
    for(auto it1 = str.crbegin(); it1!=str.crend(); it1++)
        cout<<*it1;
    
    return 0;
}
