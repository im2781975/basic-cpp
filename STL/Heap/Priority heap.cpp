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
