//mismatch() | minmax() | swap_range()
#include<iostream> 
#include<algorithm>  
#include<vector> 
using namespace std; 
  
int main() 
{ 
    vector<int> v1{ 1, 10, 15, 20 }; 
    vector<int> v2{1,10, 25,30,45}; 
    vector<int> v3 = {1,10,15,20 }; 
    vector<int> v4{1,10,15,20,24 };
    
    vector<int> vec= v1;
    vector<int> cev= v2;
    
    if (v1.size() % 2 == 0) 
        swap_ranges(v1.begin(), v1.begin() + (v1.size() / 2), v1.begin() + v1.size() / 2); 
  
    else
        swap_ranges(v1.begin(), v1.begin() + v1.size() / 2, v1.begin() + (v1.size() / 2) + 1); 
    cout<<"\nImposed swap_range: ";
    for(int i=0; i<v1.size(); i++)
        cout<< v1[i]<< " ";
    
    cout<<"\nElements of vec is: ";
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
        
    if (v1 == vec)  
        cout << "\nYes,both vectors are same"; 
    else 
    {
        cout << "\nNo,they aren't same."; 
    }
    pair< vector<int>::iterator,  vector<int>::iterator > mispair; 
      
    mispair = mismatch(v1.begin(), v1.end(), v2.begin()); 
      
    cout << "\nThe 1st mismatch element of 1st container: ";
    cout << *mispair.first ; 
      
    cout << "\nThe 1st mismatch element of 2nd container :"; 
    cout << *mispair.second ; 
      
    mispair = mismatch(v3.begin(), v3.end(), v4.begin()); 
     
    cout << "\nThe returned value from 1st container is : "; 
    cout << *mispair.first ; 
      
    cout << "\nThe returned value from 2nd container is : "; 
    cout << *mispair.second ; 
    
    pair<vector<int>::iterator, vector<int>::iterator> mnmx;

   mnmx = minmax_element(v1.begin(), v1.begin() + 4);

    cout << "\nMinimum value idx is : " << mnmx.first - v1.begin();
    cout << "\nMaximum value idx is : " << mnmx.second - v1.begin();
    
    // using duplicated
    // prints 1 and 5 respectively
    mnmx = minmax_element(v1.begin(), v1.end());

    cout << "\nAfter sort() minimum value idx is : " << mnmx.first - v1.begin();
    cout << "\nAfter sort() maximum value idx is : " << mnmx.second - v1.begin();

    pair<int,int>mnmx_array = minmax({2, 5, 1, 6, 3});

    cout << "\nMinimum value [array] is : " << mnmx_array.first;
    cout << "\nMaximum value [array] is : " << mnmx_array.second;
} 
//Move() | Move_backward()
#include<bits/stdc++.h> 
using namespace std;
void print(vector<int>&vec)
{
    int n=vec.size();
    for(int i=0; i<n; i++)
    {
        cout<<vec[i]<<" ";
    }
}
int main() 
{ 
    vector <int> vec1{ 1,2,3,4,5 };
    vector <int> vec2 (5,7); 
    vector<int>vect(vec1.size());
    vect=vec1;
  
    cout <<"Elements of vect1 :";
    print(vec1);
      
    cout<<"\nElements of vect2 :";
    print(vec2);
      
    move (vec1.begin(), vec1.begin() + 4, vec2.begin() + 1); 
      
    cout << "\nVect2 contains after move() :"; 
    print(vec2);
    
    int n=3, x=3;
    //n<=x
    move_backward (vec2.begin(), vec2.begin() + n, vec1.begin() + x); 
  
    cout<<"\nVect1 contains after move_backward () : "; 
    print(vec1);
    
    cout<<"\nVect2 contains after move_backward () : "; 
    print(vec2);
    
    sort(vect.begin(), vect.end());
    cout<<"\nVector after sorting: ";
    print(vect);
       
    sort(vect.begin(),vect.end(), greater<int>());
    cout << "\nVector after sorting in Descending order is: ";
    print(vect);
   
 
    cout << "\nMaximum element of vector is: ";
    cout<<*max_element(vect.begin(),vect.end());
 
    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end()) ;
    
    //Starting the summation from 0
    cout << "\nSummation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);
 
   cout <<"\nDistance between first to max element: ";
    cout << distance(vect.begin(),
        max_element(vect.begin(), vect.end()));
    
    next_permutation(vect.begin(), vect.end());
    cout<<"\nVector after performe next permutation: ";
    print(vect);
 
    prev_permutation(vect.begin(), vect.end());
    cout <<"\nVector after performe prev permutation:";
    print(vect);
} 
#include <algorithm> 
#include <iostream> 
using namespace std;
bool isEven(int a) 
    { return (a % 2); }
bool isOdd(int a) 
    { return (a % 2 == 0); }
    
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
bool comp(int a) { return a < 0;  }

