// remove() | remove_if() | remove_copy_if() 
//remove_copy() | erase() 
#include <bits/stdc++.h>
using namespace std;
bool IsOdd(int i) 
 { return ((i % 2) == 1); }
 
void print(vector<int>&vect)
{
    int len=vect.size();
    for(int i=0; i<len; i++)
        cout<<vect[i]<<" ";
}
void print(int arr[],int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    vector<int> vect1{10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> vect2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
    cout << "vect1 is : ";
    print(vect1);
 
    vector<int>::iterator it;
    vector<int>::iterator pt;
    it = remove(vect1.begin(), vect1.end(), 20);
 
    cout << "\nAfter remove vect1 is: ";
    for (pt =vect1.begin(); pt!= it; ++pt)
        cout << ' ' << *pt;

    cout << "\nvect2 is : ";
    print(vect2);
    
    remove_copy(vect1.begin(),vect1.end(),vect1.begin(),30);
    
    cout<<"\nAfter romove_copy vect1 is: ";
    print(vect1);
    
    //it =remove_if(vec2.begin(), vec2.end(), IsOdd);
    it = remove_if(vect2.begin(), vect2.end(),[](int i) { return ((i % 2) == 1); });
 
    cout << "\nAfter remove_if vect2 is: ";
    for (pt=vect2.begin(); pt != it; ++pt)
        cout << ' ' << *pt;
        
    remove_copy_if(vect2.begin(), vect2.end(),vect2.begin(),IsOdd);
    cout<<"\nAfter romove_copy_if vect2 is: ";
    print(vect2);
    
    remove_copy_if(vect1.begin(), vect1.end(),vect1.begin(),IsOdd);
    cout<<"\nAfter romove_copy_if vect1 is: ";
    print(vect1);
    
   vect1.erase(find(vect1.begin(),vect1.end(),10));
    cout << "\nVector after erasing element: ";
    for (int i = 0; i < vect1.size(); i++)
        cout << vect1[i] << " ";
        
int arr[]{ 10, 20, 30, 30, 20, 10, 10, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int Old = 20, New = 99;
 
    cout <<"\nBefore replace arr is:";
    print(arr,n);
 
    replace(arr, arr + n, Old, New);
    cout<<"\nAfter replace arr is:";
    print(arr,n);
 
    replace_if(arr, arr + n, IsOdd, New);

    cout<<"\nAfter replace_if arr is: ";
    print(arr,n);
    
    vector<char>vect;
    for(int i=0; i<n; i++)
        vect.push_back('A'+i);
        
    cout<<"\nBefore replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
        
    replace_copy(vect.begin(), vect.begin()+1,vect.begin(), 'A', 'Z' );
    
    cout<<"\nAfter replace_copy arr is: ";
    for(int i=0; i<n; i++)
        cout<<vect[i]<<" ";
    
    vector<int>vec(arr,arr+n);
    vector<int>cev ;
    for(int i=0; i<n; i++)
        cev.push_back(i);
        
    cout<<"\nBefore replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nBefore replace_copy_if vec is : ";
    print(vec);
    
    replace_copy_if(vec.begin(),vec.end(),cev.begin(),IsOdd,-1);
            
    cout<<"\nAfter replace_copy_if cev is : ";
    print(cev);
    
    cout<<"\nAfter replace_copy_if vec is : ";
    print(vec);
    return 0;
}
