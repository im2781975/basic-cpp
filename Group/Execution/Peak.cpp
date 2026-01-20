// find a peak element 
#include <bits/stdc++.h> 
using namespace std; 
int peak(int *arr, int n){
    int l = 0, r = mid - 1;
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) break;
        if(mid > 0 && arr[mid - 1] > arr[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return mid;
}
int peak(int *arr, int n){
    if(n == 1) return 0;
    if(arr[0] >= arr[1]) return 0;
    if(arr[n - 1] >= arr[n - 2]) return n - 1;
    for(int i = 1; i < n - 1; i++){
        if(arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) return i;
    }
}
// return idx of peak element
int peakutil(int *arr, int low, int high, int n){
    int mid = low + (high - low) >> 1;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&  
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return peakutil(arr, low, (mid - 1), n); 
    else return peakutil( 
            arr, (mid + 1), high, n); 
}
int peak(int *arr, int n){
    return peakutil(arr, 0, n - 1, n);
}
// Inserts a key in arr of given capacity
int insertSorted(int arr[], int n, int key, int capacity) { 
    // Cannot insert more elements if n is already more than or equal to capacity 
    if (n >= capacity)  return n; 
    int i; 
    for (i = n - 1; (i >= 0 && arr[i] > key); i--) 
        arr[i + 1] = arr[i]; 
  
    arr[i + 1] = key; 
    return (n + 1); 
} 
void Insert(int arr[], int n, int x, int pos){
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
    arr[pos] = x;
}
int InvCount(int arr[], int n){
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]) inv_count++;
        }
    }
    return inv_count;
}
// print leader
void Leader(int *arr, int n){
    for(int i = 0; i < n; i++){
        int j;
        for(j = i + 1; j < n; j++){
            if(arr[i] <= arr[j]) break;
            if(j == n) cout << arr[i] << " ";
        }
    }
}
void Leader(int *arr, int n){
    int maxirg = arr[n - 1];
    // rightmost val always leader
    cout << maxirg << " ";
    for(int i = n - 2; i >= 0; i--){
        if(maxirg < arr[i]){
            maxirg = arr[i];
            cout << maxirg << " ";
        }
    }
}
void Leaders(int *arr, int n){
    stack <int> st;
    st.push(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] >= st.top()) st.push(arr[i]);
    }
    while(!st.empty()){
        st.top() << " "; st.pop();
        
    }
}
