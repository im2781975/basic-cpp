#include<bits/stdc++.h>
using namespace std;
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
   
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = 10;
   
    quickSort(arr, 0, n - 1);
    cout<<" after using quick sort: "<<"\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
   
    return 0;
}
