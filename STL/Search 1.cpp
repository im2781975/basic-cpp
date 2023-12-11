#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int binarySearch(int arr[], int low, int high, int x)
{
    int mid = low + (high - low) / 2;
    while(low <= high)
    {
        if(arr[mid] == x)
        {
            return mid;
            break;
        }
        else if(arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 2];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << "\nAfter sort array is: ";
    print(arr, n);

    int x;
    cout<<"\nEnter elements for search: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    
    (result == -1)?
        cout << "\nElement doesn't present in the array":
        cout << "\nElement present at index: " << result;

    if(binary_search(arr, arr + n, 2))
        cout << "\nElements 2 exists";
    else
        cout << "\nElements 2 doesn't exist";
}
