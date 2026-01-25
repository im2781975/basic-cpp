// count_if() | count()
#include <bits/stdc++.h>
using namespace std;
bool isEven(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
}
int main()
{
    vector<int> vect;
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vect.push_back(i);
    }
    for(int i=10; i>0; i--)
        vec.push_back(i);
        
    int noEven = count_if(vect.begin(), vect.end(),isEven);
    cout << "After using count_if Even count is: "<< noEven;
    
    int n=count_if(vect.begin(),vect.end(),[](int i){return i%2!=0;});
    cout << "\nAfter using count_if odd count is: "<< n;
    
    string str = "geeksforgeeks";
    cout << "\nAfter using count() 'e' count is : " << count(str.begin(), str.end(), 'e');
    
    cout << "\nOccurrences of 20 in vector : ";
    
    //Counts the occurrence of 20
    cout << count(vec.begin(), vec.end(), 20);
 
    if(find(vec.begin(), vec.end(),5) != vec.end())
        cout << "\nElement found";
    else
        cout << "\nElement not found";
 
    vector<int>v{2, 3, 4, 8, 5, 7, 8 };
    vector<int> ::iterator i1,i2;
    
    i1=v.begin();i2=v.end();
    
    if(i1!=i2)
        cout<<"\n1st & last value aren't same" ;
    if (i1 < i2) {
        cout << "\n1st value is smaller than last";
    }
    //count total elements
    //int count = i2 - i1;
    int count=distance(i1,i2);
    cout<<"\nTotal element is:"<<count ;
    return 0;
}
//equal() | equal_range()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) 
{ 
    return (a > b); 
} 
bool pred(int a, int b)
{
    return (a = b);
}
void print(vector<int>&vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
}
int main()
{
    vector<int> vect{10, 10, 30, 30, 30, 100, 10, 300, 300, 70, 70, 80};

    pair<vector<int>::iterator, vector<int>::iterator> it;

    cout << "Before sorting elements: ";
    print(vect);

    sort(vect.begin(), vect.end());
    cout << "\nAfter sorting elements: ";
    print(vect);

    // Comparing elements with 30
    it = equal_range(vect.begin(), vect.end(), 30);

    cout << "\n30 is present in the sorted vector from index "
         << (it.first - vect.begin()) << " to " << (it.second - vect.begin());
    
    sort(vect.begin(), vect.end(), greater<int>());
  
    // equal_range and comparing the elements with 10 
    it = equal_range(vect.begin(), vect.begin() + 12, 10, comp); 
  
    // Displaying the subrange bounds 
    cout << "\n10 is present in the sorted vector from index "
         << (it.first - vect.begin()) << " till "
         << (it.second - vect.begin()); 
  
    vector<int>::iterator i1, i2; 
  
    //lower_bound 
    i1 = lower_bound(vect.begin(), vect.end(), 5); 
    cout << "\nlower_bound is = " << (i1 - vect.begin()); 
  
    //upper_bound 
    i2 = upper_bound(vect.begin(), vect.end(), 5); 
    cout << "\nupper_bound is = " << (i2 - vect.begin()); 
    
    vector<int> vec(vect.begin(), vect.end());
    //vector<int> vect(v, v+sizeof(v) / sizeof(int) );
    cout << "\nElements of vect are:";
    print(vec);

    //equal() to compare vectors
    if (equal(vec.begin(), vec.end(), vect.begin()))
        cout << "\nContents of both sequences are equal";
    else
        cout << "\nContents of both sequences differ.";
        
    int arr[]{2,4,7,9,7};
    vector<int>cev(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    
    if(equal(cev.begin(),cev.end(),arr, pred))
        cout << "\nContents of both sequences are equal";
        
    else
        cout << "\nContents of both sequences differ.";
}
//fill() | fill_n()
#include<bits/stdc++.h>
using namespace std;

bool Pred(int a, int b)
{
    return (a == b);
}
bool IsOdd(int i) { return i % 2; }

bool pred1( int a, int b) 
{ 
    if (a % b == 0) { 
        return 1; 
    } else { 
        return 0; 
    } 
} 

void print(vector<int>vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<< vec[i] << " ";
}
int main()
{
    vector<int>vect(8,1);
    cout<<"Imposed vect(fill): ";
    print(vect);
    
    cout<<"\nImposed fill: ";
    fill(vect.begin(), vect.end(), 5);
    print(vect);
    cout<<"\nImposed fill(range): ";
    fill(vect.begin()+2, vect.end()-2,5);
    print(vect);
    
    cout<<"\nImposed fill_n: ";
    fill_n(vect.begin(),4,7);
    print(vect);
    
    cout<<"\nImposed fill_n(range): ";
    fill_n(vect.begin()+2,2,3);
    print(vect);
    
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> vec{3, 4, 5};
    vector<int>::iterator it, ip, pt;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        ip = vect.begin();
        pt = it;

        while (pt != arr.end() && ip != vect.end() && *pt == *ip)
        {
            pt++;
            ip++;
        }
        if (ip == vect.end())
        {
            cout << it - arr.begin();
            return 0;
        }
    }
    cout << "\nSubsequence not found";

    // find()
    ip = search(arr.begin(), arr.end(), vec.begin(), vec.end());

    cout << "First occurrence at index: " << (ip - arr.begin()) ;

    // find_end()
    ip = find_end(arr.begin(), arr.end(), vec.begin(), vec.end(), Pred);

    if (ip != arr.end())
        cout << "\nLast common occurrence begins at index: " << (ip - arr.begin()) ;
    else
        cout << "\nNo common occurrence found." ;
    
    // find_first_of()
    ip = find_first_of(arr.begin(), arr.end(), vec.begin(), vec.end()); 
    // Displaying the first common element.
    cout << "\nFirst common element at idx: " << *ip ;

    ip = find_first_of(ip + 1, arr.end(), vec.begin(), vec.end()); 
  
    // Displaying the second common element found 
    cout << "\nSecond common element at idx: " << *ip ;
    
    ip = find_if(arr.begin(), arr.end(), IsOdd);
    
    cout << "\nThe first odd value is " << *ip << "\n";
 
   ip = find_if_not(arr.begin(), arr.end(), IsOdd);
 
    cout << "\nThe first non-odd(or even) value is " << *ip ;
    vector<int>cev = {2}; 
    
    ip = find_end(arr.begin(), arr.end(), cev.begin(), cev.end(), Pred); 
    cout << "\nLast odd no. occurs at "<<(ip - arr.begin()) ;
    
    ip = find_end(arr.begin(), arr.end(), cev.begin(), cev.end(), pred1); 
    cout << "\nLast even no. occurs at " <<(ip -arr.begin()) ;
    
  ip = find_first_of(arr.begin(), arr.end(), cev.begin(), cev.end(), Pred); 
   cout << "\nFirst odd no. occurs at index "<<(ip - arr.begin()) ;
   
  ip = find_first_of(arr.begin(), arr.end(), cev.begin(), cev.end(), pred1); 
    cout << "\nFirst even no. occurs at index " <<(ip - arr.begin()) ;
    
    return 0;
}
// generate () | generate_n() | transform() 
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int gen() 
{ 
    static int i = 0; 
    return ++i; 
} 
int increment(int x)
{  
    return (x+1); 
}
using namespace std; 
int main() 
{
    vector<int> v(5); 
    generate(v.begin(), v.end(), gen); 
    
    cout<<"After impose generate(): ";
    vector<int>::iterator it; 
    for (it = v.begin(); it != v.end(); ++it) { 
        cout << *it << " "; 
    }
    
    cout<<"\nAfter impose generate_n(): ";
    generate_n(v.begin(),5,gen);
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    transform(arr, arr+n, arr, increment);
    
    cout<<"\nAfter transform array is: ";
    for (int i=0; i<n; i++)
        cout << arr[i] <<" ";
        
    int arr2[] = {4, 5, 6};
    int res[n];
  
   transform(arr, arr+n, arr2, res, plus<int>());
 
  cout<<"\nAfter transform result is: ";
  for (int i=0; i<n; i++)
    cout << res[i] << " ";
    
  // Code to add two arrays
  for (int i=0; i<n; i++)
    res[i] = arr[i] + arr2[i];
 
  cout<<"\nSum is: ";
  for (int i=0; i<3; i++)
    cout << res[i] << " ";
    return 0;
} 
//is_heap() | is_heap_until() | make_heap()
#include<bits/stdc++.h>
using namespace std;

