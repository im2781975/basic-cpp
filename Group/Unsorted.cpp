// find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
#include<bits/stdc++.h>
using namespace std;
void printUnsorted(int arr[],int n)
{
    int l = 0, r = n-1, i, max,min;
    for (l = 0; l < n-1; l++)
    {
        if (arr[l] > arr[l+1])
            break;
    }
    if (l == n-1)
    {
        cout << "The complete array is sorted";
        return;
    }
    for(r = n - 1; r > 0; r--)
    {
        if(arr[r] < arr[r-1])
            break;
    }
    max = arr[l]; min = arr[l];
    for(i = l + 1; i <= r; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    for( i = 0; i < l; i++)
    {
        if(arr[i] > min)
        { 
            l = i;
            break;
        }     
    } 
    for( i = n -1; i >= r+1; i--)
    {
        if(arr[i] < max)
        {
            r = i;
            break;
        } 
    }
    cout << "The unsorted subarray which makes the given array sorted lies between the indices " << l << " and " << r;
    return;
}
// find surpasser count of each element in array
int merge(int *arr, int l, int m, int r,unordered_map<int, int> &hm)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
    //Copy data to temporary arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
 
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    //Merge the temporary array
    i = 0, j = 0, k = l;
    int cnt = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            // increment inversion count of L[i]
            hm[L[i]] += cnt;
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            // inversion found
            cnt++;
        }
    }
    //Copy the remaining elements of L[], if there are any 
    while (i < n1)
    {
        hm[L[i]] += cnt;
        arr[k++] = L[i++];
    }
    //Copy the remaining elements of R[], if there are any 
    while (j < n2)
        arr[k++] = R[j++];
}
int mergeSort(int *arr, int l, int r,unordered_map<int, int> &hm)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, hm);
        mergeSort(arr, m + 1, r, hm);
        merge(arr, l, m, r, hm);
    }
}
void printArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void findSurpasser(int arr[], int n)
{
    unordered_map<int, int> hm;
    int dup[n];
    //copies n bytes from the source memory area to the destination memory area.
    memcpy(dup, arr, n*sizeof(arr[0]));
    // Sort the copy and store inversion count for each element.
    mergeSort(dup, 0, n - 1, hm);
 
    printf("Surpasser Count of array is \n");
    for (int i = 0; i < n; i++)
        cout << (n - 1) - i - hm[arr[i]] << " ";
}
int main()
{
    int arr[] = {10, 12, 20, 30, 25,40, 32, 31, 35, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printUnsorted(arr, n);
   findSurpasser(arr, n);
    return 0;
}
