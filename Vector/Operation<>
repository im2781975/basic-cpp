// assign() | insert()
#include<iostream>  
#include<vector>  
#include<algorithm> 
#include<iterator> 
using namespace std;  
  
int main()  
{  
    vector<int> vect1{1, 2, 3, 4};  
    vector<int> vect2;  
  
    // Copying vector by assign function  
    vect2.assign(vect1.begin(), vect1.end());  
  
    cout << "\nVector 1 is: ";  
    for (int i=0; i<vect1.size(); i++)  
        cout << vect1[i] << " ";  
  
    cout << "\nAfter assign Vector 2 is: ";  
    for (int i=0; i<vect2.size(); i++)  
        cout << vect2[i] << " ";  
  
    vect1[0] = 2;  
  
    cout << "\nFirst element of vector 1 is : " <<vect1[0];
    
    cout << "\nFirst element of vector 2 is : "<<vect2[0];
  
    vector<int> vect3; 
 
    vect3.insert(vect3.begin(), vect1.begin(), vect1.end()); 
  
    cout<<"\nVector 1 elements are : ";
    for (int i=0; i<vect1.size(); i++) 
        cout << vect1[i] << " "; 
        
    cout<<"\nAfter insert Vector 2 are : "; 
    for (int i=0; i<vect3.size(); i++) 
        cout << vect3[i] << " "; 
    
    vect1[0] = 2; 
  
    cout<<"\nFirst element of old vector is :"<<vect1[0];
    
    cout << "\nThe first element of new vector is :"<<vect3[0];
    return 0;  
}
