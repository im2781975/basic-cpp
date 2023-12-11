#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
// Function to partition the array
int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
// Function to perform quick sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    vector<int> numbers;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr));
    quickSort(numbers, 0, n - 1);

    cout << "Sorted numbers in non-increasing order: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
