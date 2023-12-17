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
