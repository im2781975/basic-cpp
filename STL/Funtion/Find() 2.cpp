//find the occurrence of an odd & even numb;
#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std; 
 
bool pred( int a, int b) 
{ 
    if (a % b != 0) { 
        return 1; 
    } else { 
        return 0; 
    } 
} 
 
bool pred1( int a, int b) 
{ 
    if (a % b == 0) { 
        return 1; 
    } else { 
        return 0; 
    } 
} 
int main() 
{ 
    vector<int>v1 = {1, 3, 4, 5, 6, 7, 8, 10}; 
     
    vector<int>v2 = {2}; 
    
    vector<int>::iterator ip; 
    ip = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), pred); 
    cout << "Last odd no. occurs at "<<(ip - v1.begin())<<"\n";
    
    ip = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), pred1); 
    cout << "Last even no. occurs at " <<(ip -v1.begin())<<"\n";
    
  ip = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), pred); 
   cout << "First odd no. occurs at index "<<(ip - v1.begin())<<"\n";
   
  ip = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), pred1); 
    cout << "First even no. occurs at index " <<(ip - v1.begin())<<"\n";
    return 0; 
} 
