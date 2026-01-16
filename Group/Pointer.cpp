//demonstrate the relation between arrays and pointers
#include<bits/stdc++.h>
using namespace std;
#define x 3
void way(int arr[][x]) { 
    int *ptr = (int *)arr; 
    sort(ptr, ptr + x * x); 
}
int* func() {
    static int arr[5] = { 1, 2, 3, 4, 5 };
    return arr;
}
int main(){
    int arr[5] = {10, 20, 30, 40, 50 };
    int *ptr = &arr[0];
    cout << arr << " " << &arr[0] << endl;
    for(int i = 0; i < 5; i++)
        cout << *ptr++ << " ";
    cout << endl;
    
    int ar[x][x] = {{1, 0, 3,}, {2, 5, 6},{9, 4, 8}}; 
    way(ar);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
    int *tr = func();
    for (int i = 0; i < 5; i++) cout << *tr++ << " ";
    cout << endl;
}
