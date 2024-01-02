#include <iostream>
#define mod 1000000007
#define lli long long int
using namespace std;
int main()
{
    long long int x, y, z;
    cout<<"Enter ingegers: ";
    cin >> x >> y >> z;
    //z = (z + x*y)%mod; 
    z = ((z%mod) + ((x%mod)*(y%mod))%mod) % mod;
    cout << z;
    
    lli a= 1e7;
    lli b= 1e7;
    lli c= 1LL*a*b;
    cout<<"\n" << c;
    
    return 0;
}

