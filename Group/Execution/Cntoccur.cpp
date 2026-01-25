#include<bits/stdc++.h>
using namespace std; 
// find k numbers with most occurrences in the given array
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
    return;
} 
bool cmp(pair <int, int> x, pair <int, int> y) {
    if(x.second == y.second) return x.first > y.first;
    else return x.second > y.second;
}
void nfreq(int *arr, int n, int k) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    vector <pair <int, int>> freq(mp.begin(), mp.end());
    sort(freq.begin(), freq.end(), cmp);
    for(int i = 0; i < k; i++) cout << freq[i].first << " ";
    cout << endl;
}
vector <int> nfreq(vector <int> vec, int k) {
    unordered_map <int, int> mp;
    for(int i = 0; i < vec.size(); ++i) mp[vec[i]]++;
    vector <pair <int, int>> freq;
    for(auto it = mp.begin(); it != mp.end(); ++it)
        freq.push_back({it->second, it->first});
    // get top k elements
    nth_element(freq.begin(), freq.end() - k, freq.end());
    vector <int> res;
    for(int i = freq.size() - k; i < freq.size(); i++) res.push_back(freq[i].second);
    return res;
}
//count all possible triangles 
int cntTriangle(int *arr, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j]
                    && arr[k] + arr[j] > arr[i]) cnt++;
            }
        }
    }
    return cnt;
}
int cntTriangle(int *arr, int n){
    sort(arr, arr + n); int cnt = 0;
    for(int i = 0; i < n - 2; i++){
        int k = i + 2;
        for(int j = i; j < n; j++){
            while(k < n && arr[i] + arr[j] > arr[k]) k++;
            if(k > j) cnt += k - j + 1;
        }
    }
    return cnt;
}
int cntTriangle(vector <int> vec) {
    int n = vec.size(), cnt = 0;
    sort(vec.begin(), vec end());
    for(int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while(l < r) {
            if(arr[l] + arr[r] > arr[i]) {
                cnt += r - l; r--;
            }
            else l++;
        }
    }
    cout << cnt;
}
int findXOR(int *arr, int n) {
    int res = arr[0];
    for(int i = 1; i < n; ++i) res ^= arr[i];
    return res;
}
int occuronce(int *arr, int n) {
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt == 1) return arr[i];
    }
    return -1;
}
void occurance(int *arr, int n) {
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        if (it -> second == 1) cout << it -> first;
    }
}
int cntmatch(vector <int> vec, int l, int r, int trg) {
    int cnt = 0;
    int mid = l + (r - l) / 2;
    if(r - l < 2) {
        if(vec[l] == trg) cnt++;
        if(vec[r] == trg && l != r) cnt++;
        return cnt;
    }
    else if(vec[mid] == trg) 
        return cntmatch(vec, l, mid - 1, trg) + 1 + cntmatch(vec, mid + 1, r, trg);
    else if(vec[mid] < trg)
        return cntmatch(vec, mid + 1, r, trg);
    else return cntmatch(vec, l, mid - 1, trg);
}
int cntmatch(vector <int> vec, int l, int r, int trg) {
    if(l > r) return 0;
    int mid = l + (r - l) / 2;
    if(vec[mid] == trg) {
        int cnt = 1;
        cnt += cntmatch(vec, l, mid - 1, trg);
        cnt += cntmatch(vec, mid + 1, r, trg);
        return cnt;
    }
    else if(vec[mid] > trg) return cntmatch(vec, l, mid - 1, trg);
    return cntmatch(vec, mid + 1, r, trg);
}
int opr(int *arr, int n) {
    unordered_map <int, int> mp;
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        if(mp[arr[i]] == 0) {
            x += arr[i]; mp[arr[i]]++;
        }
        y += arr[i];
    }
    return (2 * x - y);
}
int XOR(int *arr, int n) {
    int low = 0, high = n - 2, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == arr[mid ^ 1]) 
            low = mid + 1;
        //XOR (^ 1) is used to find the adjacent element.
        else high = mid - 1; 
    }
    return arr[low];
} 
//find number of rotations in a sorted and rotated array for being sorted
int cntcycle(int *arr, int n) {
    /* int min = arr[0], idx = 0;
    for(int i = 1; i < n; ++i) {
        if(min > arr[i]) {
            min = arr[i]; idx = i;
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
    int mid = low + (high - low) / 2;
    if(mid < high && arr[mid + 1] < arr[mid]) return (mid + 1);
    if(mid > low && arr[mid] < arr[mid - 1]) return mid;
    if(arr[high] > arr[mid]) return cntcycle(arr, low, mid - 1);
    else return cntcycle(arr, mid + 1, high);
}
int cntcycle(int *arr, int n) {
    int low = 0, high = n - 1;
    if(arr[low] <= arr[high]) return 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int prv = (mid - 1 + n) % n;
        int nxt = (mid + 1) % n;
        if(arr[mid] <= arr[prv] && arr[mid] <= arr[nxt]) return mid;
        else if(arr[mid] <= arr[high]) high = mid - 1;
        else if(arr[mid] >= arr[0]) low = mid + 1;
    }
    return 0;
}
int findpivot(int *arr, int n) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid < high && arr[mid] > arr[mid + 1]) return mid;
        if(mid > low && arr[mid] < arr[mid - 1]) return (mid - 1);
        if(arr[low] > arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int cntcyle(int *arr, int n) {
    int piv = findpivot(arr, n); return piv + 1;
}
int cntsubset(int *arr, int n) {
    unordered_set <int> st; int cnt = 0;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    for(int i = 0; i < n; ++i) {
        if(st.find(arr[i] - 1) == st.end()) {
            int j = arr[i];
            while(st.find(j) != st.end()) j++;
            cnt++;
        }
    }
    return cnt;
}
// find number of subset containing consecutive numbers
int cntsubset(int *arr, int n) {
    sort(arr, arr + n); int cnt = 1;
    for(int i = 0; i < n - 1; i++) {
        if((arr[i] + 1) != arr[i + 1]) cnt++;
    }
    return cnt;
}
