#include<bits/stdc++.h>
using namespace std;

void func(int *x, int *y)
{
    *x = *x + *y;
    cout << "after sum: " << *x << " " << *y;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    cout << "after swap: " << *x << " " << *y;
}

int main()
{
    int x = 5, y = 7;
    func(&x, &y);
    cout << "\n";
    swap(&x, &y);
}


