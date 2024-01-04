#include<bits/stdc++.h>
using namespace std;
int main()
{
    auto int_=32;
    auto bool_=true;
    auto float_=21.89;
    auto ptr= &float_ ;
    
    cout<< typeid(int_).name() <<" \n";
    cout<<typeid(bool_).name() <<" \n";
    cout<<typeid(float_).name() <<" \n";
    cout<<typeid(ptr).name() <<" \n";
    
}
