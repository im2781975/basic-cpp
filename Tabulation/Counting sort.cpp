#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int n) {
    // Create a counting array to track the frequency of each number
    vector<int> count(n, 0);
    // Count the frequency of each number in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Output the sorted numbers based on the counting array
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    countingSort(numbers, n);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
