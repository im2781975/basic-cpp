//fill() | fill_n()
#include<bits/stdc++.h>
using namespace std;

bool Pred(int a, int b)
{
    return (a == b);
}
bool IsOdd(int i) { return i % 2; }

bool pred1( int a, int b) 
{ 
    if (a % b == 0) { 
        return 1; 
    } else { 
        return 0; 
    } 
} 

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
    
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> vec{3, 4, 5};
    vector<int>::iterator it, ip, pt;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        ip = vect.begin();
        pt = it;

        while (pt != arr.end() && ip != vect.end() && *pt == *ip)
        {
            pt++;
            ip++;
        }
        if (ip == vect.end())
        {
            cout << it - arr.begin();
            return 0;
        }
    }
    cout << "\nSubsequence not found";

    // find()
    ip = search(arr.begin(), arr.end(), vec.begin(), vec.end());

    cout << "First occurrence at index: " << (ip - arr.begin()) ;

    // find_end()
    ip = find_end(arr.begin(), arr.end(), vec.begin(), vec.end(), Pred);

    if (ip != arr.end())
        cout << "\nLast common occurrence begins at index: " << (ip - arr.begin()) ;
    else
        cout << "\nNo common occurrence found." ;
    
    // find_first_of()
    ip = find_first_of(arr.begin(), arr.end(), vec.begin(), vec.end()); 
    // Displaying the first common element.
    cout << "\nFirst common element at idx: " << *ip ;

    ip = find_first_of(ip + 1, arr.end(), vec.begin(), vec.end()); 
  
    // Displaying the second common element found 
    cout << "\nSecond common element at idx: " << *ip ;
    
    ip = find_if(arr.begin(), arr.end(), IsOdd);
    
    cout << "\nThe first odd value is " << *ip << "\n";
 
   ip = find_if_not(arr.begin(), arr.end(), IsOdd);
 
    cout << "\nThe first non-odd(or even) value is " << *ip ;
    vector<int>cev = {2}; 
    
    ip = find_end(arr.begin(), arr.end(), cev.begin(), cev.end(), Pred); 
    cout << "\nLast odd no. occurs at "<<(ip - arr.begin()) ;
    
    ip = find_end(arr.begin(), arr.end(), cev.begin(), cev.end(), pred1); 
    cout << "\nLast even no. occurs at " <<(ip -arr.begin()) ;
    
  ip = find_first_of(arr.begin(), arr.end(), cev.begin(), cev.end(), Pred); 
   cout << "\nFirst odd no. occurs at index "<<(ip - arr.begin()) ;
   
  ip = find_first_of(arr.begin(), arr.end(), cev.begin(), cev.end(), pred1); 
    cout << "\nFirst even no. occurs at index " <<(ip - arr.begin()) ;
    
    return 0;
}
