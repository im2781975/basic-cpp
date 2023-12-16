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
    for(int i=0; i<vect.size(); i++)
        cout<< vect[i] <<" ";

    sort(vect.begin(), vect.end());
    cout << "\nAfter sorting elements: ";
    for(int i=0; i<vect.size(); i++)
        cout<< vect[i] <<" ";

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
    for (unsigned int i = 0; i < vec.size(); i++)
        cout << " " << vec[i];

    //equal() to compare vectors
    if (equal(vec.begin(), vec.end(), vect.begin()))
        cout << "\nContents of both sequences are equal";
    else
        cout << "\nContents of both sequences differ.";
        
    int arr[]{2,4,7,9,7};
    vector<int>cev(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    
    if(equal(cev.begin(),cev.end(),arr, pred))
    {
        cout<<"\nYes";
    }
    else
    {
        cout<<"\nNo";
    }
}
