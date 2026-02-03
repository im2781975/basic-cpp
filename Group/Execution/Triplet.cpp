#include<bits/stdc++.h>
using namespace std;
//find the min and max values that can be calculated by summing exactly four of the five integers
void maxmin(int *arr, int n) {
    int tmp[n], sum;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            sum += arr[j];
        }
        tmp[i] = sum;
    }
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(tmp[i] < mn) mn = tmp[i];
        if(tmp[i] > mx) mx = tmp[i];
    }
    cout << mx << " " << mn;
}
int left(int *arr, int l, int r, int key) {
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= key) r = mid;
        else l = mid;
    }
    return r;
}
int right(int *arr, int l, int r, int key) {
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= key) l = mid;
        else r = mid;
    }
    return l;
}
int cntfreq(int *arr, int n, int key) {
    int l = left(arr, -1, n - 1, key);
    int r = right(arr, 0, n - 1, key);
    return (arr[l] == key && key == arr[r]) ? (r - l + 1) : -1;
}
int Bsearch(int *arr, int l, int r, int key){
    if(r < l) return -1;
    int mid = l + (r - l) / 2;
    if(key == arr[mid]) return mid;
    else if(key > arr[mid]) return  Bsearch(arr, mid + 1, r, key);
    else return Bsearch(arr, l, mid - 1, key);
}
int Deleteval(int *arr, int n, int key){
    int pos = Bsearch(arr, 0, n - 1, key);
    if(pos == -1) return n;
    for(int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}
// find the Minimum length of Unsorted Subarray
void unsorted(int *arr, int n) {
    int l = 0, r = n - 1;
    while(l < n - 1 && arr[l] <= arr[l + 1])    l++;
    if(l == n - 1) return;
    while (r > 0 && arr[r] >= arr[r - 1]) r--;
    int submin = arr[l], submax = arr[l];
    for (int i = l + 1; i <= r; i++) {
        submin = min(submin, arr[i]);
        submax = max(submax, arr[i]);
    }
    for(int i = 0; i < l; i++){
        if(arr[i] > submin) l = i; break;
    }
    for(int i = n - 1; i > r; i--){
        if(arr[i] < submax) r = i; break;
    }
    cout << l << " " << r << endl;
}
void findsurpassar(int *arr, int n) {
    vector <int> vec(arr, arr + n);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(vec.begin(), vec.end(), arr[i]);
        cout << vec.end() - it;
        // cout << vec.end() - upper_bound(vec.begin(), vec.end(), arr[i]) << " ";
    }
}
void cntsurpasser(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) ++cnt;
        }
        cout << cnt << " ";
    }
}
// Returns length of smallest subarray with sum greater than x. 
int subarrlen(int *arr, int n, int x) {
    int cur = 0, minlen = n + 1, l = 0, r = 0;
    while(r < n) {
        while(cur <= x && r < n) cur += arr[r++];
        while(cur > x && l < n) {
            if(r - l < minlen) minlen = r - l;
            cur -= arr[l++];
        }
    }
    return minlen;
}
int subarrlen(int *arr, int n, int x) {
    int minlen = n + 1;
    for(int i = 0; i < n; i++) {
        int cur = arr[i];
        if(cur > x) return 1;
        for(int j = i + 1; j < n; j++) {
            cur += arr[j];
            if(cur > x && (j - i + 1) < minlen) minlen = j - i + 1;
        }
    }
    return minlen;
}
int subarrlen(vector <int> arr, int x) {
    int n = arr.size(), res = INT_MAX - 1;
    if(n == 0) return 1;
    vector <int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i - 1];
    for(int i = 1; i <= n; i++) {
        int val = x + sum[i - 1];
        auto find = lower_bound(sum.begin(), sum.end(), val);
        if(find != sum.end() && *find != val) {
            int len = find - (sum.begin() + i - 1);
            res = min(res, len);
        }
    }
    return res;
}
// finds and prints the first contiguous subarray equaling a target sum.
void subarrsum(int *arr, int n, int sum) {
    for(int i = 0; i < n; i++) {
        int cur = arr[i];
        if(cur == sum) { cout << i << " "; return; }
        else {
            for(int j = i + 1; j < n; j++) {
                cur += arr[j];
                if(cur == sum) cout << i << " " << j << endl; return;
            }
        }
    }
    return;
}
int subarrsum(int *arr, int n, int sum) {
    int l = 0, cur = arr[0];
    for(int i = 1; i <= n; i++) {
        if(i < n) cur += arr[i];
        if(cur == sum) {
            cout << l << " " << i - 1 << endl; return 1;
        }
        while(cur > sum && l < i - 1) cur -= arr[l++];
    }
    return 0;
}
vector <int> subarrsum(vector <int> arr, int sum) {
    unordered_map <int, int> mp;
    int cur = 0;
    for(int i = 0; i < arr.size(); i++) {
        cur += arr[i];
        if (mp.count(cur - sum))
            return vector <int> (arr.begin() + mp[cur - sum] + 1, arr.begin() + i + 1);
        mp[cur] = i;
    }
    return {};
}
void freq(vector <int> arr) {
    unordered_map <int, int> mp;
    for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
    vector <pair <int, int> > items;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        items.emplace_back({it-> second, it-> first});
    }
    sort(items.begin(), items.end(), [](pair <int, int> x, pair <int, int> y) {
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    int i = 0;
    for(auto it = items.begin(); it != items.end(); ++it) {
        for(int j = 0; j < it -> first; j++)
            arr[i++] = it -> second;
    }
}
// Function to reorder elements of arr[] according to index[]
bool comp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}
void reorder(int *arr, int *idx, int n) {
    vector <pair <int, int>>vec(n);
    for(int i = 0; i < n; i++) {
        vec[i].first = arr[i];
        vec[i].second = idx[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; i++) 
        arr[i] = vec[i].first;
}
void reorder(int *arr, int *idx, int n) {
    for(int i = 0; i < n; i++) {
        while(idx[i] != i) {
            int dig = idx[idx[i]];
            char ch = arr[idx[i]];
            
            arr[idx[i]] = arr[i];
            idx[idx[i]] = idx[i];
            
            idx[i] = dig;
            arr[i]   = ch;
        }
    }
}
void reorder(int *arr, int *idx, int n) {
    int tmp[n];
    for(int i = 0; i < n; i++) tmp[idx[i]] = arr[i];
    for(int i = 0; i < n; i++) {
        arr[i] = tmp[i];
        idx[i] = i;
    }
}
void printSpiralMatrix(int rows, int cols, int matrix[][4]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}
// find three elements whose sum is equal to zero
void findTriplets(int arr[], int n){
    bool found = false;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    found = true;
                }
            }
        }
    }
    if (found == false) cout << " not exist " << endl;
}
void findTriplets(int *arr, int n) {
    bool found = false;
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (arr[i] + arr[l] + arr[r] == 0) {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                l++; r--; found = true;
            }
            else if (x + arr[l] + arr[r] < 0) l++;
            else r--;
        }
    }
}
void findTriplets(int *arr, int n) {
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        unordered_set <int> st;
        for (int j = i + 1; j < n; j++) {
            int x = -(arr[i] + arr[j]);
            if (st.find(x) != st.end()) {
                cout << x << " " << arr[i] << " " << arr[j] << endl;
                found = true;
            }
            else st.insert(arr[j]);
        }
    }
    if(!found) cout << "No Triplet found";
}
void Triple(int *arr, int n, int sum) {
    for(int i = 0; i < n - 2; i++) {
        unordered_set <int> st;
        int curr = sum - arr[i];
        for(int j = i + 1; j < n; j++) {
            int req = cur - arr[j];
            if(st.find(req) != st.end()) {
                cout << arr[i] << " " << arr[j] << " " << req << endl;
                return true;
            }
            st.insert(arr[j]);
        }
    }
    return false;
}
int maximum(int a, int b, int c) {
    return max(max(a, b), c);
}
int minimum(int a, int b, int c) {
   return min(min(a, b), c);
}
void TripletDiff(int *a, int *b, int *c, int n) {
    sort(a, a + n); sort(b, b + n), sort(c, c + n);
    int mini, maxi, mid, i = 0, j = 0, k = 0;
    int diff = INT_MAX;
    while (i < n && j < n && k < n){
        int sum = a[i] + b[j] + c[k];
        int mx = maximum(a[i], b[j], c[k]);
        int mn = minimum(a[i], b[j], c[k]);
        if (mx == a[i]) i++;
        else if (mn == b[j]) j++;
        else k++;
        if (diff > (mx - mn)){
            diff = mx - mn;
            maxi = mx;
            mid = sum - (mx + mn);
            mini = mn;
        }
    }
    cout << maxi << " " << mini << " " << mid << endl;
}

