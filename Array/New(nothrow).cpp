#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int* p = NULL;
    
    //you can use "new (nothrow)" when allocating memory to prevent an exception from being thrown if the allocation fails for shortes memory in heap for continue the code.
    p = new(nothrow) int;
    if (!p)
        cout << "allocation of memory failed\n";
    else
    {
        *p = 29;
        cout << "Value of p: " << *p <<"\n";
    }
    
    float *r = new(nothrow) float(75.25);
    cout << "Value of r: " << *r << "\n";
    
    int n = 5;
    int *q = new(nothrow) int[n];
    if (!q)
        cout << "allocation of memory failed\n";
    else
    {
        for (int i = 0; i < n; i++)
            q[i] = i+1;
 
        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    delete p;
    delete r;
    delete[] q;
 
    return 0;
}

