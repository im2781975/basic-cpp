#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    int arr[n+5];
    for(int i = 1; i<= n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        for(int j = i+1; j<= n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 1; i<= n; i++)
        cout <<  arr[i] << " ";
    return 0;
}
