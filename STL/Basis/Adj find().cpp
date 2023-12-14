// adjacent_find
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec{0, 1, 2, 5, 40, 40, 41, 41, 5 };
 
    int range1 = 5;
    int range2 = 9;
 
    vector<int>::iterator it;
 
    // Check if the elements in the range [vec.begin(), vec.begin() + range1) are sorted in descending order.
    it = adjacent_find(vec.begin(),vec.begin() + range1,greater<int>());
    if (it == vec.begin() + range1) 
    {
          cout <<"\nSorted in the range :"<<range1 ;
    }
    else
    {
    cout << "\nNot sorted in the range : " << range1 ;
    }
    // Check if the elements in the range [vec.begin(), vec.begin() + range2) are sorted in descending order.
    it =adjacent_find(vec.begin(),vec.begin() + range2, greater<int>());
 
    if (it == vec.begin() + range2) 
    {
        cout<< "\nSorted in the range : " << range2 ;
    }
    else
    {
        cout<<"\nNot sorted in the range : "<<range2 ;
    }
    int A[]{ 10, 13, 16, 16, 18 };
    int n =sizeof(A) /sizeof(A[0]);
 
    int* pt = adjacent_find(A, A + n);
    cout<<"\nrepeated element is: ";
    cout << *pt;
}
