#include <iostream>
using namespace std;
void f1() 
{
    cout << "\n f1() Start ";
    throw 100;
    cout << "\n f1() End ";
}
void f2()
{
    cout << "\n f2() Start ";
    f1();
    cout << "\n f2() End ";
}
void f3()
{
    cout << "\n f3() Start ";
    try {
        f2();
    }
    catch (int i) {
        cout << "\n Caught Exception: " << i;
    }
    cout << "\n f3() End";
}
int main()
{
    f3();
    getchar();
    return 0;
}

