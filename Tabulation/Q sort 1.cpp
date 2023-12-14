#include <iostream>
#include <cstdlib>

using namespace std;

// This function is used in qsort to decide the relative 
// order of elements at addresses p and q.
int comparator(const void* p, const void* q)
{
    // Get the values at given addresses
    int l = *(const int*)p;
    int r = *(const int*)q;
    // both odd, put the greater of two first.
    if ((l & 1) && (r & 1))
        return (r - l);
    // both even, put the smaller of two first
    if (!(l & 1) && !(r & 1))
        return (l - r);
    // l is even, put r first
    if (!(l & 1))
        return 1;
    // l is odd, put l first
    return -1;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {1, 6, 5, 2, 3, 9, 4, 7, 8};

    int size = sizeof(arr) / sizeof(arr[0]);
    qsort((void*)arr, size, sizeof(arr[0]), comparator);

    cout << "Output array is" << endl;
    printArr(arr, size);

    return 0;
}
