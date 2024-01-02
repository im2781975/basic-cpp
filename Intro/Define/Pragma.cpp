#include <bits/stdc++.h>
using namespace std;
void func1();
void func2();

#pragma startup func1
#pragma exit func2
 
void func1(){cout<<"func1()\n"; }
void func2(){cout << "func2()\n"; }
 
int main()
{
    void func1();
    void func2();
    cout << "Inside main()\n";
    return 0;
}
