#include <iostream>
#include <vector>
using namespace std;
 // Function for finding the maximum and minimum element of the Array
void maxMin(vector<int> vec, int n, int& bingo,
            int& nextBingo)
{
    for (int i = 1; i < n; bingo = min(bingo, vec[i]), nextBingo = max(nextBingo, vec[i]), i++)
        ;
}
// Function to sort the array
void bingoSort(vector<int>& vec, int n)
{
    //It repeatedly finds the minimum element (bingo) and moves it to its correct position, updating the next minimum element (nextBingo) for the next pass.
    int bingo = vec[0];
    int nextBingo = vec[0];
    maxMin(vec, n, bingo, nextBingo);
    int largestEle = nextBingo;
    int nextElePos = 0;
    while (bingo < nextBingo) {
        // Will keep the track of the element position to shifted to their correct position
        int startPos = nextElePos;
        for (int i = startPos; i < n; i++) {
            //for loop iterates over the vector from startPos to n.
            //If an element (vec[i]) is equal to bingo, it is swapped with the element at nextElePos, and nextElePos is incremented.
             //If an element is less than nextBingo, it becomes the new value of nextBingo
            if (vec[i] == bingo) {
                swap(vec[i], vec[nextElePos]);
                nextElePos = nextElePos + 1;
            }
            // Here we are finding the next Bingo Element for the next pass
            else if (vec[i] < nextBingo)
                nextBingo = vec[i];
        }
        //After the inner loop, bingo is updated to the current value of nextBingo.nextBingo is reset to the initial value of the largest element (largestEle).
        bingo = nextBingo;
        nextBingo = largestEle;
    }
}
void printArray(vector<int> arr, int n)
{
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = { 5, 4, 8, 5, 4, 8, 5, 4, 4, 4 };
    bingoSort(arr, arr.size());
    printArray(arr, arr.size());
 
    vector<int> arr2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    bingoSort(arr2, arr2.size());
    printArray(arr2, arr2.size());
 
    vector<int> arr3 = { 0, 1, 0, 1, 0, 1 };
    bingoSort(arr3, arr3.size());
    printArray(arr3, arr3.size());
    return 0;
}
