#include<bits/stdc++.h>
using namespace std;
int n = 5;
int main()
{
    vector <int> v(5,3);
    for(int i=0; i<5-2; i++)
        v[i] = i;
        
    cout<<"Elements of vector are: ";
    for(int i=0; i<5; i++)
        cout<< v[i]<< " ";
        
    vector <int> vec(5,0);
    
    vec[1] = 5;
    vec.resize(10, 10);
    
    cout<<"\nFront elements are: " << vec.front()<<" ";
    cout<<"\n7th elements are: " <<vec[7] <<" ";
}
