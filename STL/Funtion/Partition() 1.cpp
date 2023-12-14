// std::is_partitioned 
#include <iostream> 
#include <algorithm> 
#include <vector> 

bool pred(int a) 
{ 
    return (a % 2 == 0); 
} 
using namespace std; 
int main() 
{ 
    vector<int> v1{ 2, 4, 6, 3, 5, 7, 9 }; 
 
    bool b = is_partitioned(v1.begin(), v1.end(), pred); 
  
    if (b == 1) { 
        cout << "All the even no. are present before odd no \n"; 
    } else { 
        cout << "All the even no. are not present before odd no \n"; 
    } 
  
    // Inserting an even no. at the end of v1 
    // so std::is_partitioned returns false 
    v1.push_back(16); 
  
    // Now again using std::is_partitioned 
    b = is_partitioned(v1.begin(), v1.end(), pred); 
  
    if (b == 1) { 
        cout << "All the even no. are present before odd no \n"; 
    } else { 
        cout << "All the even no. are not present before odd no \n"; 
    } 
  
    return 0; 
} 
