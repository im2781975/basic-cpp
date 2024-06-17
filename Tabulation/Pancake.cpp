#include<bits/stdc++.h> 
using namespace std; 
void flip(int arr[], int i) 
{ 
    int temp, start = 0; 
    while (start < i) 
    { 
        temp = arr[start]; 
        arr[start] = arr[i]; 
        arr[i] = temp; 
        start++; 
        i--; 
    } 
} 
int findMax(int arr[], int n) 
{ 
    int mi, i; 
    for (mi = 0, i = 0; i < n; ++i) 
    if (arr[i] > arr[mi]) 
            mi = i; 
    return mi; 
} 
void pancakeSort(int *arr, int n) 
{ 
    for (int cur = n; cur > 1;--cur) 
    { 
        // Find index of the  maximum element in 
        int mi = findMax(arr, cur); 
        // Move the maximum  element to end of current array if  it's not already  at the end
        if (mi != cur -1) 
        { 
            flip(arr, mi); 
 
            // Now move the maximum number to end by  reversing current array 
            flip(arr, cur -1);
        } 
    } 
} 
void pancakeSort(int arr[], int n)
{
    if (n == 1)
        return;
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[mi]) {
            mi = i;
        }
    }
    // Move the maximum element to the front of the array if it's not already there
    if (mi != 0) {
        flip(arr, mi);
    }
    // Flip the entire array to move the maximum element to its correct position
    flip(arr, n - 1);i
    pancakeSort(arr, n - 1);
}
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; ++i) 
        cout<< arr[i]<<" "; 
} 
int main() 
{ 
    int arr[] = {23, 10, 20, 11, 12, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
 
    pancakeSort(arr, n); 
    cout<<"Sorted Array "; 
    printArray(arr, n); 
    return 0; 
} 
