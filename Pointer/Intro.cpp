#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v[3] = { 10, 100, 200 };
    int* ptr;
    ptr = v;
    
    cout << "Elements of the array are: ";
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2];
    cout<<"\n";
    
    for (int i = 0; i < 3; i++) {
        cout << "address of ptr = " << ptr << "\n";
        cout << "Value at *ptr = " << *ptr << "\n";
        ptr++;
    }
}
