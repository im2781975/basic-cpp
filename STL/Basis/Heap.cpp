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
