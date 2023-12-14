#include<bits/stdc++.h> 
using namespace std; 
  
void swapValue(int *a, int *b) 
{ 
    int *temp = a; 
    a = b; 
    b = temp; 
    return; 
} 
  
// Function to sort an array using insertion sort
void InsertionSort(int arr[], int *begin, int *end) 
{ 
    // Get the left and the right index of the subarray to be sorted 
    int left = begin - arr; 
    int right = end - arr; 
  
    for (int i = left+1; i <= right; i++) 
    { 
        int key = arr[i]; 
        int j = i-1; 
        while (j >= left && arr[j] > key) 
        { 
            arr[j+1] = arr[j]; 
            j = j-1; 
        } 
        arr[j+1] = key; 
   } 
  
    return; 
} 
// A function to partition the array and return the partition point 
int* Partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];  
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            // increment index of smaller element 
            i++; 
  
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (arr + i + 1); 
} 

int *MedianOfThree(int * a, int * b, int * c) 
{ 
    if (*a < *b && *b < *c) 
        return (b); 
  
    if (*a < *c && *c <= *b) 
        return (c); 
  
    if (*b <= *a && *a < *c) 
        return (a); 
  
    if (*b < *c && *c <= *a) 
        return (c); 
  
    if (*c <= *a && *a < *b) 
        return (a); 
  
    if (*c <= *b && *b <= *a) 
        return (b); 
} 

// A Utility function to perform intro sort 
void IntrosortUtil(int arr[], int * begin, int * end, int depthLimit) 
{ 
    // Count the number of elements 
    int size = end - begin; 
      // If partition size is low then do insertion sort 
    if (size < 16) 
    { 
        InsertionSort(arr, begin, end); 
        return; 
    } 
    // If the depth is zero use heapsort 
    if (depthLimit == 0) 
    { 
        make_heap(begin, end+1); 
        sort_heap(begin, end+1); 
        return; 
    } 
    // Else use a median-of-three concept to  find a good pivot 
    int * pivot = MedianOfThree(begin, begin+size/2, end); 
    // Swap the values pointed by the two pointers 
    swapValue(pivot, end); 
   // Perform Quick Sort 
    int * partitionPoint = Partition(arr, begin-arr, end-arr); 
    IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1); 
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1); 
    return; 
} 
void Introsort(int arr[], int *begin, int *end) 
{ 
    int depthLimit = 2 * log(end-begin); 
    // Perform a recursive Introsort 
    IntrosortUtil(arr, begin, end, depthLimit); 
  
      return; 
} 
void printArray(int arr[], int n) 
{ 
   for (int i=0; i < n; i++) 
        cout<<arr[i]<<" ";
} 
int main() 
{ 
    int arr[] = {3, 1, 23, -9, 233, 23, -313, 32, -9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    // Pass the array, the pointer to the first element and 
    // the pointer to the last element 
    Introsort(arr, arr, arr+n-1); 
    printArray(arr, n); 
    return(0); 
} 
