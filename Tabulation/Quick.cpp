#include<bits/stdc++.h>
using namespace std;
// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
// Function to perform quick sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
vector<int>quick_sort(vector<int>&a)
{
    if(a.size() <= 1) return a;
    int pivot = a.size()-1;
    vector<int> b,c;
    for (int i=0 ; i<a.size();i++)
    {
        if(i== pivot)
        continue;
        
        if(a[i] <= a[pivot])
            b.push_back(a[i]);
        if(a[i] > a[pivot])
            c.push_back(a[i]);
    }
    vector <int> sorted_b=quick_sort(b);
    vector<int> sorted_c= quick_sort(c);
    vector<int> sorted_a;
    for(int i = 0; i <sorted_c.size(); i++)
        sorted_a.push_back(sorted_c[i]);
    sorted_a.push_back(a[pivot]);
    for(int i = 0;i < sorted_b.size(); i++)
        sorted_a.push_back(sorted_b[i]);
    return sorted_a;
}
void print(vector <int> arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sorted_a = quick_sort(a);
    print(sorted_a);
    // Seed the random number generator
    //srand(static_cast<unsigned>(time(nullptr));
    quickSort(a, 0, n - 1);

    cout << "Sorted numbers in non-increasing order: ";
    print(a);
}
