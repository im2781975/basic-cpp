#include <bits/stdc++.h>
using namespace std;
void insertion(vector <int> a, int n)
{
    for (int i = 1; i < n; i++) {
        int idx = i;
        while (idx >= 1) {
            if (a[idx - 1] > a[idx]) {
                swap(a[idx - 1], a[idx]);
                idx--;
            } else
                break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void insertionSort(int arr[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            cout << arr[j] << " ";
        }
        cout << "\n";
        cout << arr[j] << " ";
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertion(a, n);
    
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int N =10;
    insertionSort(arr, N);
    cout<<"\narray after using insertion sort:"<<endl;
    printArray(arr, N);
    return 0;
}
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
// perform 3 way Merge Sort
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &gArray, int low, int mid1, int mid2, int high, vector<int> &destArray) 
{ 
    int i = low, j = mid1, k = mid2, l = low; 
    // Choose smaller of the smallest in the three ranges 
    while ((i < mid1) && (j < mid2) && (k < high)) 
    { 
        if(gArray[i] < gArray[j])
        {
            if(gArray[i] < gArray[k])
                destArray[l++] = gArray[i++];
            else
                destArray[l++] = gArray[k++];
        }
        else
        {
            if(gArray[j] < gArray[k])
                destArray[l++] = gArray[j++];
            else
                destArray[l++] = gArray[k++];
        }
    } 
    // Case where first and second ranges have remaining values 
    while ((i < mid1) && (j < mid2)) 
    { 
        if(gArray[i] < gArray[j])
            destArray[l++] = gArray[i++];
        else
            destArray[l++] = gArray[j++];
    }
    // case where second and third ranges have remaining values 
    while ((j < mid2) && (k < high)) 
    { 
        if(gArray[j] < gArray[k])
            destArray[l++] = gArray[j++];
        else
            destArray[l++] = gArray[k++];
    } 
    // Case where first and third ranges have remaining values 
    while ((i < mid1) && (k < high)) 
    { 
        if(gArray[i] < gArray[k])
            destArray[l++] = gArray[i++];
        else
            destArray[l++] = gArray[k++];
    } 
    // Copy remaining values from the first range 
    while (i < mid1) 
        destArray[l++] = gArray[i++]; 
    // Copy remaining values from the second range 
    while (j < mid2) 
        destArray[l++] = gArray[j++]; 
    // Copy remaining values from the third range 
    while (k < high) 
        destArray[l++] = gArray[k++]; 
} 
void mergeSort3WayRec(vector<int> &gArray, int low,int high, vector<int> &destArray) 
{ 
    if (high - low < 2) 
        return; 
    int mid1 = low + ((high - low) / 3); 
    int mid2 = low + 2 * ((high - low) / 3) + 1; 
 
    // Sorting 3 arrays recursively 
    mergeSort3WayRec(destArray, low, mid1, gArray); 
    mergeSort3WayRec(destArray, mid1, mid2, gArray); 
    mergeSort3WayRec(destArray, mid2, high, gArray); 
 
    merge(destArray, low, mid1, mid2, high, gArray); 
}
void mergeSort3Way(vector<int> &gArray, int n) 
{ 
    if (n == 0) 
        return; 
    vector<int> fArray(n); 
    for (int i = 0; i < n; i++) 
        fArray[i] = gArray[i]; 
    // sort function 
    mergeSort3WayRec(fArray, 0, n, gArray); 
 
    // copy back elements of duplicate array to given array
    for (int i = 0; i < n; i++) 
        gArray[i] = fArray[i]; 
} 
int main()
{
    vector<int> data = {45, -2, -45, 78, 30, -42, 10, 19, 73, 93};
    mergeSort3Way(data,10);
    cout << "After 3 way merge sort: ";
    for (int i = 0; i < 10; i++)
        cout << data[i] << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int const l, int const mid,
           int const r)
{
    int const One = mid - l + 1;
    int const Two = r - mid;
    
    auto *left = new int[One],
         *right = new int[Two];
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < One; i++)
        left[i] = array[l + i];
    for (auto j = 0; j < Two; j++)
        right[j] = array[mid + 1 + j];
    auto idx1 = 0, idx2= 0;
    int indexOfMergedArray = l;
 
    // Merge the temp arrays back into array[left..right]
    while (idx1 < One && idx2< Two)
    {
        if (left[idx1]
            <= right[idx2]) {
           array[indexOfMergedArray]
                = left[idx1];
            idx1++;
        }
        else {
            array[indexOfMergedArray]
                = right[idx2];
            idx2++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of left[], if there are any
    while (idx1 < One) {
        array[indexOfMergedArray]
            = left[idx1];
        idx1++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of right[], if there are any
    while (idx2 < Two) {
        array[indexOfMergedArray]
            = right[idx2];
        idx2++;
        indexOfMergedArray++;
    }
    delete[] left;
    delete[] right;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n";
    printArray(arr, n);
 
    mergeSort(arr, 0, n - 1);
    cout << "\nSorted array is \n";
    printArray(arr, n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int>merged(vector<int>a, vector<int>b)
{
    vector<int>output;
    int idx1 = 0, idx2 = 0;
    int n = a.size() + b.size();

    for(int i=0; i<n; i++)
    {
        if(idx1 == a.size())
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else if(idx2 == b.size())
        {
            output.push_back(a[idx1]);
            idx1++;
        }
        else if(a[idx1] > b[idx2])
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else
        {
            output.push_back(a[idx1]);
            idx1++;
        }
    }
    return output;
}
vector<int>devide(vector<int>p)
{
    vector<int>b, c;
    if(p.size() <= 1)
        return p;
    int len = p.size();
    for(int i =0; i<len/2; i++)
        b.push_back(p[i]);
        
    for(int i=len/2; i<len; i++)
        c.push_back(p[i]);
    vector<int>Sorted_b = devide(b);
    vector<int>Sorted_c = devide(c);
    return merged(Sorted_b, Sorted_c);
}
vector<int> merge_sort(vector<int> a)
{
    if (a.size() <= 1)
        return a;

    int mid = a.size() / 2;
    vector<int> b, c;
    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);

    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);
    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    vector<int> sorted_a;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    return sorted_a;
}
void print(vector <int> ans)
{
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}
int main()
{
    int r, x;
    vector <int> p;
    cin >> r;
    for(int i = 0; i < r; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    //vector<int>ans = devide(p);
    vector <int> ans = merge_sort(p);
    print(ans);
    return 0;
}
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
#include <bits/stdc++.h>
using namespace std;

void pigeonholeSort(int arr[], int n)
{
    // Find minimum and maximum values in arr[]
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; 
    // Find range
 
    // Create an array of vectors. Size of array range. Each vector represents a hole that is going to contain matching elements.
    vector<int> holes[range];
 
    // Traverse through input array and put every element in its respective hole
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);
 
    // Traverse through all holes one by one. For every hole, take its elements and put in array.
    int index = 0;
    // index in sorted array
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}
int main()
{
    int arr[] = {8, 3, 2, 7, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    pigeonholeSort(arr, n);
 
    cout<<"Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
 
    return 0;
}
// qsort() 
#include <bits/stdc++.h>
using namespace std;
// This function is used in qsort to decide the relative 
// order of elements at addresses p and q. 
int comparator(const void* p, const void* q) 
{ 
    int l = *(const int*)p; 
    int r = *(const int*)q; 
  
    // both odd, put the greater of two first. 
    if ((l & 1) && (r & 1)) 
        return (r - l); 
  
    // both even, put the smaller of two first 
    if (!(l & 1) && !(r & 1)) 
        return (l - r); 
  
    // l is even, put r first 
    if (!(l & 1)) 
        return 1; 
  
    // l is odd, put l first 
    return -1; 
} 
 
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        cout<<arr[i]<<" ";
} 
 
int main() 
{ 
    int arr[] = { 1, 6, 5, 2, 3, 9, 4, 7, 8 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
    qsort((void*)arr, size, sizeof(arr[0]), comparator); 
  
    printf("Output array is\n"); 
    printArr(arr, size); 
  
    return 0; 
}
#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low, int high)
{
    int piIndex = low + rand() % (high - low + 1);
    swap(a[piIndex], a[high]);
    int pivot = a[high];
    int i = low - 1;
    for (int j=low;j<=high-1;j++)
    {
        if (a[j]>=pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1],a[high]);
    return  i+1;
}
void quickSort(int a[],int low, int high)
{
    if (low<high)
    {
        int pivot=partition(a, low, high);
        quickSort(a, low, pivot-1);
        quickSort(a, pivot+1, high);
    }
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
   
    int count = 0;
    for (int i= start +1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    while (start < pivotIndex && end> pivotIndex) {
   
        while (arr[start] <= pivot) {
            start++;
        }
   
        while (arr[end] > pivot) {
            end--;
        }
   
        if (start < pivotIndex && end> pivotIndex) {
            swap(arr[start++], arr[end--]);
        }
    }
   
    return pivotIndex;
} 
int partition(int arr[],int low,int high)
{

    int pivot=arr[high];
  //Index of smaller element and Indicate the right position of pivot found so far
  int i=(low-1);
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}
   
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
   
    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    
    quickSort(arr, p + 1, end);
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    quickSort(a, 0, n-1);
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    quickSort(a, 0, n - 1);
    cout<<" after using quick sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
// Function to perform quick sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
vector<int>quick_sort(vector<int>&a)
{
    if(a.size() <= 1) return a;
    int pivot = a.size()-1;
    vector<int> b,c;
    for (int i=0 ; i<a.size();i++)
    {
        if(i== pivot)
        continue;
        
        if(a[i] <= a[pivot])
            b.push_back(a[i]);
        if(a[i] > a[pivot])
            c.push_back(a[i]);
    }
    vector <int> sorted_b=quick_sort(b);
    vector<int> sorted_c= quick_sort(c);
    vector<int> sorted_a;
    for(int i = 0; i <sorted_c.size(); i++)
        sorted_a.push_back(sorted_c[i]);
    sorted_a.push_back(a[pivot]);
    for(int i = 0;i < sorted_b.size(); i++)
        sorted_a.push_back(sorted_b[i]);
    return sorted_a;
}
void print(vector <int> arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sorted_a = quick_sort(a);
    print(sorted_a);
    // Seed the random number generator
    //srand(static_cast<unsigned>(time(nullptr));
    quickSort(a, 0, n - 1);

    cout << "Sorted numbers in non-increasing order: ";
    print(a);
}
#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
// A function to do counting sort of arr[] according to the digit
// represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void stoogesort(int arr[], int l, int h) 
{ 
    if (l >= h) 
        return; 
  
    // If first element is smaller than last, swap them 
    if (arr[l] > arr[h]) 
        swap(arr[l], arr[h]); 
  
    // If there are more than 2 elements in the array 
    if (h - l + 1 > 2) { 
        int t = (h - l + 1) / 3; 
    //Recursively sort first 2/3 elements 
        stoogesort(arr, l, h - t); 
  
    // Recursively sort last 2/3 elements 
        stoogesort(arr, l + t, h); 
    // Recursively sort first 2/3 elements 
    // again to confirm 
        stoogesort(arr, l, h - t); 
    } 
} 
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = { 543, 986, 217, 765, 329 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    radixsort(arr, n);
    print(arr, n);
    stoogesort(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// A recursive function to implement Strand sort.
// ip is input list of items (unsorted). op is output list of items (sorted)
void strandSort(list<int> &ip, list<int> &op)
{
    if (ip.empty())
        return;
    // Create a sorted sublist with first item of input list as first item of the sublist
    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();
      
    // Traverse remaining items of ip list
    for (auto it = ip.begin(); it != ip.end(); ) {
 
        // If current item of input list is greater than last added item to sublist, move current item
        // to sublist as sorted order is maintained.
        if (*it > sublist.back()) {
            sublist.push_back(*it);
 
            // erase() on list removes an item and returns iterator to next of removed item
            it = ip.erase(it);
        }
        // Otherwise ignore current element
        else
            it++;
    }
    // Merge current sublist into output
    op.merge(sublist);
 
    // Recur for remaining items in
    // input and current items in op.
    strandSort(ip, op);
}
int main(void)
{
    list<int> ip{10, 5, 30, 40, 2, 4, 9};
 
    // To store sorted output list
    list<int> op;
 
    // Sorting the list
    strandSort(ip, op);
    // Printing the sorted list
    for (auto x : op)
        cout << x << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int RUN = 32;
// This function sorts array from left index to to right index which is of size atmost RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
    // Original array is broken in two parts left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;
    // After comparing, we merge those two array in larger sub array
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
// Iterative Timsort function to sort the array
}
void timSort(int arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    // Start merging from size RUN (or 32).It will merge to form size 64, then 128, 256 and so on ....
    for (int size = RUN; size < n; size = 2 * size) {

        // pick starting point of left sub array. We are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1] After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2 * size) {
        // Find ending point of left sub array mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            // merge sub array arr[left.....mid] & arr[mid+1....right]
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = { -2, 7,  15,  -14, 0, 15,  0, 7, -7, -4, -13, 5,   8, -14, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    timSort(arr, n);

    printf("After Sorting Array is\n");
    printArray(arr, n);
    return 0;
}
// C++ program to implement Tree Sort 
#include<bits/stdc++.h> 
  
using namespace std; 
  
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Stores inorder traversal of the BST 
// in arr[] 
void storeSorted(Node *root, int arr[], int &i) 
{ 
    if (root != NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/* A utility function to insert a new 
   Node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 
  
// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n) 
{ 
    struct Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        root = insert(root, arr[i]); 
  
    // Store inorder traversal of the BST 
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, i); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    //create input array 
    int arr[] = {5, 4, 7, 2, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    treeSort(arr, n); 
  
        for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 
} 
