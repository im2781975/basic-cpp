//make_heap() | push_back() | push_heap() | pop_heap() | pop_back() | sort_heap()
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int>vect{9,1,4,7,2};
    make_heap(vect.begin(),vect.end());
    cout<<"After heap elements are: ";
    print(vect);
    
    vect.push_back(50);
    cout<<"\nAfter push_back heap is: ";
    print(vect);
    
    push_heap(vect.begin(),vect.end());
    cout<<"\nAfter push_heap heap is: ";
    print(vect);
    
    pop_heap(vect.begin(),vect.end());
    cout<<"\nAfter pop_heap heap is: ";
    print(vect);
    
    vect.pop_back();
    cout<<"\nAfter pop_back heap is: ";
    print(vect);
    
    sort_heap(vect.begin(),vect.end());
    cout<<"\nAfter sort_heap heap is: ";
    print(vect);
}
