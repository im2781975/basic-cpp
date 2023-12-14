#include <bits/stdc++.h>
using namespace std;
void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
void pancakeSort(int arr[], int n)
{
    if (n == 1)
        return;
 
    // Find the index of the maximum element in the unsorted portion of the array
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[mi]) {
            mi = i;
        }
    }
    // Move the maximum element to the front of the array if
    // it's not already there
    if (mi != 0) {
        flip(arr, mi);
    }
    // Flip the entire array to move the maximum element to its correct position
    flip(arr, n - 1);
 
    // Recursively sort the remaining unsorted portion of the array
    pancakeSort(arr, n - 1);
}
int main()
{
    int arr[] = { 23, 10, 20, 11, 12, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    pancakeSort(arr, n);
 
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
