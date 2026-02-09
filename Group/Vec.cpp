#include <bits/stdc++.h>
using namespace std;
int main()
{
    typedef vector<int> vInt;
    // vec1 is a vectorof type int
    vInt v;
    v.push_back(190);
    v.push_back(180);
    v.push_back(10);
    v.push_back(10);
    v.push_back(27);
    cout<<"array element is: ";
    for (auto X : v)
    {
        cout << X << " ";
    }
    cout<<"\n";
//---------------------------------
    typedef unsigned long long int ulli;
    ulli a{ 1232133 };
    cout <<"after typedef element is: "<< a<<"\n";
//---------------------------------
//typedef ptr
    int x = 10;
    int y = 20;
    typedef int* iPtr;
  
    iPtr pointer_to_a = &x;
    iPtr pointer_to_b = &y;
  
    cout << "x is: " << *pointer_to_a << "\n";
    cout << "y is: " << *pointer_to_b << "\n";
  
    return 0;
}
