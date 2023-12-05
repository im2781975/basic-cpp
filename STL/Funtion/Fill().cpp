//fill() | fill_n()
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&vect)
{
    int len=vect.size();
    for(int i=0; i<len; i++)
    {
        cout<<vect[i]<<" ";
    }
}
int main () 
{
    vector<int> vect(8, 1); 
    cout<<"Elements of vect is: ";
    print(vect);

    vector<int> vect2(8); 
    fill(vect2.begin() + 2, vect2.end() - 1, 4);
    
    cout<<"\nElements of vect2 is: ";
    print(vect2);

// Filling the complete vector with value 10 
    fill(vect.begin(),vect.end(),10);
    cout<<"\nAfter impose fill()  vect is: ";
    print(vect);

   fill_n(vect.begin(), 4, 7);
   cout<<"\nAfter impose fill_n vect is: ";
   print(vect);
    // calling fill to initialize 3 elements from 
    // "begin()+3" with value 4
    fill_n(vect.begin() + 3, 3, 4);
    cout<<"\nAfter impose fill_n(range) vect is: ";
   print(vect);

    return 0;
}
