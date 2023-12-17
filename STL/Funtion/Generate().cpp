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
