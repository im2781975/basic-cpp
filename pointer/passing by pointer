#include <iostream>
using namespace std;
struct demo 
{
    int a;
};
 
int main()
{
    int x = 5;
    int y = 6;
    demo d;
 
    int* p;
    p = &x;
    p = &y; 
    int& r = x;
    r = y; 
 
    p = NULL;
    p++;
    r++;
 
    cout<< &p << " " << &x << '\n';
    cout<< &r << " " << &x << '\n'; 
    demo* q = &d;
    demo& ref = d;
 
    q->a = 8;
    ref.a = 8;

    cout << p << '\n';
    cout << r << '\n';
    return 0;
}
