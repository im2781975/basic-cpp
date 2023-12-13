#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a < b);
}
void print(vector<int>vec)
{
    vector<int>::iterator it;
    for(it=vec.begin(); it!=vec.end(); it++)
        cout<<*it<<" ";
}
int main()
{
    vector<int> vec = { 1, 1, 3, 10, 3, 3, 7, 7, 8 }, v(3),cev(7); 
    vector<int>::iterator it;
    partial_sort(vec.begin(), vec.begin()+7, vec.end());
    cout<<"\nImposed partial sort: ";
    print(vec);
    
    partial_sort(vec.begin(), vec.begin()+7, vec.end(), greater<int>());
    cout<<"\nImposed desc partial sort: ";
    print(vec);
    
    cout<<"\nLargest element is: ";
    it=vec.begin();
    cout<<*it;
    
    v.resize(vec.size());
    partial_sort_copy(vec.begin(), vec.end(), v.begin(), v.end());
    
    //partial_sort_copy(vec.begin(), vec.end(), v.begin(), v.end());
    cout<<"\nImposed partial_sort_copy: ";
    print(v);
    
    cev.resize(vec.size());
    cev=vec;
    partial_sort(vec.begin(), vec.begin() + 2, vec.end());
    sort(cev.begin(), cev.begin()+2);
    cout<<"\nImposed partial_sort(range),vec is: ";
    print(vec);
    cout<<"\nImposed partial_sort(range),cev is: ";
    print(cev);
}
