#include <bits/stdc++.h>
#include <vector>
using namespace std;
void print(vector<int>vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
}
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
    
    cout << "\nSize: " << vec.size();
    cout << "\nCapacity: " <<vec.capacity();
    cout << "\nMax_Size: " <<vec.max_size();
 
    vec.resize(4);
    cout << "\nAfter resize,Size is : "<< vec.size();
 
    if (vec.empty() == false)
    cout<<"\nVector isn't empty";
    else
    cout <<"\nVector is empty";
 
    vec.shrink_to_fit();
    cout<<"\nImposed shrink_to_fit(): ";
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
 
    cout << "\nOutput of begin and end: ";
    for (auto i =vec.begin(); i !=vec.end(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of cbegin and cend: ";
    for (auto i =vec.cbegin(); i != vec.cend(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of rbegin and rend: ";
    for (auto i = vec.rbegin(); i != vec.rend(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of crbegin and crend : ";
    for (auto i =vec.crbegin(); i != vec.crend(); ++i)
        cout << *i << " ";
        
    vec.clear();
    cout << "\nAfter clear() size is: " << vec.size();
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
        
    cout<<"\nImplemented Not2: ";
    sort(v1.begin(), v1.end(), not2(less<int>()));
    print(v1);
 
    v1.swap(v2);
    cout<<"\nAfter Swap Vector 1:";
        print(v1);
    cout<<"\nAfter Swap Vector 2:";
        print(v2);
    
}
