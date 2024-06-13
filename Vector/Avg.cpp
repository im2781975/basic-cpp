#include <bits/stdc++.h>
using namespace std;
int findMax(int arr[], int n)
{
    if (n == 1) return arr[0];
    int max = findMax(arr, n-1);
    return (arr[n-1] > max) ? arr[n-1] : max;
}
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
    int n; cin >> n; int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max = findMax(arr, n);
    cout <<"Maximum element is: "<<max;
    cout << "\nAvg value is: " << getavg(arr, n);
    return 0;
}

