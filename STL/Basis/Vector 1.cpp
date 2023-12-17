#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    vector<int> vec;

    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    int sz = vec.size();
    cout<<"\nElement of vector are: ";
    for(int i = 0; i < sz; i++)
    {
        cout << vec[i] << " ";
    }

    int first_element = vec.front();
    cout << "\nFirst element of vect are: "<<first_element;

    int last_element = vec.back();
    cout << "\nLast element of vect are: " <<last_element ;

    cout<<"\nAfter erasing last element vect are: ";
    vec.pop_back();
    sz = vec.size();
    for(int i = 0; i < sz; i++)
        cout << vec[i] << " ";

    cout <<"\nSize of the vector are: " <<sz ;
    
    cout<<"\nWith using loop & pop elements are: ";
    while(!vec.empty())
    {
        cout << vec.back() << " ";
        vec.pop_back();
    }

    // Resize the vector and display elements
    cout<<"\nAfter resize elements are: ";
    vec.resize(10, 1);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    // Clear the vector
    vec.clear();
    sz = vec.size();
    cout<< "\nAfter clear sz is: "<<sz ;

    // Check if the vector is empty
    int emp = vec.empty();
    cout << "\nis empty: "<<emp ;
    vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i * 10);
 
    cout <<"Elements of v[2] :" <<v[2] ;
    cout << "\nElements of v.at(4) : " << v.at(4) ;
    cout << "\nElements of v.front() : " << v.front() ;
    cout << "\nElements of v.back() : " << v.back();
    // pointer to the first element
    int* pos = v.data();
    cout << "\nThe first element is " << *pos;
    
   vector< pair <int,int> > vect;
 
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int x = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<x; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );
 
    for (int i=0; i<x; i++)
    {
        cout<< "\n";
        cout << vect[i].first <<" "
             << vect[i].second;
    }
    return 0;
}
