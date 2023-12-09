//value_type func
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    priority_queue<int>::value_type AnInt;
    priority_queue<string>::value_type AString;
  
    priority_queue<int> q1;
    priority_queue<string> q2;
  
    AnInt = 20;
    cout << "\nThe value_type is AnInt = " << AnInt;
    q1.push(AnInt);
    AnInt = 30;
    q1.push(AnInt);
    cout << "\nTop element of the integer priority_queue is: "<< q1.top() ;
  
    AString = "geek";
    cout <<"\nThe value_type is AString = "<< AString ;
         
    q2.push(AString);
    AString = "for";
    q2.push(AString);
    AString = "geeks";
    q2.push(AString);
  
    cout << "\nTop element of the string priority_queue is: "
         << q2.top() ;
  
    return 0;
}