struct greaters
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

int main()
{
    vector<int> vect{9, 2, 1, 6, 4};
    vector<int>::iterator it, pt;

    is_heap(vect.begin(), vect.end()) ? cout << "\nContainer is heaped" : cout << "\nContainer isn't heaped";

    pt = is_heap_until(vect.begin(), vect.end());

    cout << "\nVect elements are: ";
    for (it = vect.begin(); it != pt; it++)
    {
        cout << *it << " ";
    }

    //make_heap(vect.begin(),vect.end(),greaters());
    make_heap(vect.begin(), vect.end());

    cout << "\nFront element after make_heap: " << vect.front();
}
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
// application of make_heap() (max_heap) priority scheduling 
#include<iostream> 
#include<algorithm>
#include<vector> 
using namespace std; 
  
int main() 
{ 
    vector<int>vi{15,6,7,9,11,19}; 
    make_heap(vi.begin(),vi.end()); 
    int a = 10; 
    int k = 3; 
    // k represents the number of additional jobs to be scheduled, and a is the priority of the first additional job.
    for ( int i=0; i<k; i++) 
    { 
        vi.push_back(a); 
    // transform into heap ( using push_heap() ) 
    push_heap(vi.begin(), vi.end()); 
    for(int i=0; i<vi.size(); i++)
    {
        cout<<vi[i]<<" ";
    }
    cout <<"\nJob with maximum priority is : "<<vi.front();
    a = a + 10; 
    } 
} 
// sort_heap 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <iostream> 
  
