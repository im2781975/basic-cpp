//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int count(char a[])
{
    int cnt=0,i=0;
    while(a[i]!='\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}
void print(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        cout<<a[i];
        i++;
    }
}
int main()
{
    char a[] ="ABCDE";
    char b[] ="abcde";
    int n=count(a);
    int x=n;
    if(lexicographical_compare( a, a+x, b, b+x))
    {
        cout<<"\nElements of a is: ";
        print(a);
        cout<<"\nElements of b is: ";
        print(b);
    }
    else
        cout<< "\ndoesn't match";
        
    char list[][100]={
        {'a','b','a','c','u','s'},
        {'a','p','p','l','e'},
        {'c','a','r'},
        {'a','b','b','a'}
    };
    char min[100] = "zzzzzz";
    for (int i=0; i<4; i++)
    { 
        //list,list+n,min,min+n
        //if( lexicographical_compare(list[i], list[i] + strlen(list[i]), min, min+strlen(min)))
        if( lexicographical_compare(list[i], list[i] 
        + count(list[i]), min, min+count(min)))
        {
            strcpy(min,list[i]);
        }
    }
    cout << "\nsmallest string is : ";
    for(int i = 0; min[i]!='\0'; i++)
    {
        cout<<min[i];
    }
}
