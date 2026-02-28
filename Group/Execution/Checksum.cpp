#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector <int> arr) {
    if(arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    vector <int> left = merge(vec);
    vector <int> right = merge(tor);
    vector <int> res;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) res.push_back(left[i++]);
        else res.push_back(right[j++]);
    }
    while(i < left.size()) res.push_back(left[i++]);
    while(j < right.size()) res.push_back(right[j++]);
    return res;
}
vector <int> merged(vector <int> vec, vector <int> tor) {
    vector <int> res;
    int len = vec.size() + tor.size();
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < len; i++) {
        if(idx1 == vec.size()) res.push_back(tor[idx2++]);
        else if(idx2 == tor.size()) res.push_back(vec[idx1++]);
        else if(vec[idx1] > tor[idx2]) res.push_back(tor[idx2++]);
        else res.push_back(vec[idx1++]);
    }
    return res;
}
vector <int> divide(vector <int> arr) {
    if(arr.size() <= 1) return arr;
    int len = arr.size();
    vector <int> x, y;
    for(int i = 0; i < len / 2; i++) x.push_back(arr[i]);
    for(int i = len / 2; i < len; i++) y.push_back(arr[i]);
    vector <int> vec = divide(x);
    vector <int> tor = divide(y);
    return merged(vec, tor);
}
//checks two numbers in the array which sums to trg
bool twin_point(vector <int> arr, int trg) {
    int idx1 = 0, idx2 = arr.size() - 1;
    while(idx1 < idx2) {
        if(arr[idx1] + arr[idx2] == trg) return true;
        else if(arr[idx1] + arr[idx2] > trg) idx2--;
        else idx1++;
    }
    return false;
}
vector <int> twin_sum(vector <int> arr, int trg) {
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == trg) return {l, r};
        else if(sum > trg) r--;
        else l++;
    }
    return {};
}
vector <int> RemoveDup(vector <int> arr) {
    vector <int> tor(arr.begin(), arr.end()); arr.clear();
    arr = divide(tor);
    vector <int> Dup;
    if(!arr.empty()) Dup.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1]) Dup.push_back(arr[i]);
    }
    return Dup;
}
bool Bsearch(vector <int> arr, int low, int high, int trg) {
    while(low <= high) {
        int mid = low + (high - low) >> 1;
        if(arr[mid] == trg) return true;
        else if(arr[mid] > trg) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
int pairsum(vector <int> vec, int trg) {
    vector <int> tor(vec.begin(), vec.end()); vec.clear();
    vec = merge(tor);
    int cnt = 0;
    for(int i = 0; i < vec.size(); i++) {
        int val = trg - vec[i];
        if(Bsearch(vec, i + 1, vec.size() - 1, val)) cnt++;
    }
    return cnt;
}
// counts the number of inversions in the array using Merge.
//number of inversions in an array is a measure of how far the array is from being sorted.
int cnt = 0;
int invcnt(vector <int> vec, vector <int> tor, vector <int> res) {
    int i = 0, j = 0, inv = 0;
    while(i < vec.size() && j < tor.size()) {
        if(vec[i] <= tor[j]) res.push_back(vec[i++])
        else {
            res.push_back(tor[j++]);
            inv += vec.size() - i;
        }
    }
    while(i < vec.size()) res.push_back(vec[i++])
    while(j < tor.size()) res.push_back(tor[j++])
    return inv;
}
int merg(vector <int> arr) {
    if(arr.size() <= 1) return 1;
    int mid = arr.size() / 2;
    vector <int> vec(arr.begin(), arr.begin() + mid);
    vector <int> tor(arr.begin() + mid, arr.end());
    merg(vec); merg(tor);
    cnt += invcnt(vec, tor, arr);
}
int cnt = 0; 
int merged(vector <int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l, inv = 0;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            inv += (n1 - i); 
        }
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
    return inv;
}
int invcnt(vector <int> arr, int l, int r) {
    // l = 0, r = arr.size() - 1;
    if(l >= r) return 0;
    int mid = l + (r - l) / 2; int inv = 0;
    inv += invcnt(arr, l, mid);
    inv += invcnt(arr, mid + 1, r);
    inv += marged(arr, l, mid, r);
    return inv;
} 
bool cmp(pair <int, int> x, pair <int, int> y) {
    if(x.first != y.first) return x.first > y.first;
    return x.second < y.second;
}
void reorder(int *arr, int *idx, int n) {
    vector <pair <int, int>> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i].first = arr[i];
        vec[i].second = idx[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; i++) arr[i] = vec[i].first;
}
void reorder(int *arr, int *idx, int n) {
    for(int i = 0; i < n; i++) {
        while(idx[i] != i) {
            int dig = idx[idx[i]];
            char ch = arr[idx[i]];
            idx[idx[i]] = idx[i];
            arr[idx[i]] = arr[i];
            idx[i] = dig;
            arr[i] = ch;
        }
    }
}
void reorder(int *arr, int *idx, int n) {
    int tmp[n];
    for(int i = 0; i < n; i++) tmp[idx[i]] = arr[i];
    for(int i = 0; i < n; i++) {
        arr[i] = tmp[i]; idx[i] = i;
    }
}
// redundant parentheses from algebraic expressions by tracking sign propagation through nested parentheses using a stack.
string simplify(string str) {
    int len = str.length();
    string res = ""; res.reserve(len);
    int i = 0;
    stack <int> st; st.push(0);
    while(i < len) {
        if(str[i] == '(') {
            if(i > 0 && str[i - 1] == '-')
                st.push(1 - st.top());
            else st.push(st.top());
            i++; continue;
        }
        else if(str[i] == ')') {
            st.pop(); i++;
            continue;
        }
        else if(str[i] == '+' || str[i] == '-') {
            i++; continue;
        }
        res += str[i++];
    }
    return res;
}
//Given Array of size n and a number k, find all elements that appear more than n/k times
void moreThanNdKSimple(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto& p : freq) {
        if (p.second > n/k) {
            cout << "Number: " << p.first 
                 << " Count: " << p.second << endl;
        }
    }
}
void moreThanNdK(int arr[], int n, int k) {
    if (k <= 1) return;
    vector<int> candidates(k - 1, -1);  
    vector<int> counts(k - 1, 0);
    for (int i = 0; i < n; i++) {
        bool found = false;
        
        for (int j = 0; j < k-1; j++) {
            if (candidates[j] == arr[i]) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            bool placed = false;
            for (int j = 0; j < k-1; j++) {
                if (counts[j] == 0) {
                    candidates[j] = arr[i];
                    counts[j] = 1;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                for (int j = 0; j < k-1; j++) {
                    counts[j]--;
                }
            }
        }
    }
    for (int i = 0; i < k-1; i++) {
        if (candidates[i] == -1) continue;
        
        int actualCount = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == candidates[i]) actualCount++;
        }
        
        if (actualCount > n/k) {
            cout << "Number: " << candidates[i] 
                 << " Count: " << actualCount << endl;
        }
    }
}
// Maximum Length of Valid (Balanced) Bracket Subsequence in a Range
void buildBalancedArrays(int open[], int close[], string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                open[st.top()] = 1;
                close[i] = 1; 
                st.pop();
            }
        }
    }
    for (int i = 1; i < s.size(); i++) {
        open[i] += open[i-1];
        close[i] += close[i-1];
    }
}
int maxBalancedLength(int open[], int close[], int L, int R) {
    /*string s = "())(())(())(";
    int n = s.size();
    vector<int> open(n), close(n);
    buildBalancedArrays(open.data(), close.data(), s);
    
    cout << "Max balanced in [5,11]: " << maxBalancedLength(open.data(), close.data(), 5, 11) << endl; */
    int balanced = close[R] - close[L-1];
    if (open[L - 1] == open[L]) {
        return balanced * 2;
    }
    return (balanced + 1) * 2;
}
