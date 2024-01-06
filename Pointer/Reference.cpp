#include<iostream>
using namespace std;
void fun(const int &i)
{
    cout << "fun(const int &) called ";
}
void fun(int &i)
{
    cout << "fun(int &) called " ;
}
int main()
{
    const int i = 10;
    fun(i);
    int x = 10;
    int& ref = x;
    ref = 20;
    cout << "\nx = " << x ;
    // Value of x is now changed to 30
    x = 30;
    cout << "\nref = " << ref ;
    return 0;
}
