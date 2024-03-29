//copy() | merge() | push_front() |insert_after() |  pop_front() | emplace_front() | remove() | remove_if() | erase_after() | clear() | sort() | unique() | splice_after() | assign()
#include<bits/stdc++.h>
using namespace std;
void print(forward_list<int>fl)
{
    forward_list<int>::iterator it=fl.begin();
    while(it!=fl.end())
    {
        cout<<*it<<" ";
        it++;
    }
}
int main()
{
    forward_list<int>list;
    forward_list<int>mist;
    forward_list<int>::iterator it;
    forward_list<int> list1;
    list1.assign({ 1, 2, 3 });
    
    forward_list<int> list2;
    list2.assign(5, 10);
    
    forward_list<int> list3;
    list3.assign(list1.begin(), list1.end());

    for(int i=1; i<=10; i++)
    {
        list.push_front(i);
    }
    list.push_front(14);
    cout<<"\nImposed copy(): ";
    mist=list;
    print(mist);
    
    cout<<"\nImpose splice_after list array: ";
    list.splice_after(list.begin(),mist);
    print(list);
    
    cout<<"\nImposed merge: ";
    list.merge(mist);
    print(list);
    cout<<"\nImposed push_front : ";
    print(list);
    
    list.sort();
    cout<<"\nImposed sort(): ";
    print(list);
    
    list.unique();
    cout<<"\nImposed unique(): ";
    print(list);
    
    it=list.insert_after(list.begin(),{1,2,3});
    cout<<"\nImposed Insert_after: ";
    print(list);
    
    cout<<"\nImposed pop_front: ";
    list.pop_front();
    print(list);
    
    cout<<"\nImposed emplaced_front: ";
    list.emplace_front(15);
    print(list);
    
    it=list.erase_after(it);
    cout<<"\nimposed erase_after: ";
    print(list);
    
    /*it=list.erase_after(list.begin(),list.end());
    cout<<"\nimposed erase_after: ";
    print(list);*/
    
    it=list.erase_after(it);
    cout<<"\nimposed erase_after: ";
    print(list);
    
    cout<<"\nImposed remove(): ";
    list.remove(5);
    print(list);
    
    cout<<"\nImposed remove_if: ";
    list.remove_if([](int x){return x>5;});
    print(list);

    list.clear();
    cout<<"\nImposed clear(): ";
    print(list);
}
