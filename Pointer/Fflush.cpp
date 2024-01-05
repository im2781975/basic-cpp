#include <iostream>
using namespace std;
int *fun()
{
    static int x = 5;
    return &x;
}
int main()
{
    int *p = fun();
    fflush(stdin);
    cout << *p;
    return 0;
}
