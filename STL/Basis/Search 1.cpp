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

void linearSearch(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
            cout<<i<<" ";
        // with break, it will print only one element; without break will print several elements.
    }
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
    cout << "\nAfter sorting, the array is: ";
    print(arr, n);

    int x;
    cout << "\nEnter element for search: ";
    cin >> x;
    cout << "\nElements found at index: ";
    linearSearch(arr, n, x);
    int result = binarySearch(arr, 0, n - 1, x);
    
    (result == -1) ?
        cout << "\nElement doesn't present in the array" :
        cout << "\nElement present at index: " << result;

    if(binary_search(arr, arr + n, 2))
        cout << "\nElement 2 exists";
    else
        cout << "\nElement 2 doesn't exist";
}
