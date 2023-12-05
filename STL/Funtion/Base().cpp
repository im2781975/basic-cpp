// all_of() | any_of() | copy_n() | none_of() | find_first_of() | iter_swap() | swap_range() 
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void operation(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            arr[i] *= 2;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool allpositive = all_of(arr, arr + n, [](int i) { return i > 0; });
    cout << "\nAfter impose all_of: ";
    if (allpositive)
        operation(arr, n);

    bool anyEven = any_of(arr, arr + n, [](int i) { return i % 2 == 0; });
    cout << "\nAfter impose any_of: ";
    if (anyEven)
        operation(arr, n);

    int ar[n];
    copy_n(arr, n, ar);
    cout << "\nAfter impose copy_n: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    bool noneNeg = none_of(ar, ar + n, [](int i) { return i < 0; });
    cout << "\nAfter impose none_of: ";
    if (noneNeg)
        operation(ar, n);

    vector<int> vect(arr, arr + n);
    vector<int> cev(ar, ar + n);
    auto p = find_first_of(vect.begin(), vect.end(), cev.begin(), cev.end());
    cout << "\nAfter impose find_first_of: ";
    cout << p - vect.begin();
    
    string s1 = "You are reading about std::find_first_of"; 
    string s2 = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O',  
                'u', 'U'}; 
      
    auto ip = find_first_of(s1.begin(),s1.end(), 
      s2.begin(), s2.end()); 
  
    cout << "\nFirst vowel found at index "<<(ip - s1.begin());
    
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    it1=vect.begin();
    it2=vect.end()-1;
    iter_swap(it1,it2);
    cout<<"\nAfter impose iter_swap: ";
    for(int i=0; i<n; i++)
    {
        cout<<vect[i]<<" ";
    }
    vector<int>vec(5,10);
    swap_ranges(vect.begin()+2,vect.begin()+5,vec.begin());
    cout<<"\nAfter impose swap_ranges(): "
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}