int main( ) { 
   using namespace std; 
   vector <int> vt1, vt2; 
   vector <int>::iterator Itera1, Itera2; 
  
   int i; 
   for ( i = 1 ; i <=5 ; i++ ) 
      vt1.push_back( i ); 
  
   random_shuffle( vt1.begin( ), vt1.end( ) ); 
  
   cout << "vector vt1 is ( " ; 
   for ( Itera1 = vt1.begin( ) ; Itera1 != vt1.end( ) ; Itera1++ ) 
      cout << *Itera1 << " "; 
   cout << ")" << endl; 
  
   sort_heap (vt1.begin( ), vt1.end( ) ); 
   cout << "heap vt1 sorted range: ( " ; 
   for ( Itera1 = vt1.begin( ) ; Itera1 != vt1.end( ) ; Itera1++ ) 
      cout << *Itera1 << " "; 
   cout << ")" << endl; 
} 
// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;
  
void showpq(
    priority_queue<int, vector<int>, greater<int> > g)
{
    while (!g.empty()) {
        cout << ' ' << g.top();
        g.pop();
    }
}
void showArray(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
int main()
{
    int arr[6]={10, 2, 4, 8, 6, 9};
    priority_queue<int, vector<int>, greater<int> > gquiz(
        arr, arr + 6);
    //int: The data type of elements in the priority q.
//vector<int>:underlying container used for the priority queue 
//greater<int>: The comparison function or functor that defines the order of elements.
    cout << "\nArray: ";
      showArray(arr, 6);
  
    cout << "\nPriority Queue : ";
    showpq(gquiz);
  
    return 0;
}

