//equal() | equal_range()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) 
{ 
    return (a > b); 
} 
int main()
{
    vector<int> v{10, 10, 30, 30, 30, 100, 10, 300, 300, 70, 70, 80};

    pair<vector<int>::iterator, vector<int>::iterator> ip;

    cout << "Before sorting elements: ";
    for (auto i : v)
        cout << i << " ";

    // Sorting the vector
    sort(v.begin(), v.end());

    cout << "\nAfter sorting elements: ";
    for (auto i : v)
        cout << i << " ";

    // Comparing elements with 30
    ip = equal_range(v.begin(), v.end(), 30);

    cout << "\n30 is present in the sorted vector from index "
         << (ip.first - v.begin()) << " to " << (ip.second - v.begin());
    
    sort(v.begin(), v.end(), greater<int>());
  
    // equal_range and comparing the elements with 10 
    ip = equal_range(v.begin(), v.begin() + 12, 10, comp); 
  
    // Displaying the subrange bounds 
    cout << "\n10 is present in the sorted vector from index "
         << (ip.first - v.begin()) << " till "
         << (ip.second - v.begin()); 
  
    vector<int>::iterator i1, i2; 
  
    //lower_bound 
    i1 = lower_bound(v.begin(), v.end(), 5); 
    cout << "\nlower_bound is = " << (i1 - v.begin()); 
  
    //upper_bound 
    i2 = upper_bound(v.begin(), v.end(), 5); 
    cout << "\nupper_bound is = " << (i2 - v.begin()); 
    
    vector<int> vect(v.begin(), v.end());
    //vector<int> vect(v, v+sizeof(v) / sizeof(int) );
    cout << "\nElements of vect are:";
    for (unsigned int i = 0; i < vect.size(); i++)
        cout << " " << vect[i];

    //equal() to compare vectors
    if (equal(vect.begin(), vect.end(), v.begin()))
        cout << "\nContents of both sequences are equal";
    else
        cout << "\nContents of both sequences differ.";
    return 0;
}
