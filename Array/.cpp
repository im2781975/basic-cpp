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
using namespace std;
//Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers.print the respective minimum and maximum values
int main(){
    int n = 5;
    int arr[n], sum, tmp = -888;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ray[n];
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j];
        }
        ray[i] = sum;
    }
    for(int i = 0; i < n; i++){
        if(ray[i] > ray[i + 1]){
            int tmp = ray[i + 1];
            ray[i + 1] = ray[i];
            ray[i] = tmp;
        }
    }
    cout << ray[n - 2] << " " << ray[n - 1];
}
//Allocation memory
using namespace std;
int main (){
    int* p = NULL;
    //you can use "new (nothrow)" when allocating memory to prevent an exception from being thrown
    // if the allocation fails for shortes memory in heap for continue the code.
    p = new(nothrow) int;
    if (!p)
        cout << "allocation of memory failed\n";
    else{
        *p = 29;
        cout << "Value of p: " << *p <<"\n";
    }
    float *r = new(nothrow) float(75.25);
    cout << "Value of r: " << *r << "\n";
    int n = 5;
    int *q = new(nothrow) int[n];
    if (!q) cout << "allocation of memory failed\n";
    else{
        for (int i = 0; i < n; i++)
            q[i] = i + 1;
        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    delete p;
    delete r;
    delete[] q;
}
using namespace std;
//Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction
int main(){
    int n; cin >> n;
    int arr[n + 2];
    int pos = 0, neg = 0, zero = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos++;
        else if(arr[i] < 0) neg++;
        else zero++;
    }
    double plus = (double)pos / n;
    double Minus = (double)neg / n;
    double zeros = (double)zero / n;
    cout << fixed << setprecision(6) << plus << "\n" << Minus << "\n" << zeros;
}
