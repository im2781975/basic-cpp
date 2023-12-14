//mismatch() | minmax() 
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

