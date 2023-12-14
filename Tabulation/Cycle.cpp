#include <iostream>
using namespace std;
void cyclicSort(int arr[], int n){
    int i = 0; 
    while(i < n)
    {
    int correct = arr[i] - 1 ;
    if(arr[i] != arr[correct]){
      // if array element should be lesser than size and array element should not be at
      // its correct position then only swap with its correct position or index value
      swap(arr[i], arr[correct]) ;
    }else{
      // if element is at its correct position just increment i and check for remaining array elements
      i++ ;
    }
  }
}
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
    // traverse array elements and put it to on the right place
    //i=cycle start.
    for (int i = 0; i <= n - 2; i++) {
        // initialize item as starting point
        int item = arr[i];
 
        // Find position where we put the item. We basically count all smaller elements on right side of item.
        int pos = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < item)
                pos++;
 
        // If item is already in correct position
        if (pos == i)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it's right position
        if (pos != i) {
            swap(item, arr[pos]);
            writes++;
        }
        // Rotate rest of the cycle
        while (pos != i) {
            pos = i;
 
            // Find position where we put the element
            for (int j = i + 1; j < n; j++)
                if (arr[j] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it's right position
            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
    // cout << writes << endl ;
}
int main()
{
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
    cyclicSort(arr, n);
    cout << "\nAfter sort : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
