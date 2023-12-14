//count() occurrence | find() | count() elements
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
 
    cout << "Occurrences of 20 in vector : ";
    
 //Counts the occurrence of 20
    cout << count(vect.begin(), vect.end(), 20);
 
    find(vect.begin(), vect.end(),5) != vect.end()?
    cout << "\nElement found":
    cout << "\nElement not found";
 
    vector<int>v{2, 3, 4, 8, 5, 7, 8 };
    
    vector<int> ::iterator i1,i2;
    
    i1=v.begin();i2=v.end();
    
    if(i1!=i2)
    {
        cout<<"\n1st & last value aren't same" ;
    }
    if (i1 < i2) {
        cout << "\n1st value is smaller than last";
    }
    
    //count total elements
    int count = i2 - i1;
    //count=distance(i1,i2);
    cout<<"\nTotal element is:"<<count ;

    return 0;
}
