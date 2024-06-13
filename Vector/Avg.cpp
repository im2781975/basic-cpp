#include<bits/stdc++.h>
using namespace std;
int getavg(int *arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    float avg = sum/n;
    return avg;
}
int main()
{
    int arr[]{2, 3, 1, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << getavg(arr, n);
}
