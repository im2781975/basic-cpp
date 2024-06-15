#include <bits/stdc++.h>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}
void bogosort(int a[], int n)
{
    while (!isSorted(a, n))
    {
        for (int i = 0; i < n; i++)
            swap(a[i], a[rand() % n]);
    }
}
void BrickSort(int arr[], int n)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 1; i<= n -2; i+= 2)
        {
            if (arr[i] > arr[i+1])
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }
        for (int i = 0; i<= n-2; i+= 2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
    return;
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[] = { 3, 2, 5, 1, 0, 4 };
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    cout<<"\nBogo sort: ";
    printArray(a, n);
    BrickSort(a, n);
    printArray(a, n);
    return 0;
}
