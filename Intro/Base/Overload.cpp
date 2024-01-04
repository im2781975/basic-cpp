#include<bits/stdc++.h>
using namespace std;
void foo(char c)
{
   cout<<"From foo: char"<<"\n";
}
void foo(int i)
{
   cout<<"From foo: int"<<"\n";
}
int main()
{
   foo('V');
   foo(89);
   return 0;
}
