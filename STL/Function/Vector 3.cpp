#include <bits/stdc++.h>
#include <vector>
void print(vector<int>&vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
}
using namespace std;
int main()
{
    vector<int> vec;
    
    vec.assign(5, 10);
    cout <<"Imposed assign: ";
        print(vec);
         
    vec.push_back(15);
    cout << "\nImposed push_back(): ";
        print(vec);
    
    vec.pop_back();
    cout <<"\nImposed pop_back(): ";
        print(vec);
        
    vec.insert(vec.begin(), 5);
    cout << "\nImposed insert: " ;
        print(vec);
 
    vec.erase(vec.begin());
    cout <<"\nImposed erase(): ";
        print(vec);
 
    // inserts at the beginning
    vec.emplace(vec.begin(), 5);
    cout << "\nImposed emplace: " ;
        print(vec);
 
    // Inserts 20 at the end
    vec.emplace_back(20);
    cout << "\nImposed emplace_back: ";
        print(vec);
 
    vec.clear();
    cout << "\nAfter clear() size is: " << v.size()
    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
 
    cout << "\nVector 1: ";
        print(v1);
    cout << "\nVector 2: ";
        print(v2);
 
    v1.swap(v2);
    cout<<"\nAfter Swap Vector 1:";
        print(v1);
    cout<<"\nAfter Swap Vector 2:";
        print(v2);
}
