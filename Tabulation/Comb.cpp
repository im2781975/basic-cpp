#include<bits/stdc++.h>
using namespace std;
int getNextGap(int gap)
{
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
        gap = getNextGap(gap);
        // Initialize swapped as false so that we can check if swap happened or not
        swapped = false;
        for(int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}
void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;
        // move the end point back by one, because item at the end is in its rightful spot
        --end;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would
        //have moved the next smallest number to its rightful spot.
        ++start;
    }
}
int main()
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    combSort(arr, n);
    CocktailSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
