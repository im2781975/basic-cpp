// Bubble sort
#include<bits/stdc++.h>
using namespace std;
void Bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
void BubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {7, 2, 13, 2, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nImposed Bubble sort optimized: ";
    BubbleSort(arr,n);
    print(arr,n);
    
    cout<<"\nImposed Bubble sort: ";
    Bubble_sort(arr, n);
    print(arr, n);
}
