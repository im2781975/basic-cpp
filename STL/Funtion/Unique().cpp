// unique() | unique_copy()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
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
    return 0;
}
