// remove() | remove_if() | remove_copy_if() 
//remove_copy() | erase() | // replace() | replace_if() | replace_copy() | replace_copy_if()
#include <bits/stdc++.h>
using namespace std;
bool IsOdd(int i) 
 { return ((i % 2) == 1); }
 
void print(vector<int>&vect)
{
    int len=vect.size();
    for(int i=0; i<len; i++)
        cout<<vect[i]<<" ";
}
void print(int arr[],int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    vector<int> vect1{10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> vect2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
    cout << "vect1 is : ";
    print(vect1);
 
    vector<int>::iterator it;
    vector<int>::iterator pt;
    it = remove(vect1.begin(), vect1.end(), 20);
 
    cout << "\nAfter remove vect1 is: ";
    for (pt =vect1.begin(); pt!= it; ++pt)
        cout << ' ' << *pt;

    cout << "\nvect2 is : ";
    print(vect2);
    
    remove_copy(vect1.begin(),vect1.end(),vect1.begin(),30);
    
    cout<<"\nAfter romove_copy vect1 is: ";
    print(vect1);
    
    //it =remove_if(vec2.begin(), vec2.end(), IsOdd);
    it = remove_if(vect2.begin(), vect2.end(),[](int i) { return ((i % 2) == 1); });
 
    cout << "\nAfter remove_if vect2 is: ";
    for (pt=vect2.begin(); pt != it; ++pt)
        cout << ' ' << *pt;
        
    remove_copy_if(vect2.begin(), vect2.end(),vect2.begin(),IsOdd);
    cout<<"\nAfter romove_copy_if vect2 is: ";
    print(vect2);
    
    remove_copy_if(vect1.begin(), vect1.end(),vect1.begin(),IsOdd);
    cout<<"\nAfter romove_copy_if vect1 is: ";
    print(vect1);
    
   vect1.erase(find(vect1.begin(),vect1.end(),10));
    cout << "\nVector after erasing element: ";
    for (int i = 0; i < vect1.size(); i++)
        cout << vect1[i] << " ";
        
int arr[]{ 10, 20, 30, 30, 20, 10, 10, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int Old = 20, New = 99;
 
    cout <<"\nBefore replace arr is:";
    print(arr,n);
 
    replace(arr, arr + n, Old, New);
    cout<<"\nAfter replace arr is:";
    print(arr,n);
 
    replace_if(arr, arr + n, IsOdd, New);

    cout<<"\nAfter replace_if arr is: ";
    print(arr,n);
    
    vector<char>vect;
    for(int i=0; i<n; i++)
        vect.push_back('A'+i);
        
    cout<<"\nBefore replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
        
    replace_copy(vect.begin(), vect.begin()+1,vect.begin(), 'A', 'Z' );
    
    cout<<"\nAfter replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
    
    vector<int>vec(arr,arr+n);
    vector<int>cev ;
    for(int i=0; i<n; i++)
        cev.push_back(i);
        
    cout<<"\nBefore replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nBefore replace_copy_if vec is : ";
    print(vec);
    
    replace_copy_if(vec.begin(),vec.end(),cev.begin(),IsOdd,-1);
            
    cout<<"\nAfter replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nAfter replace_copy_if vec is : ";
    print(vec);
    return 0;
}
//reverse() | reverse_copy() | Rotate() | Rotate_copy()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
    int len=v.size();
    for(int i=0; i<len; i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    vector<int> vect;
    vector<int>::iterator it;

    for (int i = 0; i < 8; i++) {
        vect.push_back(i + 10);
    }

    cout << "Initial Vector:";
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    cout << "\nAfter reverse specific vect is: ";

    reverse(vect.begin() + 5, vect.begin() + 8);
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    cout << "\nAfter reverse specific vect is: ";

    reverse(vect.begin(), vect.end());
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    vector<int> src(vect.size());
    reverse_copy(vect.begin(), vect.end(), src.begin());

    cout << "\nAfter remove_copy vect is: ";
    for (int i = 0; i < src.size(); i++) {
        cout << src[i] << " ";
    }

    cout << "\nVector is: ";
    print(vect);

    int rotL = 3;
    rotate(vect.begin(), vect.begin() + rotL, vect.end());
    cout << "\nVector after rotation: ";
    print(vect);

    int rotR = 5;
    rotate(vect.begin(), vect.begin() + vect.size() - rotR, vect.end());
    cout << "\nNew vector after right rotation: ";
    print(vect);

    vector<int> cev(7);
    rotate_copy(vect.begin(), vect.begin() + 3, vect.end(), cev.begin());

    cout << "\ncev[] contains:";
    for (auto i = cev.begin(); i != cev.end(); i++)
        cout << ' ' << *i;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

void suffle(int arr[], int n)
{
    random_shuffle(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int random_suffle(int j)
{
    return rand() % j;
}

bool pred(int i, int j)
{
    return i == j;
}

int main()
{
    srand(unsigned(time(0)));
    int ar[] = {10, 20, 30, 40, 50};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "After impose shuffle using array: ";
    suffle(ar, n);

    vector<int> arr(ar, ar + n);
    vector<int>::iterator it;
    random_shuffle(arr.begin(), arr.end(), random_suffle);
    cout << "\nAfter impose shuffle using vector: ";
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    array<int, 5> s{1, 2, 3, 4, 5};
    unsigned seed = 0;

    shuffle(s.begin(), s.end(), default_random_engine(seed));

    cout << "\nAfter impose shuffle using vector array: ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    int v2 = 3;
    vector<int> v1 = {1, 2, 3, 4, 5, 3, 3, 6, 7};

    vector<int>::iterator i1;

    i1 = search_n(v1.begin(), v1.end(), 2, v2, pred);

    if (i1 != v1.end())
    {
        cout << "\nv2 is present consecutively 2 times at index "
             << (i1 - v1.begin());
    }
    else
    {
        cout << "\nv2 is not present consecutively 2 times "
             << "in vector v1";
    }

    vector<int> v3 = {3, 4};

    i1 = search(v1.begin(), v1.end(), v3.begin(), v3.end());

    if (i1 != v1.end())
    {
        cout << "\nvector3 is present firstly at index "
             << (i1 - v1.begin());
    }
    else
    {
        cout << "\nvector3 is not present in vector1 ";
    }

    i1 = find_end(v1.begin(), v1.end(), v3.begin(), v3.end());

    if (i1 != v1.end())
    {
        cout << "\nvector3 is present lastly at index " << (i1 - v1.begin());
    }
    else
    {
        cout << "\nvector3 is not present in vector1";
    }
    return 0;
}
// unique() | unique_copy()
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
bool Pred(char a, char b)
{
    if (a == b && a == 'v') 
        return 1;

    else
        return 0;

}
int main()
{
    vector<int> vect{ 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
    int n=vect.size();
    vector<int>::iterator it;
    sort(vect.begin(), vect.end());
    
    vector<int> cev;
    cev.resize(n);

    it = unique_copy(vect.begin(), vect.end(), cev.begin());
    cev.resize(distance(cev.begin(), it)); // Resize cev to remove unused elements
    cout<<"Before impose unique_copy vect is: ";
    for (it = vect.begin(); it != vect.end(); it++)
    {
        cout << *it <<" ";
    }
    cout<<"\nAfter impose unique_copy cev is: ";
    for (it = cev.begin(); it != cev.end(); it++)
    {
        cout << *it << " ";
    }
    
    it =unique(vect.begin(), vect.begin() + 12);
    
    vect.resize(distance(vect.begin(), it));
    cout<<"\nAfter impose unique vect is: ";
    for (it = vect.begin(); it != vect.end(); ++it) {
        cout << *it << " ";
    }
    
    int count =distance(vect.begin(), unique(vect.begin(), vect.begin() + 12));
    cout << "\nTotal no. of unique elements are: " << count;
    
   vect.erase(unique(vect.begin(), vect.end()),
               vect.end());
    cout << "\nVector after removing duplicates: ";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
        
    string s = "You arre vvvisiting GFG", s1;
    auto ip = unique_copy(s.begin(), s.end(), back_inserter(s1), Pred);
 
    cout << "\nBefore unique_copy string is: " << s;
    cout << "\nAfter unique_copy string is: " << s1;
    
    auto pi=unique(s.begin(), s.end(), Pred);
    cout << "\nAfter unique string is: " << s;
    cout << string(s.begin(), pi);
    cout << "\nAfter unique string is: " << s;
    return 0;
}
// apply() | sum() | swap() | shift() | cshift
#include<iostream>
#include<valarray> 
using namespace std;
void print(valarray<int>val)
{
    for(int i=0; i<val.size(); i++)
    {
        cout<<val[i]<<" ";
    }
}
int main()
{
    valarray<int> varr = { 10, 2, 20, 1, 30 };
    valarray<int> varr1, varr2, varr3, varr4;
    
    varr1 = varr.apply([](int x){return x=x+5;});

    cout << "\nImposed apply(),varr1 is: ";
    print(varr1);
    cout << "\nSum of varr is: " <<varr.sum();

    cout << "\nSum of varr1 is: "<<varr1.sum();
    
    cout<<"\nBefore swap varr is: ";
    print(varr);
    cout<<"\nBefore swap varr1 is: ";
    print(varr1);
    
    //varr.swap(varr1);
    swap(varr,varr1);
    cout<<"\nAfter swap varr is: ";
    print(varr);
    cout<<"\nAfter swap varr1 is: ";
    print(varr1);
    
    varr2 = varr.shift(-2);
    varr3 = varr.cshift(-3);
    varr4 = varr.cshift(3);
    cout<<"\nAfter shift varr2 is: ";
    print(varr2);
    cout<<"\nAfter cshift varr3 is: ";
    print(varr3);
    cout<<"\nAfter cshift varr4 is: ";
    print(varr4);
    
    return 0; 
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    vector<int> vec;

    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    int sz = vec.size();
    cout<<"\nElement of vector are: ";
    for(int i = 0; i < sz; i++)
    {
        cout << vec[i] << " ";
    }

    int first_element = vec.front();
    cout << "\nFirst element of vect are: "<<first_element;

    int last_element = vec.back();
    cout << "\nLast element of vect are: " <<last_element ;

    cout<<"\nAfter erasing last element vect are: ";
    vec.pop_back();
    sz = vec.size();
    for(int i = 0; i < sz; i++)
        cout << vec[i] << " ";

    cout <<"\nSize of the vector are: " <<sz ;
    
    cout<<"\nWith using loop & pop elements are: ";
    while(!vec.empty())
    {
        cout << vec.back() << " ";
        vec.pop_back();
    }

    // Resize the vector and display elements
    cout<<"\nAfter resize elements are: ";
    vec.resize(10, 1);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    // Clear the vector
    vec.clear();
    sz = vec.size();
    cout<< "\nAfter clear sz is: "<<sz ;

    // Check if the vector is empty
    int emp = vec.empty();
    cout << "\nis empty: "<<emp ;
    vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i * 10);
 
    cout <<"Elements of v[2] :" <<v[2] ;
    cout << "\nElements of v.at(4) : " << v.at(4) ;
    cout << "\nElements of v.front() : " << v.front() ;
    cout << "\nElements of v.back() : " << v.back();
    // pointer to the first element
    int* pos = v.data();
    cout << "\nThe first element is " << *pos;
    
   vector< pair <int,int> > vect;
 
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int x = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<x; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );
 
    for (int i=0; i<x; i++)
    {
        cout<< "\n";
        cout << vect[i].first <<" "
             << vect[i].second;
    }
    return 0;
}
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
//set_difference() | set_symmetrric_difference() | set_union() | set_intersection()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main()
{
    int arr[]{5, 4, 1, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    vector<int> cev{3, 2, 1, 4, 0, 2};
    vector<int> vect(vec.size()+cev.size());
    vector<int> tcev(vec.size()+cev.size());
    vector<int> union_vec(vec.size()+cev.size());
    vector<int> intersec_vec(vec.size()+cev.size());

    cout << "Vec is: ";
    print(vec);
    cout << "\ncev is: ";
    print(cev);

    vector<int>::iterator it = set_symmetric_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), vect.begin());
    vect.resize(it - vect.begin());

    cout << "\nImposed set_symmetric_difference vect is: ";
    for(it = vect.begin(); it != vect.end(); it++)
        cout << *it << " ";

    cout << "\nImposed set_difference: ";
    vector<int>::iterator pt = set_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tcev.begin());
    tcev.resize(pt - tcev.begin());
    for(pt = tcev.begin(); pt != tcev.end(); pt++)
        cout << *pt << " ";
        
    cout << "\nImposed set_union: ";
    vector<int>::iterator ip = set_union(vec.begin(), vec.end(), cev.begin(), cev.end(), union_vec.begin());
    union_vec.resize(ip - union_vec.begin());
    for(ip = union_vec.begin(); ip != union_vec.end(); ip++)
        cout << *ip << " ";
        
    cout << "\nImposed set_intersection: ";
    vector<int>::iterator te = set_intersection(vec.begin(), vec.end(), cev.begin(), cev.end(), intersec_vec.begin());
    intersec_vec.resize(te - intersec_vec.begin());
    for(te = intersec_vec.begin(); te != intersec_vec.end(); te++)
        cout << *te << " ";
    return 0;
}
