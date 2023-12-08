//insert() | erase() | search() 
#include<bits/stdc++.h>
using namespace std;
void print(unordered_multimap<string,int>&ump)
{
    unordered_multimap<string,int>::iterator it;
    it=ump.begin();
    while(it!=ump.end())
    {
        cout<<"\nKey: "<<it->first<<" "<<"Value: "<<it->second;
        it++;
    }
}
int main()
{
    //unordered_multimap<string,int>ump{{"A",1},{"B",2},{"C",3},{"D",2},{"E",5},{"F",6},{"D",7}};
    
    unordered_multimap<string,int>ump;
    ump.insert(pair<string,int>("A",1));
    ump.insert(pair<string,int>("B",2));
    ump.insert(pair<string,int>("C",3));
    ump.insert(pair<string,int>("D",2));
    ump.insert(pair<string,int>("E",5));
    ump.insert(pair<string,int>("F",6));
    ump.insert(pair<string,int>("D",7));
    unordered_multimap<string,int>::iterator it;
    cout<<"\nmultimap elements are: ";
    print(ump);
    // Search for an element with value 1
    int n=1;
    it=ump.begin();
    cout<<"\nImposed search for value 1: ";
    while(it!=ump.end())
    {
        if(it->second==n)
        {
            break;
        }
        it++;
    }
    cout<<it->first;
    //Erase the element pointed by iterator it
    if(it!=ump.end())
    {
        ump.erase(it);
    }
    cout<<"\nImposed erase: ";
    print(ump);
}
