#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    } else {
        int maxInRest = findMax(arr, size - 1);
        return maxInRest > arr[size - 1] ? maxInRest : arr[size - 1];
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxElement = findMax(arr, n);
    cout << maxElement ;
    
    int num, test = 40; 
    num = test < 10 ? 10 : test + 10; 
  
    cout << "\nNum - Test : " << num - test; 
  
    int A = 39, B = 10, C = 23; 
    int maxNum 
        = (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C); 
    cout << "\nLargest number is " << maxNum ; 
    return 0;
}

