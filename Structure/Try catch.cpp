//for_each with Exception
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void printx2(int a)
{
    cout << a * 2 << " ";
    if ( a % 2 == 0)
    {
        throw a;
    }
}

struct Class2
{
    void operator() (int a)
    {
        cout << a * 3 << " ";
        if ( a % 2 == 0)
        {
            throw a;
        }
    }
} ob1;

int main()
{
    int arr[5] = { 1, 5, 2, 4, 3 };
    try
    {
        for_each(arr, arr + 5, printx2);
    }
    catch(int i)
    {
        cout << "The Exception element is : " << i ;
    }
    cout << "\n";
     
    try
    {
        for_each(arr, arr + 5,ob1);
    }
    catch(int i)
    {
        cout << "The Exception element is : " << i ;
    }
    vector<int>arr1{1, 3, 6, 5, 1};
    try
    {
        for_each(arr1.begin(), arr1.end(), printx2);
    }
    catch(int i)
    {
        cout << "The Exception element is : " << i ;
    }
    cout <<"\n";
    try
    {
        for_each(arr1.begin(), arr1.end(), ob1);
    }
    catch(int i)
    {
        cout << "The Exception element is : " << i ;
    }
}
