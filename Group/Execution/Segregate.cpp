#include<bits/stdc++.h>
using namespace std;
//find position to insert current element of stream using binary search
int Bsearch(float arr[], float item, int low, int high){
    if (low >= high)
        return (item > arr[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == arr[mid])
        return mid + 1;
    if (item > arr[mid])
        return Bsearch(arr, item, mid + 1, high);
 
    return Bsearch(arr, item, low, mid - 1);
}
// Function to print median of stream of integers
void printmedian(float *arr, int n) {
    int i, j, pos, cnt = 1;
    float num;
    for(i = 1; i < n; i++) {
        float median; 
        j = i - 1; num = arr[i];
        pos = Bsearch(arr, num, 0, j);
        while(j >= pos) {
            arr[j + 1] = arr[j]; j--;
        }
        arr[j + 1] = num; cnt++;
        if(cnt % 2 != 0)
            median = arr[cnt / 2];
        else median = (arr[(cnt / 2) - 1] + arr[cnt / 2]) / 2;
        cout << i + 1 << " " << median << endl;
    }
}
void streamed(int *arr, int n){
    priority_queue <int> g, s;
    for(int i = 0; i < n; i++) {
        s.push(arr[i]);
        int tmp = s.top(); s.pop();
        g.push(-1 * tmp);
        if(g.size() > s.size()) {
            int tmp = g.top(); g.pop();
            s.push(-1 * tmp);
        }
        if(g.size() != s.size()) cout << (double)s.top() << endl;
        else cout << (double)((s.top() - g.top()) / 2) << endl;
    }
}
void pushzeros(vector <int> &vec){
    stable_partition(vec.begin(), vec.end(), [](int n) {return n != 0;});
}
void multarr(int *arr, int n){
    if(n == 0) return 1;
    return arr[n - 1] * multarr(arr, n - 1);
}
void sumarr(int *arr, int n){
    if(n == 0) return 0;
    return arr[n - 1] + sumarr(arr, n - 1);
}
void revarr(int *arr, int start, int end) {
    while(start < end) {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++; end--;
    }
}
void revarr(int *arr, int start, int end) {
    if (start >= end) return;
    int tmp = arr[start]; 
    arr[start] = arr[end];
    arr[end] = tmp;
    revarr(arr, start + 1, end - 1);
}
// Function to segregate even odd numbers
vector <int> segregateEvenOdd(vector <int> arr) {
    int i = -1, j = 0;
    int piv = arr.back();
    for(int j = 0; j < arr.size() - 1; j++) {
        if(arr[j] % 2 == 0) {
            i++; swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr.back()); return arr;
}
