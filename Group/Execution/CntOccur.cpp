#include<bits/stdc++.h>
using namespace std; 
// return the k most frequent elements.
void nfreq(int *arr, int n, int k) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    vector <vector <int>> freq(n + 1);
    for(auto val : mp)
        freq[val.second].push_back(val.first);
    int cnt = 0;
    for(int i = freq.size() - 1; i >= 0; i--) {
        if(freq[i].size() > 1) sort(freq[i].begin(), freq[i].end(), greater <int> ());
        for(auto val : freq[i]) {
            cnt++; cout << val << " ";
            if(cnt >= k) return;
        }
    } 
}
bool cmp(pair <int, int> x, pair <int, int> y) {
    if(x.second == y.second) return x.first > y.first;
    return x.second > y.second;
}
void freq(int *arr, int n, int k) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    vector <pair <int, int>> Hz(mp.begin(), mp.end());
    sort(Hz.begin(), Hz.end(), cmp);
    for(int i = 0; i < k; i++) cout << Hz[i].first << " ";
} 
vector <int> nfreq(vector <int> arr, int k) {
    unordered_map <int, int> mp;
    for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
    vector <pair <int, int>> freq;
    for(auto it = mp.begin(); it != mp.end(); ++it) freq.push_back({it -> second, it -> first});
    nth_element(freq.begin(), freq.end() - k, freq.end());
    vector <int> res;
    for(int i = freq.size() - k; i < freq.size(); i++) res.push_back(freq[i].second);
    return res;
}
int cntTriangle(int *arr, int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[k] + arr[j] > arr[i]) cnt++;
            }
        }
    }
    return cnt;
}
int cntTriangle(int *arr, int n) {
    sort(arr, arr + n); int cnt = 0;
    for(int i = 0; i < n - 2; i++) {
        int k = i + 2; 
        for(int j = i + 1; j < n - 1; j++) {
            while(k < n && arr[i] + arr[j] < arr[k]) k++;
            if(k > j) cnt += k - j + 1;
        }
    }
    return cnt;
}
int cntTriangle(vector <int> arr) {
    int n = arr.size(), cnt = 0;
    sort(arr.begin(), arr.end());
    for(int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while(l < r) {
            if(arr[l] + arr[r] > arr[i]) {
                cnt += r - l; r--;
            }
            else l++;
        }
    }
    return cnt;
} 
int xorTriangle(int *arr, int n) {
    sort(arr, arr + n);
    int res = 0;
    for(int i = 0; i < n - 2; i++) {
        int k = i + 2; 
        for(int j = i + 1; j < n - 1; j++) {
            while(k < n && arr[i] + arr[j] > arr[k]) k++;
            res ^= (k - j - 1);
        }
    }
    return res;
}
int occurOnce(int *arr, int n) {
    int res = arr[0];
    for(int i = 1; i < n; i++) res ^= arr[i];
    return res;
} 
int occurOnce(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt == 1) return arr[i];
    }
    return -1;
}
void occuranceOnce(int *arr, int n) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        if(it -> second == 1) cout << it -> first << endl;
    }
}
int cntMatch(vector <int> arr, int l, int r, int trg) {
    int cnt = 0, mid = l + (r - l) / 2;
    if(r - l < 2) {
        if(arr[l] == trg) cnt++;
        else if(arr[r] == trg && l != r) cnt++;
    }
    else if(arr[mid] == trg) return cntMatch(arr, l, mid - 1, trg) + 1 + cntMatch(arr, mid + 1, r, trg);
    else if(arr[mid] < trg) return cntMatch(arr, mid + 1, r, trg);
    else return cntMatch(arr, l, mid - 1, trg);
}
int cntMatch(vector <int> arr, int l, int r, int trg) {
    if(l > r) return 0;
    int mid = l + (r - l) / 2;
    if(arr[mid] == trg) {
        int cnt = 1;
        cnt += cntMatch(arr, l, mid - 1, trg);
        cnt += cntMatch(arr, mid + 1, r, trg);
        return cnt;
    }
    else if(arr[mid] > trg) return cntMatch(arr, l, mid - 1, trg);
    else return cntMatch(arr, mid + 1, r, trg);
}
int action(int *arr, int n) {
    unordered_map <int, int> mp;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(mp[arr[i]] == 0) {
            x += arr[i]; mp[arr[i]]++;
        }
        y += arr[i];
    }
    return (2 * x - y);
}
// finds the unique val in an array where all other elements
// appear exactly twice as consecutive pairs.
int findUnique(int *arr, int n) {
    int low = 0, high = n - 2;
    while(low <= right) {
        int mid = (low + high) / 2;
        if(arr[mid] == arr[mid ^ 1]) low = mid + 1;
        //XOR is used to find the adj val
        else high = mid - 1;
    }
    return arr[low];
}
int cntcycle(int *arr, int n) {
    /*int least = arr[0], idx = 0;
    for(int i = 1; i < n; i++) {
        if(least > arr[i]) {
            least = arr[i]; idx = i;
        }
    }
    return idx; */
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[i + 1] && i + 1 < n) return i + 1;
    }
    return -1;
}
int cntcycle(int *arr, int low, int high) {
    if(high < low) return 0;
    if(high == low) return low;
    int mid = low + (high - low) >> 1;
    if(mid < high && arr[mid + 1] < arr[mid]) return mid + 1;
    if(mid > low && arr[mid] < arr[mid - 1]) return mid;
    if(arr[low] <= arr[mid]) return cntcycle(arr, mid + 1, high);
    else return cntcycle(arr, low, mid - 1);
}
int cntcycle(int *arr, int n) {
    int low = 0, high = n - 1;
    if(arr[low] <= arr[high]) return 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int prv = (mid - 1 + n) % n;
        int nxt = (mid + 1) % n;
        if(arr[mid] <= arr[prv] && arr[mid] <= arr[prv]) return mid;
        if(arr[mid] > arr[high]) low = mid + 1;
        else high = mid - 1;
    }
}
// find number of subset containing consecutive numbers
int cntsubset(int *arr, int n) {
    unordered_set <int> st; int cnt = 0;
    for(int i = 0; i < n; ++i) st.insert(arr[i]);
    for(int i = 0; i < n; ++i) {
        if(st.find(arr[i] - 1) == st.end()) {
            int j = arr[i];
            while(st.find(j) != st.end()) j++;
            cnt++;
        }
    }
    cout << cnt;
}
int cntsubset(int *arr, int n) {
    sort(arr, arr + n); int cnt = 1;
    for(int i = 0; i < n - 1; i++) {
        if((arr[i] + 1) != arr[i + 1]) cnt++;
    }
    return cnt;
}
// demonstrate Difference Array
vector <int> Diff(vectir <int> vec) {
    int n = vec.size();
    vector <int> res(n + 1);
    res[0] = vec[0]; res[n] = vec[n];
    for(int i = 1; i < n; i++) res[i] = vec[i] - vec[i - 1];
    return res;
}
void update(vector <int> vec, int l, int r, int val) {
    vec[l] += val; vec[r + 1] -= val;
}
void print(vector <int> vec, vector <int> res) {
    for(int i = 0; i < vec.size(); i++) {
        if(i == 0) vec[i] = res[i];
        else vec[i] = res[i] + vec[i - 1];
        cout << vec[i] << " ";
    }
}
void primes(int n) {
    vector <int> prime;
    vector <bool> flag(n + 1);
    for(int i = 2; i <= n; i++) {
        if(flag[i] == false) {
            prime.push_back(i);
            for(int x = 2; i * x <= n; x++){
                flag[i * x] = true;
            }
        }
    }
    for(int i = 0; i < prime.size(); i++)
        cout << prime[i] << " ";
}
int recusive(int *arr, int n, int l, int r) {
    if(l == r) return arr[l];
    else {
        int mid = l + (r - l) / 2;
        return min(recursive(arr, n, l, mid - 1), recursive(arr, n, mid + 1, r));
    }
}
void cntzero(int *arr, int n, int q) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] != 0) cnt++;
    }
    while(q--) {
        int type, idx; cin >> type >> idx;
        if(type == 2) {
            if(arr[idx] == 0) arr[idx]++;
        }
        else if(type == 1) {
            if(arr[idx] > 0) {
                arr[idx]--;
                if(arr[idx] == 0) cnt--;
            }
        }
    }
    cout << cnt;
}
void pair() {
    vector <pair <int, int>> vpr;
    int arr[]{10, 20, 5, 40};
    int ray[]{30, 60, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        vec.push_back(make_pair(arr[i], ray[i]));
    for(int i = 0; i < n; i++)
        cout << vec[i].first << " " << vec[i].second << endl;
}
