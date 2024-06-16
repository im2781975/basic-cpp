#include <bits/stdc++.h>
using namespace std;
void insertion(vector <int> a, int n)
{
    for (int i = 1; i < n; i++) {
        int idx = i;
        while (idx >= 1) {
            if (a[idx - 1] > a[idx]) {
                swap(a[idx - 1], a[idx]);
                idx--;
            } else
                break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void insertionSort(int arr[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            cout << arr[j] << " ";
        }
        cout << "\n";
        cout << arr[j] << " ";
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertion(a, n);
    
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int N =10;
    insertionSort(arr, N);
    cout<<"\narray after using insertion sort:"<<endl;
    printArray(arr, N);
    return 0;
}
