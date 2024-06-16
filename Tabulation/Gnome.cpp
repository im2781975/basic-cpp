#include <iostream> 
using namespace std; 
void gnomeSort(int arr[], int n) 
{ 
    int index = 0; 
    while (index < n) { 
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(arr[index], arr[index - 1]); 
            index--; 
        } 
    } 
    return; 
} 
int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
            // shift earlier gap-sorted elements up until the correct  location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
void printArray(int arr[], int n) 
{ 
    cout << "Sorted sequence after Gnome sort: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
int main() 
{ 
    int arr[] = { 34, 2, 10, -9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    shellSort(arr, n); 
    gnomeSort(arr, n);
    selectionSort(arr, n);
    printArray(arr, n); 
    return (0); 
} 
