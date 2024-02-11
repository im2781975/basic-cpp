#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "\nEnter String: ";
    getline(cin,str);
    str.push_back('o');
    cout << "\nAfter push_back String is: " << str;
    str.pop_back();
    cout << "\nAfter pop_back original String is: " << str;
    cout << "\nLength of str is: " << str.length();
    cout << "\nCapacity of str is: " << str.capacity();
    str.resize(12, 'f');
    
    cout << "\nAfter resize str is: " << str ;
    cout << "\nAfter resize capacity is: " << str.capacity();
    cout << "\nsizeof String is: " << sizeof(str);
    str.shrink_to_fit();
    cout << "\nAfter shrink_to_fit capacity is: " << str.capacity();
}
