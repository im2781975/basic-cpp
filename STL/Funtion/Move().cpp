//Move() | Move_backward()
#include<bits/stdc++.h> 
using namespace std;
void print(vector<int>&vec,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<vec[i]<<" ";
    }
}
int main() 
{ 
    vector <int> vec1{ 1,2,3,4,5 };
    vector <int> vec2 (5,7); 
  
    cout <<"Elements of vect1 :";
    print(vec1, vec1.size());
      
    cout<<"\nElements of vect2 :";
    print(vec2, vec2.size());
      
    move (vec1.begin(), vec1.begin() + 4, vec2.begin() + 1); 
      
    cout << "\nVect2 contains after move() :"; 
    print(vec2, vec2.size());
    
    int n=3, x=3;
    //n<=x
    move_backward (vec2.begin(), vec2.begin() + n, vec1.begin() + x); 
  
    cout<<"\nVect1 contains after move_backward () : "; 
    print(vec1, vec1.size());
    
    cout<<"\nVect2 contains after move_backward () : "; 
    print(vec2, vec2.size());
} 
