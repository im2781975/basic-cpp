// count_if() | count()
#include <bits/stdc++.h>
using namespace std;
bool isEven(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
}
int main()
{
    vector<int> vect;
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vect.push_back(i);
    }
    for(int i=10; i>0; i--)
        vec.push_back(i);
        
    int noEven = count_if(vect.begin(), vect.end(),isEven);
    cout << "After using count_if Even count is: "<< noEven;
    
    int n=count_if(vect.begin(),vect.end(),[](int i){return i%2!=0;});
    cout << "\nAfter using count_if odd count is: "<< n;
    
    string str = "geeksforgeeks";
    cout << "\nAfter using count() 'e' count is : " << count(str.begin(), str.end(), 'e');
    
    cout << "\nOccurrences of 20 in vector : ";
    
    //Counts the occurrence of 20
    cout << count(vec.begin(), vec.end(), 20);
 
    if(find(vec.begin(), vec.end(),5) != vec.end())
        cout << "\nElement found";
    else
        cout << "\nElement not found";
 
    vector<int>v{2, 3, 4, 8, 5, 7, 8 };
    vector<int> ::iterator i1,i2;
    
    i1=v.begin();i2=v.end();
    
    if(i1!=i2)
        cout<<"\n1st & last value aren't same" ;
    if (i1 < i2) {
        cout << "\n1st value is smaller than last";
    }
    //count total elements
    //int count = i2 - i1;
    int count=distance(i1,i2);
    cout<<"\nTotal element is:"<<count ;
    return 0;
}
