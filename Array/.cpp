#include<bits/stdc++.h>
using namespace std;
//return the only occurring which is odd or even
int findOdd(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
int main(){
    int arr[] = {12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findOdd(arr, n);
}
using namespace std;
int main(){
    int arr[5];
    arr[0] = -1; arr[3 / 2] = 1; arr[2] = arr[0];
    int i = 0;
    while(arr[i]){
        cout << arr[i] << " ";
        i++;
    }
    char ar[5] = {'a', 'b', 'c'};
    int i = 0;
    while(ar[i]){
        cout << ar[i] << " ";
        i++;
    }
}
