#include <bits/stdc++.h>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}
// To generate permutation of the array
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
    // if array is not sorted then shuffle the array again
    while (!isSorted(a, n))
        shuffle(a, n);
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int a[] = { 3, 2, 5, 1, 0, 4 };
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    cout<<"\nBogo sort: ";
    printArray(a, n);
    return 0;
}
