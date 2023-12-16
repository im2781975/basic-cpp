//fill() | fill_n()
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<< vec[i] << " ";
}
int main()
{
    vector<int>vect(8,1);
    cout<<"Imposed vect(fill): ";
    print(vect);
    
    cout<<"\nImposed fill: ";
    fill(vect.begin(), vect.end(), 5);
    print(vect);
    cout<<"\nImposed fill(range): ";
    fill(vect.begin()+2, vect.end()-2,5);
    print(vect);
    
    cout<<"\nImposed fill_n: ";
    fill_n(vect.begin(),4,7);
    print(vect);
    
    cout<<"\nImposed fill_n(range): ";
    fill_n(vect.begin()+2,2,3);
    print(vect);
    
}
