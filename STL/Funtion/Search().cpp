// return idx of equal one
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
bool pred(int i, int j) 
{ 
    if (i == j) { 
        return 1; 
    } else { 
        return 0; 
    } 
} 
int main() 
{ 
    int i, j; 
    vector<int> v1 = { 1, 2, 3, 4, 5, 3, 3, 6, 7 }; 
  
    int v2 = 3; 
  
    vector<int>::iterator i1; 
  
    i1 = search_n(v1.begin(), v1.end(), 2, v2, pred); 
  
    if (i1 != v1.end()) { 
        cout << "v2 is present consecutively 2 times at index "
             << (i1 - v1.begin()); 
    } else { 
        cout << "v2 is not present consecutively 2 times "
             << "in vector v1"; 
    } 
    
    vector<int> v3 = {3, 4}; 
   
   // vector<int>::iterator i1; 
   
    i1 =search(v1.begin(), v1.end(), v3.begin(), v3.end()); 
   
    if (i1 != v1.end()) { 
        cout << "\nvector3 is present firstly at index " 
             << (i1 - v1.begin()) ;
    } else { 
        cout << "\nvector3 is not present in vector1 ";
    } 
  
    i1 =find_end(v1.begin(), v1.end(), v3.begin(), v3.end()); 
   
    if (i1 != v1.end()) { 
        cout << "\nvector3 is present lastly at index "<< (i1 - v1.begin()) ;
    } else { 
        cout << "\nvector3 is not present in vector1"; 
    } 
    return 0; 
} 
