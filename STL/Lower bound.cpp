#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<pair<int, int>> arr = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}};

    pair<int, int> targetPair = {3, 30};

    auto low=lower_bound(arr.begin(), arr.end(), targetPair);
    
    auto lowerBoundIndex = low- arr.begin();
    cout << "Lower bound index: " << lowerBoundIndex ;
    return 0;
}
