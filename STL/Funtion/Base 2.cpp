//constructive() | back_inserter() | iterative()
#include<bits/stdc++.h>  
using namespace std;  
  
int main()  
{  
    vector<int> vect1{1, 2, 3, 4};  
    //constructor method, Deep copy
    vector<int> vect2(vect1);  
  
    cout << "\nElement of Vect1[] is: ";  
    for (int i=0; i<vect1.size(); i++)  
        cout << vect1[i] << " ";  
  
    cout << "\nAfter copy(constructive) vect2[] is : ";  
    for (int i=0; i<vect2.size(); i++)  
        cout << vect2[i] << " ";  

    vect1[0] = 2;  
  
    cout << "\nFirst element of vect1[] is:" <<vect1[0];
    
    cout << "\nFirst element of vect2[] is : "<<vect2[0];
    
    vector<int> vect3;  
  
    copy(vect1.begin(), vect1.end(), back_inserter(vect3));  
    cout <<"\nElements of vect1[] are: ";  
    for (int i=0; i<vect1.size(); i++)  
        cout << vect1[i] << " ";  
  
    cout << "\nAfter copy vect3[] are : ";
    for (int i=0; i<vect3.size(); i++)  
        cout << vect3[i] << " ";  
  
    vect1[0] = 2;  
  
    cout << "\nFirst element of vect1[] is:" <<vect1[0];
    
    cout << "\nFirst element of vect3[] is:" <<vect3[0];
    
    //copy<iterative>
    vector<int> vect4;  
  
    vect4 = vect1;  
    
    cout <<"\nElements of vect1[] are: ";  
    for (int i=0; i<vect1.size(); i++)  
        cout << vect1[i] << " ";  

    cout <<"\nAfter copy(iterative) elements of vect4[] are: ";  
    for (int i=0; i<vect4.size(); i++)  
        cout << vect4[i] << " ";  
 
    vect1[0] = 2;  
  
    cout << "\nFirst element of vect1[] is :"<<vect1[0];

    cout << "\nFirst element of vect4[] is :"<<vect4[0];
    
    return 0;  
}  
