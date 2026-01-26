#include<bits/stdc++.h>
using namespace std;
void binarySearch_iterative(int arr[],int n,int k)
{
    int low = 0, high = n - 1;
    bool flag=0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout<<"\nLow: "<< low <<" High: "<<high<<" Mid: "<<mid;
        if (arr[mid] == k) {
            cout << "\nPresent at index: "<<mid;
            flag=1;

            
            break;
        } else if (arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if(flag==0)
    {
        cout<<"\nDoesn't exits";
    }
}
int binarySearch_recursive(int arr[], int low, int high, int x)
{
    int mid=low+(high-low)/2;
    while(low<=high)
    {
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            return binarySearch_recursive(arr,0,mid-1,x);
        }
        else
        {
            return binarySearch_recursive(arr,mid+1,high,x);
        }
    }
    return -1;
}
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n + 2];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    binarySearch_iterative(arr, n, k);
    int result=binarySearch_recursive(arr, 0, n-1, k);
    (result==-1)?
    cout<<"\nElement doesn't found":
    cout<<"\nElement found at index: "<<result;
    return 0;
}
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
#include <iostream>
#include <vector>
using namespace std;
int searchRotatedArray(const vector<int>& arr, int key) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int index = searchRotatedArray(arr, key);
    if (index != -1) {
        cout << "Found at index " << index ;
    } else {
        cout << "Not found" ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>primes;
    vector<bool>visited(n+1);

    for(int i=2;i<=n;i++)
    {
        if(visited[i]==false)
        {
            primes.push_back(i);
            for(int x=2;i*x<=n;x++)
            {
                visited[i*x] = true;
            }
        }
    }
    for(int i=0; i<primes.size(); i++)
        cout<<primes[i]<<" ";
    return 0;
}
