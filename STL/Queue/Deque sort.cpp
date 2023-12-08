#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    deque<int> ladder;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ladder.push_back(num);
    }
    sort(ladder.begin(), ladder.end());
    cout << "Sorted Ladder Array: ";
    for (const int& num : ladder) {
        cout << num << " ";
    }
    return 0;
}

