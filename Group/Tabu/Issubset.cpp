#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <algorithm>
using namespace std;
int Bsearch(int arr[], int low, int high, int key){
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot) {
            i++; swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void Quick(int arr[], int low, int high){
    if (low < high) {
        int pivot = partition(arr, low, high);
        Quick(arr, low, pivot - 1);
        Quick(arr, pivot + 1, high);
    }
}
bool Issubset(int *arr, int n, int *ray, int m) {
    Quick(arr, 0, n - 1);
    for(int i = 0; i < m; i++) {
        if(Bsearch(arr, 0, n - 1, ray[i])) return false;
    }
    return true;
}
