//push_front() | push_back() | size() | max_size() | at() | front() | back() | pop_front() | pop_back() | max_element() | min_element() | reverse() 
#include<bits/stdc++.h>
using namespace std;
void print(deque<int>dq)
{
    deque<int>::iterator it=dq.begin();
    while(it!=dq.end())
    {
        cout<<*it<<" ";
        it++;
    }
}
int main()
{
    deque<int>dq;
    for(int i=0; i<11; i++)
    {
        dq.push_front(i);
        dq.push_back(i+1);
    }
    print(dq);
    cout<<"\ndeque.size(): "<<dq.size();
    cout<<"\ndeque.max_size(): "<<dq.max_size();
    cout<<"\ndeque.at(): "<<dq.at(3);
    cout<<"\ndeque.front(): "<<dq.front();
    cout<<"\ndeque.back(): "<<dq.back();
    dq.pop_front();
    cout<<"\nAfter pop_front deque is: ";
    print(dq);
    cout<<"\nAfter pop_back deque is: ";
    dq.pop_back();
    print(dq);
    
    int max=*max_element(dq.begin(),dq.end());
    cout<<"\nMax element is: "<<max;
    int min=*min_element(dq.begin(),dq.end());
    cout<<"\nMin element is: "<<min;
    cout<<"\nAfter reverse deque is: ";
    reverse(dq.begin(),dq.end());
    print(dq);
}
