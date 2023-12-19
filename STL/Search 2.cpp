#include <iostream>
#include <vector>
using namespace std;
int searchRotatedArray(const vector<int>& arr, int key) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int index = searchRotatedArray(arr, key);
    if (index != -1) {
        cout << "Found at index " << index ;
    } else {
        cout << "Not found" ;
    }
    return 0;
}
