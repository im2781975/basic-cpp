#include <iostream>
#include <algorithm>
using namespace std;
int BinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}
bool IsSubset(int a[], int n, int b[], int m)
{
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        if (BinarySearch(a, 0, n - 1, b[i]) == -1)
            return false;
    }
    return true;
}
int main()
{
    int n, m, a[n], b[m];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (IsSubset(a, n, b, m))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
