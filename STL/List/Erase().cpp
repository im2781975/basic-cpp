//erase()
#include <bits/stdc++.h>
using namespace std;

int deleteElement(list<int>& l, int value)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end();)
    {
        if (*it == value)
            it = l.erase(it);
        else
            ++it;
    }
}
int main()
{
    list<int> l;
    int n = 10;
    list<int>::iterator it;
    for (int i = 1; i < n; i++)
    {
        l.emplace_front(i);
    }
    deleteElement(l, n / 2);

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
}
