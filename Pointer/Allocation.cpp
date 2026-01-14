#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *x =new int[n];
    for(int i =0; i< n; i++)
        cin >>x[i];
    cout << "\nAddress of array is: " << x;
    cout<< "\nElements of array is: ";
    for(int i =0; i< n; i++)
        cout <<x[i] <<" ";
    cout << "\nAddress of array is: " << x;
    delete []x;
}
//demonstrate the relation between arrays and pointers
#include <stdio.h>
int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = &arr[0];
    printf("Address Stored in Array name: %p\nAddress of 1st Array Element: %p\n",
           arr, &arr[0]);
 
    printf("Array elements using pointer: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr++);
    }
    return 0;
}
