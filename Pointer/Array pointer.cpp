#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *p;
    int *ptr[5];
    int arr[5];
    p = arr;
    for(int i=0; i<5; i++)
        ptr[i] = &arr[i];
    for(int i=0; i<5; i++)
    {
        cout << p << " " << ptr << "\n";
        p++;
    }
    cout << "sizeof(p): " << sizeof(p) << "\n";
    cout << "sizeof(*p): " << sizeof(*p) << "\n";
    cout << "sizeof(ptr): " << sizeof(ptr) << "\n";
    cout << "sizeof(*ptr): " << sizeof(*ptr) << "\n";
    
    int ar[3][4] = { {10, 11, 12, 13}, {20, 21, 22, 23}, 
        {30, 31, 32, 33} };
    int (*pr)[4];
    pr = ar;
    cout << "pr: " << pr << "\n";
    cout << "pr + 1: " << pr+1 << "\n";
    cout << "pr + 2: " << pr+2 << "\n";
    cout << "pr + 3: " << pr+3 << "\n";
    cout << "*pr: " << *pr << "\n";
    cout << "*(pr + 1): " << *(pr+1) << "\n";
    cout << "*(pr + 2): " << *(pr+2) << "\n";
    cout << "*(pr + 3): " << *(pr+3) << "\n";
    //First value of every row
    cout << "**pr: " << **pr << "\n";
    cout << "**(pr + 1): " << **(pr+1) << "\n";
    cout << "**(pr + 2): " << **(pr + 2) << "\n";
    
    cout << "*(*(pr +0) +2): " << *(*(pr +0) + 2) << "\n";
    cout << "**(pr + 2): " << **(pr + 2) << "\n";
    
    cout << "pr[0][0]: " << pr[0][0] << "\n";
    cout << "pr[1][1]: " << pr[1][1] << "\n";
    cout << "pr[2][2]: " << pr[2][2] << "\n";
}
