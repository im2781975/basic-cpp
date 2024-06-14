#include <iostream>
#include <vector>
using namespace std;
void maxMin(vector<int> vec, int n,
        int& bingo, int& nextBingo)
{
    for (int i = 1; i < n; i++)
    {
        bingo = min(bingo, vec[i]);
        nextBingo = max(nextBingo, vec[i]), 
    }
}
void bingoSort(vector<int>& vec, int n)
{
    //It repeatedly finds the minimum element (bingo) and moves it to 
    //its correct position, updating the next minimum element (nextBingo) for the next pass.
    int bingo = vec[0];
    int nextBingo = vec[0];
    maxMin(vec, n, bingo, nextBingo);
    int largest = nextBingo;
    int nxtPos = 0;
    while (bingo < nextBingo) {
        // Will keep the track of the element position to shifted to their correct position
        int startPos = nxtPos;
        for (int i = startPos; i < n; i++) {
            if (vec[i] == bingo) {
                swap(vec[i], vec[nextElePos]);
                nextElePos = nextElePos + 1;
            }
            // Here we are finding the next Bingo Element for the next pass
            else if (vec[i] < nextBingo)
                nextBingo = vec[i];
        }
        //After the inner loop, bingo is updated to the current value of nextBingo.
        //nextBingo is reset to the initial value of the largest element.
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
    return 0;
}
