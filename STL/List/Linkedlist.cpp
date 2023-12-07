#include<bits/stdc++.h>
using namespace std;
int get_value(list<int>&ld,int idx)
{
    list<int>::iterator it=ld.begin();
    while(it!=ld.end())
    {
        if(*it==idx)
        {
            return *it;
        }
        ++it;
    }
    return -1;
}
bool search(list<int>&ld,int value)
{
    list<int>::iterator it;
    it=ld.begin();
    while(it!=ld.end())
    {
        if(*it==value)
        return true;
        it++;
    }
    return false;
}
int main()
{
    list<int>ld;
    vector<int>::iterator it;
    for(int i=0; i<10; i++)
    {
        ld.push_back(i);
    }
    int idx =3;
    int result=get_value(ld,idx);
    cout<<result;
    
    int value=5;
    if(search(ld,value))
        cout<<"\ntrue";
    else
        cout<<"\nfalse";
        
    ld.remove(0);
    for(it=ld.begin(); it!=ld.end(); it++)
    {
        cout<<*it<<" ";
    }
}
