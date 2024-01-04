#include<bits/stdc++.h>
using namespace std;
int print(int *ptr)
{
    *ptr = 23;
}
int main()
{
    int arr[] = {2, 4, 1, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    cout << "\nAfter sort minimum is: "<<arr[n - 1];
    
    int minimum =arr[0];
    for(int i =0; i< n; i++)
        minimum =min( minimum, arr[i]);
    
    cout << "\nAfter Buildin Minimum is: " << minimum;
    
    int* ptr = new int[]{2, 3, 6, 8, 9};
    int x =5;
    cout<<"\nArray pointer value is: ";
    for (int i = 0; i < x; i++) {
        cout << ptr[i] << " ";
    }
    
    int m = ptr[0];
    int *p = &m;
    print(p);
    cout<<"\nChanged another value pointer address is: " << p;
    cout<<"\nChanged another value pointer is: " << *p;
}
