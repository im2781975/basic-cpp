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
    
    int n = 5;
    int *grp = new int[n];
    for(int i = 0; i < n; i++) cin >> grp[i];
    cout << grp << endl;
    for(int i = 0; i < n; i++) cout << grp[i] << " ";
    cout << endl;
    cout << grp << endl;
    delete []grp;
    
    int *p, *ter[5];
    int ray[5] = {10, 20, 30, 40, 50};
    p = ray;
    for(int i = 0; i < 5; ++i) ter[i] = &ray[i];
    for(int i = 0; i < 5; ++i) {
        cout << p << " " << ter[i] << endl;
        p++;
    }
    cout << sizeof(p) << " " << sizeof(*ter) << " " << sizeof(*p) << " " << sizeof(ter);
    
    int rr[3][4] = { {10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33} };
    int (*pr)[4]; pr = rr;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << *(*(pr + i) + j) << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 4; i++) cout << pr + i << " " << *(pr + i) << endl;
    // first value of row
    cout << **pr << " " << **(pr + 1) << **(pr + 2) << endl;
    cout << pr[0][0] << " " << pr[1][1] << " " << pr[2][2] << endl;
}
