#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int arr1[], int arr2[], int m, int n) {
    unordered_set<int> elements;
    
    for (int i = 0; i < m; i++) {
        elements.insert(arr1[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (elements.find(arr2[i]) == elements.end()) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int m, n;
    cin >> m;
    int arr1[m];
    
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    
    cin >> n;
    int arr2[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    
    if (isSubset(arr1, arr2, m, n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
