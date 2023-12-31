// partition() | is_partitioned() | partition_copy() |stable partiton | partition_point() 
#include<iostream>
#include<algorithm> 
#include<vector> 
using namespace std;
bool odd(int i)
  { return (i % 2) == 1; } 
 
bool pred(int a) 
{ 
    return (a % 2 == 0); 
} 
void print(vector<int>&vect, int n)
{
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
}
int main()
{
    vector<int> vect{2,1,5,6,8,7 };
    
    vector<int>vect1;
    vector<int>vect2;
    
    is_partitioned(vect.begin(), vect.end(),[](int x)
    { return x%2==0; })?
    cout <<"\nVector is partitioned":
    cout<<"\nVector is not partitioned";
     
    vector<int> v1{ 2, 4, 6, 3, 5, 7, 9 }; 
 
    bool b = is_partitioned(v1.begin(), v1.end(), pred); 
  
    if (b == 1) { 
        cout << "\nAll the even no. are present before odd no "; 
    } else { 
        cout << "\nAll the even no. are not present before odd no "; 
    } 
    partition(vect.begin(), vect.end(), [](int x)
    { return x%2==0; });

    cout << "\npartitioned vector is : ";
    print(vect,vect.size());
    
    int n = count_if (vect.begin(), vect.end(), [](int x)
    { return x%2==0; } );
    vect1.resize(n); 
    vect2.resize(vect.size()-n);
     
    partition_copy(vect.begin(), vect.end(), vect1.begin(), 
    vect2.begin(), [](int x)
    { return x%2==0; });
     
    cout << "\nThe elements that return true for condition are : ";
    print(vect1,vect1.size());

    cout << "\nThe elements that return false for condition are : ";
    print(vect2,vect2.size());
    
    stable_partition(vect.begin(), vect.end(), [](int x)
    { return x%2 == 0; });
     
    cout << "\nAfter stable_partiton vect is : ";
    print(vect,vect.size());

    vector<int>::iterator it;
    
    auto m= partition_point(vect.begin(), vect.end(), [](int x)
    { return x%2==0; });

    cout << "\nAfter partition_point vect is: ";
    for ( it= vect.begin(); it!=m; it++)
    cout <<*it<<" ";
    
    vector<int>::iterator pt;
    pt = stable_partition(vect.begin(), vect.end(), odd);
    
    cout << "\nodd numbers:"; 
    for (it = vect.begin(); it != pt; ++it) 
        cout << ' ' << *it; 
  
    cout << "\nEven numbers:"; 
    for (it = pt; it != vect.end(); ++it) 
        cout << ' ' << *it; 
    return 0;
}
