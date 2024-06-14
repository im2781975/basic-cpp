#include<bits/stdc++.h>
using namespace std;
// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
void combSort(int a[], int n)
{
    int gap = n;
    bool swapped = true;
    // Keep running while gap is more than 1 and last iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);
        // Initialize swapped as false so that we can check if swap happened or not
        swapped = false;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}
int main()
{
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);
 
    combSort(a, n);
 
    cout<<"\nSorted array is: ";
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
 
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int gapnxt(int gap)
{
    gap = (gap * 10)/13;
    if(gap < 1)
        return 1;
    return gap;
}
void perform(int *arr, int n)
{
    int gap = n;
    bool swaped = true;
    while(gap!=1 || swaped)
    {
        gap = gapnxt(gap);
        swaped = false;
        for(int i =  0; i < n - gap)
        {
            if(arr[i] > arr[i + gap])
                swap(arr[i], arr[i + gap]);
                swaped = true;
        }
        
    }
}
int main()
{
    int arr[]{2, 3, 1, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    perform(arr, n);
}
