#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10] = "aksh";
    char b[10] = "akash";
    int res = strncmp(a, b, 4);
    if (res == 0)
    cout<<"\na is equal to b up to numb characters";
    else if (res > 0)
        cout << "\na is greater than b" ;
    else
        cout << "\nb is greater than a" ;
        
    char* st1 = "GeeksforGeeks";
    char* st2 = "Geeks For Geeks";
    int value = strncmp(st1, st2, 5);
    if (!value) 
        cout << "The first 5 characters are same.";
    else
        cout << "The first 5 characters are not equal.";
   char name[100], add[100], about[100];
    cout << "\nName is: ";
    cin.getline(name, 100);
    cout << "\nAddress is: ";
    cin.getline(add, 100);
    cout << "\nDescribe yourself: ";
    cin.getline(about, 100);
    
    cout << "\nName is: " << name;
    cout << "\nAddress is: " << add;
    cout << "\nAbout is: " << about ;
    return 0;
}
