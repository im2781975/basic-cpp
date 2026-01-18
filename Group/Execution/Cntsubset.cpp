#include<bits/stdc++.h>
using namespace std;
//find number of rotations in a sorted and rotated array for being sorted
int countRotations(int arr[], int n) { 
    int min = arr[0], idx = 0; 
    for (int i = 0; i < n; i++) { 
        if (min > arr[i]) { 
            min = arr[i];  idx = i; 
        } 
    } 
    return idx;
}
int countRotations(int *arr, int n){ 
    for (int i = 0; i < n; i++){
        if (arr[i] > arr[i + 1] && i + 1 < n) return i + 1;
    }
    return -1;
}
int countRotations(int *arr, int low, int high) { 
    if (high < low) return 0; 
    if (high == low) return low; 
    int mid = low + (high - low) / 2;
    if (mid < high && arr[mid + 1] < arr[mid]) return (mid + 1); 
    if (mid > low && arr[mid] < arr[mid - 1]) return mid; 
    if (arr[high] > arr[mid]) 
        return countRotations(arr, low, mid - 1); 
    return countRotations(arr, mid + 1, high); 
}
int countRotations(int *arr, int n) { 
    int low = 0, high = n - 1; 
    if (arr[low] <= arr[high]) return 0; 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        int prev = (mid - 1 + n) % n; 
        int next = (mid + 1) % n; 
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) return mid; 
        else if (arr[mid] <= arr[high])  high = mid - 1; 
        else if (arr[mid] >= arr[0]) low = mid + 1; 
    }
    return 0; 
}
int findPivot(int *arr, int n) { 
    int low = 0, high = n - 1; 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        if (mid < high && arr[mid] > arr[mid + 1]) return mid; 
        if (mid > low && arr[mid - 1] > arr[mid]) return mid - 1; 
        if (arr[low] > arr[mid]) high = mid - 1; 
        else low = mid + 1; 
    } 
    return -1; 
}
int countRotations(int arr[], int n){ 
    int pivot = findPivot(arr, n); 
    return pivot + 1; 
}
// find number of subset containing consecutive numbers 
int countsubsets(int *arr, int n){ 
    unordered_set <int> s;
    int count = 0;
    for(int i = 0; i < n; i++) s.insert(arr[i]);
    for(int i = 0; i < n; i++){
        if(s.find(arr[i] - 1) == s.end()){
            int j = arr[i];
            while(s.find(j) != s.end()) j++;
            count++;
        }
    }
    return count; 
} 
int countsubset(int *arr, int n) { 
    sort(arr, arr + n); 
    int count = 1; 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + 1 != arr[i + 1]) count++;
    }
    return count; 
} 
int main(){
    int arr[] = { 15, 18, 2, 3, 6, 12 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << countRotations(arr, n);
    cout << countRotations(arr, 0, N - 1);
    cout << coubtsubset(arr, n);
}


