#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a < b)? a: b)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
int main()
{
    int i;
    int array[] = {4, 5, 6, 9, 22, 11};
    int size= sizeof(array)/sizeof(array[0]);
    
    rep(i, size)     
        cout << array[i] << " ";
    cout<<"\n";
     
    REP(i, 1, size-1)     
        cout << array[i] << " ";
    cout<<"\n";
    
    REPR(i, size-1,0)     
        cout << array[i] << " ";
        
    int a =2, b=5;
    cout<<"\nMinimum element is: "<<min(a, b);
    
    return 0;
}
