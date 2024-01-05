#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set <int> uset;
    uset.insert({10, 20, 30});
    auto it= uset.equal_range(20);
    
    if(it.first!=uset.end())
    {
        for(;it.first!=it.second; ++it.first)
            cout<< *it.first <<" ";
    }
    else
    {
        cout<< "Doesn't exit";
    }
}
