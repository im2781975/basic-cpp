//emplace() | emplace_back() | emplace_front()
#include<bits/stdc++.h>
using namespace std;
int deleteElement(list<int>& l, int value)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end();)
    {
        if (*it == value)
            it = l.erase(it);
        else
            ++it;
    }
}
void print(list<int>l)
{
    list<int>::iterator it=l.begin();
    while(it!=l.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout << "\n";
}
int main()
{
    list<int>List;
    list<int>::iterator it=List.begin();
    for(int i=1; i<10; i++)
        List.emplace_back(i);
    
    cout<<"Imposed emplace_back(): ";
    print(List);
    for(int i=2; i<10; i++)
        List.emplace_front(i);
    
    cout<<"\nImposed emplace_front(): ";
    print(List);
    
    advance(it,2);
    List.emplace(it,100);
    
    cout<<"\nAfter emplace list is: ";
    print(List);
    deleteElement(List, 100);
    print(List);
}


