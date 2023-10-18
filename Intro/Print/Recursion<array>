#include <iostream>
using namespace std;
void Array(int* arr, int n)
{
    if (n == 0)  return;
    
    Array(arr, n - 1);
    cout<<arr[n - 1] << ' ';
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Array(arr,n);
    return 0;
}
