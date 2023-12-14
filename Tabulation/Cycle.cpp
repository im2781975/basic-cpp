#include <iostream>
using namespace std;

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
    // Number of memory writes or swaps
    // cout << writes << endl ;
}
int main()
{
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
 
    cout << "\nAfter sort : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