int main()
{
    int arr[] = { 4, 6, 8, 12, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "\nArray contains :";
    print(arr,n);
 
    if (none_of(arr, arr + n, isPrime))
        cout << "\nAll numbers are composite.";
    else
        cout << "\nThere are primes in array ";
    
    bool even = none_of(arr, arr + n, isEven);
    bool odd =  none_of(arr, arr + n, isOdd);
 
    if ((!even) && (!odd))
        cout << "\nContains both even and odd number";
    else if ((!even) && odd)
        cout << "\nContains odd number only";
    else if (even && (!odd))
        cout << "\nContains even number only";
    else
        cout << "\nArray is empty";
        
    if (none_of(arr, arr+n, comp))
        cout << "\nNo negative elements in the range.";
    else
        cout << "\nThere is at least one negative element in the array range.";
    return 0;
}
//nth_element | not2()
#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std; 
bool comp(int a, int b) 
{ 
    return (a < b); 
} 
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main() 
{ 
    int v[]{ 3, 2, 10, 45, 33, 56, 23, 47 },i;
    int n=sizeof(v) /sizeof( v[0]);
    
    cout<<"Before sort: ";
    print(v, n);

    nth_element(v, v + 4, v + n); 
    // Since, n is 5 so 5th element should be sorted 
    cout<<"\nAfter sort v[5]: ";
    print(v, n);
    
    nth_element(v, v + 5, v + n, comp); 
    cout<<"\nAfter sort v[6]: ";
    print(v, n);
    
    nth_element(v, v + 2, v + n); 
    cout<<"\nAfter sort v[3]: ";
    print(v, 3);
    
    cout<<"\n2nd largest element is : ";
    nth_element(v, v + 1, v + 8, greater<int>()); 
    print(v, 3);
    
    vector<int>vect(v, v + n);
    nth_element(vect.begin(), vect.begin()+ vect.size()/2, vect.end());
    cout << "\nThe median of the array is " << vect[vect.size() / 2]; 
    
    sort(vect.begin(), vect.end(), not2(greater<int>())); 
    cout<<"\nAscending sort using not2:";
    for (int i = 0; i < vect.size(); i++) 
        cout << vect[i] << " "; 
    
    sort(vect.begin(), vect.end(), not2(less<int>())); 
    
    cout<<"\nDescending sort using not2:";
    for (int i = 0; i < vect.size(); i++) 
        cout << vect[i] << " "; 
    
    return 0; 
} 
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
    
    vector<int> v1 = {1, 3, 4, 5, 20, 30};
    vector<int> v2 = {1, 5, 6, 7, 25, 30};
    vector<int> v3(12);
  
    // using copy to copy both vectors into one container
    auto ip = copy(v1.begin(), v1.end(), v3.begin());
    copy(v2.begin(), v2.end(), ip);
  
    // Using inplace_merge() to sort the container
    inplace_merge(v3.begin(),ip,v3.end());
    cout << "\nContainer after inplace_merging is : ";
    for(ip=v3.begin(); ip!=v3.end(); ip++)
        cout<<*ip<<" ";
}
// partition() | is_partitioned() | partition_copy() |stable partiton | partition_point() 
#include<iostream>
#include<algorithm> 
#include<vector> 
using namespace std;
bool odd(int i)
  { return (i % 2) == 1; } 
 
bool pred(int a) 
{ 
    return (a % 2 == 0); 
} 
void print(vector<int>&vect, int n)
{
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
}
int main()
{
    vector<int> vect{2,1,5,6,8,7 };
    
    vector<int>vect1;
    vector<int>vect2;
    
    is_partitioned(vect.begin(), vect.end(),[](int x)
    { return x%2==0; })?
    cout <<"\nVector is partitioned":
    cout<<"\nVector is not partitioned";
     
    vector<int> v1{ 2, 4, 6, 3, 5, 7, 9 }; 
 
    bool b = is_partitioned(v1.begin(), v1.end(), pred); 
  
    if (b == 1) { 
        cout << "\nAll the even no. are present before odd no "; 
    } else { 
        cout << "\nAll the even no. are not present before odd no "; 
    } 
    partition(vect.begin(), vect.end(), [](int x)
    { return x%2==0; });

    cout << "\npartitioned vector is : ";
    print(vect,vect.size());
    
    int n = count_if (vect.begin(), vect.end(), [](int x)
    { return x%2==0; } );
    vect1.resize(n); 
    vect2.resize(vect.size()-n);
     
    partition_copy(vect.begin(), vect.end(), vect1.begin(), 
    vect2.begin(), [](int x)
    { return x%2==0; });
     
    cout << "\nThe elements that return true for condition are : ";
    print(vect1,vect1.size());

    cout << "\nThe elements that return false for condition are : ";
    print(vect2,vect2.size());
    
    stable_partition(vect.begin(), vect.end(), [](int x)
    { return x%2 == 0; });
     
    cout << "\nAfter stable_partiton vect is : ";
    print(vect,vect.size());

    vector<int>::iterator it;
    
    auto m= partition_point(vect.begin(), vect.end(), [](int x)
    { return x%2==0; });

    cout << "\nAfter partition_point vect is: ";
    for ( it= vect.begin(); it!=m; it++)
    cout <<*it<<" ";
    
    vector<int>::iterator pt;
    pt = stable_partition(vect.begin(), vect.end(), odd);
    
    cout << "\nodd numbers:"; 
    for (it = vect.begin(); it != pt; ++it) 
        cout << ' ' << *it; 
  
    cout << "\nEven numbers:"; 
    for (it = pt; it != vect.end(); ++it) 
        cout << ' ' << *it; 
    return 0;
}
// prev_permutation example
#include <algorithm> 
#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 1, 2, 3 };
 
    sort(arr, arr + 3);
    cout << "\nImposed next_permutation:\n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (next_permutation(arr, arr + 3));
 
    cout << "After loop: " << arr[0] << ' '
         << arr[1] << ' ' << arr[2] << '\n';
    reverse(arr, arr + 3);
 
    cout <<"\nImposed prev_permitation: \n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (prev_permutation(arr, arr + 3));
 
    cout << "After loop: " << arr[0] << ' ' << arr[1] 
         << ' ' << arr[2] << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<pair<int, int>> arr = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}};

    pair<int, int> targetPair = {3, 30};

    auto low=lower_bound(arr.begin(), arr.end(), targetPair);
    
    auto lowerBoundIndex = low- arr.begin();
    cout << "Lower bound index: " << lowerBoundIndex ;
    return 0;
}
