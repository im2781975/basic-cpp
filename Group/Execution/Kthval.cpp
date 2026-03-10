#include<bits/stdc++.h>
using namespace std;
// Function to find the cross over point (the point before which elements are 
// smaller than or equal to x and after which greater than x)
int findcross(int *arr, int low, int high, int x) {
    if(arr[high] <= x) return high;
    if(arr[low] > x) return low;
    int mid = (low + high) / 2;
    if(mid < high && arr[mid] <= x && arr[mid + 1] > x) return mid;
    if(arr[mid] <= x) return findcross(arr, mid + 1, high, x);
    else return findcross(arr, low, mid - 1, x);
}
void showKclosest(int *arr, int n, int x, int k) {
    int l = findcross(arr, 0, n - 1, x);
    int r = (l + 1 < n) ? l + 1 : n - 1, cnt = 0;
    if(l >= 0 && arr[l] == x) l--;
    while(l >= 0 && r < n && cnt < k) {
        if(x - arr[l] < arr[r] - x) cout << arr[l--] << " ";
        else cout << arr[r++] << " ";
        cnt++;
    }
    while(cnt < k && l >= 0) {
        cout << arr[l--] << " "; cnt++;
    }
    while(cnt < k && r < n) {
        cout << arr[r++] << " "; cnt++;
    }
}
vector <int> findclosest(vector <int> &arr, int n, int k) {
    int l = 0, r = arr.size() - 1;
    while(r - l + 1 > k) {
        if(x - arr[l] > arr[r] - x) l++;
        else r--;
    }
    vector <int> res(arr.begin() + l, arr.begin() + r + 1);
    sort(res.begin(), res.end()); return res;
}
void nthlargest(int *arr, int n, int k) {
    sort(arr, arr + n, greater, int> ());
    for(int i = 0; i < k; i++) cout << arr[i] << " "; /*
    priority_queue <int, vector <int>, greater <int>> pq; // minheap
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top(); */ /*
    priority_queue <int> pq; // maxheap
    for(int i = 0; i < n; i++) pq.push(arr[i]);
    while(k-- > 0) {
        cout << pq.top() << " "; pq.pop();
    } */
}
// Function to find the Kth largest element in the array using binary search
int largest(int *arr, int n, int k) {
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < n; i++) {
        low = min(low, arr[i]); high = max(high, arr[i]);
    }
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid) cnt++;
        }
        if(cnt >= k) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
void kthlargest(int *arr, int n, int k) {
    int val = largest(arr, n, k);
    for(int i = 0; i < val; i++) {
        if(arr[i] >= val) cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int *arr, int l, int r) {
    int piv = arr[r], i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= piv) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]); return l;
}
int kthlargest(int *arr, int l, int r, int k) {
    int pos = partition(arr, l, r);
    if(pos == l + k - 1) return arr[pos];
    if(pos > l + k - 1) return kthlargest(arr, l, pos - 1, k);
    else return kthlargest(arr, pos + 1, r, k - (pos - l + 1));
}
int kthlargest(int *arr, int n, int k) {
    priority_queue <int> pq;
    for(int i = 0; i < n; i++) pq.push(arr[i]);
    while(pq.size() > n - k) pq.pop();
    while(!pq.empty()) {
        cout << pq.top() << " "; pq.pop();
    }
}
void kthlargest(vector <int> arr, int n, int k) {
    priority_queue <int, vector <int>, greater <int>> pq; /*
    vector <int> res(n);
    for(int i = 0; i < n; i++) {
        if(pq.size() < k) pq.push(arr[i]);
        else {
            if(arr[i] < pq.top()) {
                pq.pop(); pq.push(arr[i]);
            }
        }
        if(pq.size() < k) res[i] = -1;
        else res[i] = pq.top();
    }
    return res; */
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    while(!pq.empty()) {
        cout << pq.top() << " "; pq.pop();
    }
}
// returns kth smallest index in the matrix
int kthsmallest(int grid[4][4], int n, int k) {
    int l = grid[0][0], r = grid[n - 1][n - 1];
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int val = count(mid, n, grid);
        if(val >= k) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int count(int num, int n, int grid[4][4]) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(grid[i][mid] <= num) left = mid + 1;
            else right = mid - 1;
            
        }
        res += left;
    }
    return res;
}
int kthsmallest(int *arr, int n, int k) {
    priority_queue <int> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}
int kthsmallest(int arr[][4], int n, int k) {
    priority_queue <int, vector <int>, greater <int>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) pq.push(arr[i][j]);
    }
    int cnt = 0;
    while(!q.empty()) {
        int tmp = q.top(); q.pop();
        cnt++;
        if(cnt == tmp) return tmp;
    }
    return -1;
}
int kthsmallest(int grid[4][4], int n, int k) {
    int arr[n * n], x = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            arr[x++] = grid[i][j];
    }
    sort(arr, arr + n * n);
    return arr[k - 1];
}
int kthsmallest(vector <vector <int>> &grid, int k) {
    priority_queue <int, vector <int>, greater <int>> pq;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) pq.push(grid[i][j]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}
int count(vector <int> arr, int val) {
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] <= val) cnt++;
    }
    return cnt;
}
int kthsmallest(int *arr, int n, int k) {
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < n; i++) {
        low = min(low, arr[i]); high = max(high, arr[i]);
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (count(arr, mid) < k) low = mid + 1;
        else high = mid;
    }
    return low;
}
int partition(int *arr, int l, int r) {
    int piv = arr[r], i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= piv) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]); return i;
}
int kthlargest(int *arr, int l, int r, int k) {
    int pos = partition(arr, l, r);
    if(pos == l + k - 1) return arr[pos];
    if(pos > l + k - 1) return kthlargest(arr, l, pos - 1, k);
    else return kthlargest(arr, pos + 1, r, k - (pos - l + 1));
}
int kthsmallest(int *arr, int n, int k) {
    int maxi = arr[0];
    for(int i = 1; i < n; i++) {
        if(maxi < arr[i]) maxi = arr[i];
    }
    vector <int> freq(maxi + 1, 0);
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    int cnt = 0;
    for(int i = 0; i <= maxi; i++) {
        cnt += freq[i];
        if(cnt >= k) return i;
    }
    return -1;
}
int kthsmallest(int *arr, int n, int k) {
    sort(arr, arr + n); return arr[k - 1];
}
int partition(int *arr, int l, int r) {
    swap(arr[r], arr[rand() % (r - l + 1) + 1]);
    int piv = arr[r], i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= piv) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]); return i;
}
int kthsmallest(int *arr, int l, int r, int k) {
    int pos = partition(arr, l, r);
    int left = pos - l + 1;
    if(left == k) return arr[pos];
    if(left > k) return kthsmallest(arr, l, pos - 1, k);
    else return kthsmallest(arr, pos + 1, r, k - left);
