#include<bits/stdc++.h>
using namespace std;
void print(vector <int> v)
{
    for_each(v.begin(), v.end(), [](int i) {cout << i <<" ";});
}
int main()
{
    vector <int> vec{2, 3, 4, 5, 6};
    cout<<"\nElements of vector is: ";
    print(vec);
    
    auto p=find_if(vec.begin(), vec.end(), [](int i) {return i >5 ;});
    cout<<"\nSatisfied condition first element is: " << *p;
    cout<< "\nAfter sort vector is: ";
    sort(vec.begin(), vec.end(), [](const int &a, const int &b)->bool {return b < a;}
    );
    print(vec);
    int N=5;
    int count_N=count_if(vec.begin(), vec.end(), [](int i)
    {return i >=5;});
    cout <<"\nImplemented count_N: " << count_N;
    
    p =unique(vec.begin(), vec.end(), [](int a, int b){ return a==b;});
    cout<<"\nImplemented unique: ";
    print(vec);
    
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int f=accumulate(arr, arr+n, 1,[](int i, int j){return i*j ;});
    cout<<"\nImplemented factorial: " <<f;
    
    auto square=[](int i)
    {
        return i*i;
    };
    cout<<"\nImplemented square of N is: " <<square(N);
}
