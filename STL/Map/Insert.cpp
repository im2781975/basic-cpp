#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    map<int,string>mp;
 
    mp.insert(pair<int,string>(1,"A"));
    mp.insert(pair<int,string>(2,"B"));
    mp.insert(pair<int,string>(3,"C"));
 
    map<int,string>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        cout<<"Key: "<< it->first<<" "<<"Value: "<< it->second<<"\n";
    }
}
