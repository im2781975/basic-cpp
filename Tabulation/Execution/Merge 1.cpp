// sort an array of strings in lexicographic order using the merge sort algorithm
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Merge two subarrays of arr[]
void merge(vector<string>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<string> leftArr(n1);
    vector<string> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
// Merge sort function
void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
int main() {
    vector<string> arr;
    int n;

    cout << "Enter the number of strings: ";
    cin >> n;

    cin.ignore();  // Consume the newline character
    for (int i = 0; i < n; i++) {
        string str;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, str);
        arr.push_back(str);
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted strings in lexicographic order:\n";
    for (const string& str : arr) {
        cout << str << "\n";
    }
    return 0;
}
