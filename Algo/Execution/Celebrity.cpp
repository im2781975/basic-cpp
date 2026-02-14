#include<bits/stdc++.h>
using namespace std;
// Find the val greater than all values to its left and smaller than all values to its right.
bool check(int *arr, int n, int idx) {
    int i = idx - 1, j = idx + 1;
    while(i >= 0) {
        if(arr[i] > arr[idx]) return false;
        i--;
    }
    while(j < n) {
        if(arr[j] < arr[idx]) return false;
        j++;
    }
    return true;
}
int findval(int *arr, int n) {
    int left[n]; left[0] = INT_MIN;
    for(int i = 1; i < n; i++)
        left[i] = min(left[i - 1], arr[i - 1]);
    int right = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        if(left[i] < arr[i] && right > arr[i]) return i;
        right = min(right, arr[i]);
    }
    return -1;
}
int findval(int *arr, int n) {
    if(n <= 2) return -1;
    int maxleft = arr[0], candid = -1;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > maxleft) {
            maxleft = arr[i]; continue;
        }
        bool rightgreater = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] <= arr[i]) {
                rightgreater = false; break;
            }
        }
        if(rightgreater) return i;
    }
    return -1;
}
// Calculate stock span for each day: number of consecutive previous days 
// (including today) where price ≤ current day's price
int calculatespan(int *price, int n, int *res) {
    res[0] = 1;
    for(int i = 1; i < n; i++) {
        int counter = 1;
        while ((i - counter) >= 0 && price[i] >= price[i - counter])
            counter += res[i - counter];
        res[i] = counter;
    }
}
// calculate stock span values
void calculatespan(int *price, int n, int *span) {
    span[0] = 1;
    for(int i = 1; i < n; i++) {
        span[i] = 1;
        for(int j = i - 1; (j >= 0 && (price[i] >= price[j])); j++) {
                span[i]++;
        }
    }
    
    stack <int> st; st.push(0);
    span[0] = 1;
    for(int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i]) st.pop();
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}
vector <int> calculatespan(int *arr, int n) {
    stack <int> st; vector <int> res;
    for(int i = 0; i < n; i++) {
        while (!st.empty() and arr[st.top()] <= arr[i]) st.pop();
        if(st.empty()) res.push_back(i + 1);
        else res.push_back(i - st.top());
        st.push(i);
    }
    return res;
}
//Function to get index of ceiling of val in arr[]
int ceilsearch(int *arr, int low, int high, int val) {
    int i;
    if(val <= arr[low]) return low;
    for(int i = low; i < high; i++) {
        if(arr[i] == val) return i;
        if(arr[i] < val && arr[i + 1] >= val) return i + 1;
    }
    return -1;
}
int ceilsearch(int *arr, int low, int hight, int val) {
    if(val <= arr[low]) return low;
    if(val > arr[high]) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == val) return mid;
    else if (arr[mid] < val) {
        if (mid + 1 <= high && val <= arr[mid + 1]) return mid + 1;
        return ceilsearch(arr, mid + 1, high, val);
    }
    if (arr[mid - 1] >= val) return ceilsearch(arr, low, mid - 1, val);
    return mid;
}
int ceilsearch(int *arr, int low, int high, int val) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) return mid;
        else if (val < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
void ceilsearch(vector <int> arr, int val) {
    auto it = lower_bound(arr.begin(), arr.end(), val);
    int idx = it - arr.begin();
    if(idx == arr.size()) cout << "ceil val doesn't exits";
    else cout << val << " " << arr[idx] << endl;
}
// Find celebrity in party: person known by everyone else but knows no one
int celebrity(vector <vector <int>> grid) {
    int n = grid.size(), cand = 0;
    for(int i = 0; i < n; i++) {
        if(grid[cand][i] == 0) cand = i;
    }
    for(int i = 0; i < n; i++) {
        if(grid[cand][i] == 1) return -1;
    }
    for(int i = 0; i < n; i++) {
        if(i != cand && grid[i][cand] == 0) return -1;
    }
    return cand;
}
// Find celebrity in party: person known by everyone else 
//but knows no one (given adjacency matrix M where M[i][j]=1 means i knows j).
bool grid[8][8]{ {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
bool knows(int a, int b) {return grid[a][b];}
int celebrity(int n) {
    int cand = 0;
    for (int i = 0; i < n; i++) {
        if (knows(cand, i) == 0) cand = i;
    }
    for (int i = 0; i < n; i++) {
        if (knows(cand, i)) return -1;
    }
    for (int i = 0; i < n; i++) {
        if (i != cand && !knows(i, cand)) return -1;
    }
    return cand;
}
int findCelebrity(int n) {
    int arr[n] = {0}, ray[n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = knows(i, j);
            ray[i] += x; arr[j] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == n - 1 && ray[i] == 0) return i;
    }
    return -1;
}
int findcelebrity(int n) {
    stack <int> st; int cand;
    for(int i = 0; i < n; i++) st.push(i);
    while(st.size() > 1) {
        int x = st.top(); st.pop(); 
        int y = st.top(); st.pop();
        if(knows(x, y)) st.push(y);
        else st.push(x);
    }
    cand = st.top(); st.pop();
    for (int i = 0; i < n; i++) {
        if ((i != cand) && (knows(cand, i) || !knows(i, cand)))
            return -1;
    }
    for(int i = 0; i < n; i++) {
        if(i != cand && (knows(cand, i) || !knows((i, cand)))) return -1;
    }
    return cand;
}
int celebrity(int n) {
    int id = find(n);
    if (id == -1) return id;
    else {
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(i != id) {
                x += knows(id, i);
                y += knows(i, id);
            }
        }
        if(x == 0 && y == n - 1) return id;
    }
    return -1;
}
int find(int n) {
    if(n == 0) return -1;
    int id = find(n - 1);
    if(id == -1) return n - 1;
    else if(knows(id, n - 1)) return n - 1;
    else if(knows(n - 1, id)) return id;
    return -1;
}
int celebrity(int grid[4][4], int n) {
    int cand = 0;
    for(int i = 1; i < n; i++) {
        if(grid[cand][i] == 1) cand = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            if (grid[cand][i] == 1 || grid[i][cand] == 0) return -1;
        }
    }
    return cand;
}
