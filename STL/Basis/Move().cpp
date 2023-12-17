//Move() | Move_backward()
#include<bits/stdc++.h> 
using namespace std;
void print(vector<int>&vec)
{
    int n=vec.size();
    for(int i=0; i<n; i++)
    {
        cout<<vec[i]<<" ";
    }
}
int main() 
{ 
    vector <int> vec1{ 1,2,3,4,5 };
    vector <int> vec2 (5,7); 
    vector<int>vect(vec1.size());
    vect=vec1;
  
    cout <<"Elements of vect1 :";
    print(vec1);
      
    cout<<"\nElements of vect2 :";
    print(vec2);
      
    move (vec1.begin(), vec1.begin() + 4, vec2.begin() + 1); 
      
    cout << "\nVect2 contains after move() :"; 
    print(vec2);
    
    int n=3, x=3;
    //n<=x
    move_backward (vec2.begin(), vec2.begin() + n, vec1.begin() + x); 
  
    cout<<"\nVect1 contains after move_backward () : "; 
    print(vec1);
    
    cout<<"\nVect2 contains after move_backward () : "; 
    print(vec2);
    
    sort(vect.begin(), vect.end());
    cout<<"\nVector after sorting: ";
    print(vect);
       
    sort(vect.begin(),vect.end(), greater<int>());
    cout << "\nVector after sorting in Descending order is: ";
    print(vect);
   
 
    cout << "\nMaximum element of vector is: ";
    cout<<*max_element(vect.begin(),vect.end());
 
    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end()) ;
    
    //Starting the summation from 0
    cout << "\nSummation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);
 
   cout <<"\nDistance between first to max element: ";
    cout << distance(vect.begin(),
        max_element(vect.begin(), vect.end()));
    
    next_permutation(vect.begin(), vect.end());
    cout<<"\nVector after performe next permutation: ";
    print(vect);
 
    prev_permutation(vect.begin(), vect.end());
    cout <<"\nVector after performe prev permutation:";
    print(vect);
} 
