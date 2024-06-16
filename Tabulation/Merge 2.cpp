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
