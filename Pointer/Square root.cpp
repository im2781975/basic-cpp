#include<bits/stdc++.h>
using namespace std;
void fun(int n, int* square, double* sq_root)
{
    *square = n * n;
    *sq_root = sqrt(n);
    cout<< "Value is: " << *square<<" "<<*sq_root ;
    cout<< "\nAddress of the value is: " << square<<" "<< sq_root;
    
}
 
int main()
{
 
    int n = 100;
    int sq;
    double sq_root;
    fun(n, &sq, &sq_root);
    return 0;
}
