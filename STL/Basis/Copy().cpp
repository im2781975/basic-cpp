//copy() | copy_n() | copy_if() | copy_backward() 
#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
  
int main() 
{ 
   vector<int>v1{1, 5, 7, 3, 8, 3};
   
   vector<int> v2(6); 
   vector<int> v3(6); 
     
   //using copy() to copy 1st 3 elements 
   copy(v1.begin(), v1.begin()+3, v2.begin()); 
   cout << "After using copy array is : "; 
   for(int i=0; i<v2.size(); i++) 
       cout << v2[i] << " ";
     
    vector<int>::iterator itr; 
    vector<int> v4; 
 
    copy(v1.begin(), v1.end(), inserter(v4, itr)); 
  
    cout << "\nThe new vector elements entered using inserter: "; 
    for (int i = 0; i < v4.size(); i++) 
        cout << v4[i] << " "; 
   // using copy_n() to copy 1st 4 elements 
   copy_n(v1.begin(), 4, v3.begin()); 
   cout << "\nAfter using copy_n array is : "; 
   for(int i=0; i<v3.size(); i++) 
   cout << v3[i] << " "; 


   copy_if(v1.begin(), v1.end(), v2.begin(), [](int i){return i%2!=0;}); 
    cout << "\nAfter using copy_if array is: ";
    for(int i=0; i<v2.size(); i++) 
        cout << v2[i] << " "; 
          
    //using copy_backward() to copy 1st 4 elements ending at second last position. always copied element position is lessthen or equal the position where you copied

    copy_backward(v1.begin(), v1.begin() + 4, v3.begin()+5);
    cout << "\nAfter using copy_backward() array is: ";
    for(int i=0; i<v3.size(); i++) 
    cout << v3[i] << " "; 
} 
