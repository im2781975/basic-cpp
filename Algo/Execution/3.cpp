// C++ program to find the minimum no. of swaps required to  
// sort an array by swapping elements to correct positions

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}

int main() {
    vector<int> arr = {10, 19, 6, 3, 5}; 
    cout << minSwaps(arr); 
    return 0;
}
// C++ program to find no. of swaps required to 
// sort the array using cycle detection method

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr) {
  	int n = arr.size();
    
  	// Array to Keep track of those elements 
  	// who already been included in the cycle
  	bool vis[n] = {0};
  
  	// Hashing elements with their original positions
  	unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[arr[i]] = i;

    sort(arr.begin(), arr.end());

    int swaps = 0;
    for (int i = 0; i < n; i++) {

        // Already a part of another cycle Or
      	// in its correct position
        if (vis[i] || pos[arr[i]] == i)
            continue;

        int j = i, cycleSize = 0;
      
      	// We make a cycle until it comes
      	// back to first element again.
        while (!vis[j]) {
            vis[j] = true;

            // move to next element of the cycle
            j = pos[arr[j]];
            cycleSize++;
        }

        // Update answer by adding current cycle.
        if (cycleSize > 0) {
            swaps += (cycleSize - 1);
        }
    }
    return swaps;
}

int main() {
    vector<int> arr = { 10, 19, 6, 3, 5 };
    cout << minSwaps(arr);
    return 0;
}
