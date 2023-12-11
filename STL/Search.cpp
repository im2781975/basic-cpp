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
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n + 2];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    binarySearch_iterative(arr, n, k);
    return 0;
}
