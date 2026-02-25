#include<bits/stdc++.h>
using namespace std;
//find the min and max values that can be calculated by summing exactly four of the five integers
void maxmin(int *arr, int n){
    int tmp[n], sum;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            sum += arr[j];
        }
        tmp[i] = sum;
    }
    int mn = tmp[0], mx = tmp[0];
    for(int i = 1; i < n; i++) {
        if(mn > tmp[i]) mn = tmp[i];
        if(mx < tmp[i]) mx = tmp[i];
    }
    cout << mn << " " << mx << endl;
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
void Bsearch(int *arr, int low, int high, int key) {
    if(high < low) return -1;
    int mid = low + (high - low) / 2;
    if(arr[mid] == key) return mid;
    else if(key > arr[mid]) return Bsearch(arr, mid + 1, high, key);
    else return Bsearch(arr, low, mid - 1, key);
}
int DeleteVal(int *arr, int n, int key) {
    pos = Bsearch(arr, 0, n - 1, key);
    if(pos == -1) return n;
    for(int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}
// find the Minimum length of Unsorted Subarray
void unsorted(int *arr, int n) {
    int l = 0, r = n - 1;
    while(l < n - 1 && arr[l] <= arr[l + 1]) l++;
    if(l == n - 1) return;
    while(r > 0 && arr[r] >= arr[r - 1]) r--;
    int submin = arr[l], submax = arr[l];
    for(int i = l + 1; i <= r; i++) {
        submin = min(submin, arr[i]);
        submax = max(submax, arr[i]);
    }
    for(int i = 0; i < l; i++) {
        if(arr[i] > submin) l = i; break;
    }
    for(int i = n - 1; i > r; i--) {
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
    }
    cout << cnt;
}
// Returns length of smallest subarray with sum greater than x
int subarrlen(int *arr, int n, int x) {
    int cur = 0, minlen = n + 1, l = 0, r = 0;
    while(cur <= x && r < n) cur += arr[r++];
    while(cur > n && l < n) {
        if(r - l < minlen) minlen = r - l;
        cur -= arr[l++];
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
    int n = arr.size(), res = INT_MIN;
    if(n == 0) return 1;
    vector <int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i - 1];
    for(int i = 1; i <= n; i++) {
        int val = x + sum[i - 1];
        auto find = lower_bound(arr.begin(), arr.end(), val);
        if(find != sum.end() && *find == val) {
            int len = find - (sum.begin() + i - 1);
            res = min(res, len);
        }
    }
    return res;
}
int subarrlen(vector <int> arr, int n) {
    unordered_map <int, int> mp;
    mp[0] = 0;
    int sum = 0, res = INT_MIN;
    for(int i = 1; i <= arr.size(); i++) {
        sum += arr[i - 1]; int trg = sum - x;
        if(mp.count(trg)) res = min(res, i - mp[trg]);
        if(mp.find(sum) == mp.end()) mp[sum] = i;
    }
    return res;
}
// finds and prints the first contiguous subarray equaling a target sum.
void subarrsum(int *arr, int n, int sum) {
    for(int i = 0; i < n; i++) {
        int cur = arr[i];
        if(cur == sum) {
            cout << i << " "; return;
        }
        for(int j = i + 1; j < n; j++) {
            cur += arr[j];
            if(cur == sum) {
                cout << i << " " << j << endl; return;
            }
        }
    }
    return;
}
int subarrsum(int *arr, int n, int sum) {
    int cur = 0, l = 0;
    for(int i = 0; i < n; i++) {
        cur += arr[i];
        while(cur > sum && l <= i) cur -= arr[l++];
        if(cur == sum) {
            cout << l << " " << i << endl;
            return;
        }
    }
    return 0;
}
vector <int> subarrsum(vector <int> arr, int sum) {
    unordered_map <int, int> mp; int cnt = 0;
    for(int i = 0; i < arr.size(); i++) {
        cur += arr[i];
        if(mp.count(cur - sum)) {
            return vector <int> (arr.begin() + mp[cur - sum] + 1, arr.begin() + i + 1);
        }
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
// find three elements whose sum is equal to zero
void findTriplets(int *arr, int n) {
    bool found = false;
    for(int i = 0; i < n - 2; i++) {
        for(j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    found = true; 
                }
            }
        }
    }
    if(!found) cout << "not exits" < endl;
}
void findTriplets(int *arr, int n) {
    sort(arr, arr + n);
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            if(arr[i] + arr[l] + arr[r] == 0) {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                l++; r--; found = true;
            }
            else if(arr[i] + arr[l] + arr[r] > 0) l++;
            else r--;
        }
    }
}
void findTriplets(int *arr, int n) {
    bool found = false;
    for(int i = 0; i < n - 1; i++) {
        unordered_set <int> st;
        for(int j = i + 1; j < n; j++) {
            int x = -(arr[i] + arr[j]);
            if(st.find(x) != st.end()) {
                cout << x << " " << arr[i] << " " << arr[j] << endl;
                found = true;
            }
            else st.insert(arr[i]);
        }
    }
    if(!found) cout << "No Triplet found";
}
bool Triplet(int *arr, int n, int sum) {
    for(int i = 0; i < n - 2; i++) {
        unordered_set <int> st;
        int cur = sum - arr[i];
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
void TripletDiff(int *a, int *b, int *c, int n) {
    sort(a, a + n); sort(b, b + n), sort(c, c + n);
    int mini, maxi, mid, i = 0, j = 0, k = 0;
    int diff = INT_MAX;
    while(i < n && j < n && k < n) {
        int sum = a[i] + b[i] + c[i];
        int mx = maximum(a[i], b[i], c[i]);
        int mn = minimum(a[i], b[i], c[i]);
        if(mx == a[i]) i++;
        else if(mn = b[j]) j++;
        else k++;
        if (diff > (mx - mn)){
            diff = mx - mn;
            maxi = mx;
            mid = sum - (mx + mn);
            mini = mn;
        }
    }
    cout << mini << " " << mid << " " << maxi << endl;
}



