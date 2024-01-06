#include <bits/stdc++.h>
using namespace std;
void fun(char *a)
{
    cout << "non-const fun() " << a;
}
void fun(const char *a)
{
    cout << "const fun() " << a;
}
int main()
{
    const char *ptr = "GeeksforGeeks";
    fun(ptr);
    return 0;
}
