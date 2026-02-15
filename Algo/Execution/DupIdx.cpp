#include<bits/stdc++.h>
using namespace std;
int removesequent(vector <string> vec) {
    stack < string> st;
    for(int i = 0; i < vec.size(); i++) {
        if(st.empty()) st.push((vec[i]));
        else {
            string str = st.top();
            if(str.compare(vec[i]) == 0) st.pop();
            else st.push(vec[i]);
        }
    }
    return st.size();
}
int removesequent(vector <string> vec) {
    int idx = 0;
    for(int i = 0; i < vec.size(); ++i) {
        if(idx == 0 || vec[idx - 1] != vec[i]) vec[idx++] = vec[i];
    }
    vec.resize(idx);
    return idx;
}
// delete middle of a stack
void deleteMid(stack <char> st) {
    int n = st.size(), cnt = 0;
    stack <char> tmp;
    while(cnt < n / 2) {
        char ch = st.top(); st.pop();
        tmp.push(ch); cnt++;
    }
    st.pop();
    while(!tmp.empty()) {
        st.push(tmp.top()); tmp.pop();
    }
}
void deleteMid(stack <char> st, int k = 0) {
    if(k == st.size() / 2) {
        st.pop(); return;
    }
    char ch = st.top(); st.pop();
    deleteMid(st, k + 1); st.push(ch);
}
void deleteMid(stack <char> st) {
    vector <char> vec;
    while(!st.empty()) {
        vec.push_back(st.top()); st.pop();
    }
    int mid = vec.size() / 2;
    for(int i = 0; i < vec.size(); i++) {
        if(i != mid) st.push(vec[i]);
    }
}
int linearsearch(int *arr, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) return i;
    }
    return -1;
}
// Finds position of key in sorted array where duplicates exist
int Bsearch(int *arr, int l, int r, int x) {
    if(r >= l) {
        int mid = l + (r - l) >> 1;
        if(arr[mid] == x) return mid;
        if(mid > l && arr[mid - 1] == x) return (mid - 1);
        if (mid < r && arr[mid + 1] == x)
            return (mid + 1);
        if(arr[mid] > x) return Bsearch(arr, l, mid - 2, x);
        return Bsearch(arr, mid + 2, r, x);
    }
    return -1;
}
int findpos(int *arr, int key) {
    int l = 0, h = 1;
    int val = arr[0];
    if(val < key) {
        l = h; h *= 2; val = arr[h];
    }
    return Bsearch(arr, l, h, key);
}
int findPosition(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (mid > low && arr[mid - 1] == key) return mid - 1;
        if (mid < high && arr[mid + 1] == key) return mid + 1;
        if (arr[mid] > key) high = mid - 2;
        else low = mid + 2;
    }
    return -1;
}
void printMissing(int *arr, int n) {
    unordered_set <int> st;
    for(int i = 0; i < n; i++) {
        if(st.count(arr[i])) {
            cout << arr[i] << endl; break;
        }
        st.insert(arr[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(!st.count(i)) {
            cout << i << endl; break;
        }
    }
}
void printMissing(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int idx = abs(arr[i]) - 1;
        if(arr[idx] > 0) arr[idx] = -arr[idx];
        else {
            cout << abs(arr[i]) << endl;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            cout << i + 1 << endl; break;
        }
    }
}
void printMissing(int *arr, int n) {
    bool vis[n] = {};
    int dup = -1;
    for(int i = 0; i < n; i++) {
        int idx = arr[i] - 1;
        if(vis[idx]) {
            dup = arr[i]; break;
        }
        vis[idx] = true;
    }
    int Missing = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            miss = i + 1; break;
        }
    }
    cout << dup << " " << miss << endl;
}
void findMissing(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        if(abs(arr[i]) - 1 == n) continue;
        int idx = abs(arr[i]) - 1;
        arr[idx] *= -1;
    }
    int res = n + 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) res = i + 1;
    }
    cout << res;
}
int findMissing(int *arr, int n) {
    int i = 0;
    while(i < n) {
        int idx = arr[i] - 1;
        if(arr[i] < n && arr[i] != arr[idx])
            swap(arr[i], arr[idx]);
        else i++;
    }
    for(int i = 0; i < n; i++) {
        if(i != arr[i] - 1) return i + 1;
    }
    return n;
}
void findMissing(int arr[], int n) {
    int tmp[n + 1];
    for(int i = 0; i <= n; i++) tmp[i] == 0;
    for(int i = 0; i < n; i++) tmp[arr[i] - 1] = 1;
    int res;
    for(int i = 0; i <= n; i++) {
        if(tmp[i] == 0) res = i + 1;
    }
    cout << res;
}
int getMissingNo(int a[], int n) {
    int N = n + 1;
    int total = (N) * (N + 1) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
int Missing(int a[], int n){
    int res = 1;
    for(int i = 2; i < n + 1; i++) {
        res += i; res -= a[i - 2];
    }
    return res;
}
int Missing(int a[], int n){
    int x1 = a[0], x2 = 1;
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
    return (x1 ^ x2);
}
// find duplicate parenthesis in a balanced expression
bool dupparenthesis(string str) {
    // string str = "(((a+(b))+(c+d)))";
    stack <char> st;
    for(char ch : str) {
        if(ch == ')') {
            char tp = st.top(); st.pop();
            int cnt = 0;
            while(tp != '(') {
                cnt++; 
                x = st.top(); st.pop();
            }
            if(cnt < 1) return 1;
        }
        else st.push(ch);
    }
    return false;
}
pair <int, int> findDupMissing(vector <int> vec) {
    int n = arr.size(), xor_all = 0;
    for(int i = 0; i < n; i++) 
        xor_all ^= arr[i] ^ (i + 1);
    int diffbit = xor_all & -xor_all;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] && diffbit) x ^= arr[i];
        else y ^= arr[i];
        if ((i + 1) & diffbit) x ^= (i + 1);
        else y ^= (i + 1);
    }
    // x = missing, y = dup
    return {x, y};
}
vector <int> repNum(vector <int> vec) {
    int n = vec.size();
    int sum_expected = n * (n + 1) >> 1;
    int sq_expected = n * (n + 1) * (2 * n + 1) / 6;
    int sum_actual = 0, sq_actual = 0;.
    for (int x : vec) {
        sum_actual += x;
        sq_actual += 1LL * x * x;
    }
    long long sum_diff = sum_expected - sum_actual;
    long long sq_diff = sq_expected - sq_actual;
    long long miss = (sum_diff + sq_diff / sum_diff) / 2;
    long long dup = miss - sum_diff;
    return {(int)dup, (int)miss};
}
void firstRepeating(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    vector<bool> vis(maxVal + 1, false);
    for (int i = 0; i < n; i++) {
        if (vis[arr[i]]) {
            cout << "First repeating: " << arr[i] << endl;
            return;
        }
        vis[arr[i]] = true;
    }
}
void firstRepeating(int arr[], int n) {
    int maxi = *max_element(arr, arr + n);
    int tmp[maxi] = {0};
    for(int i = 0; i < n; i++) tmp[arr[i]]++;
    int dup = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(tmp[arr[i]] > 1) {
            dup = arr[i]; break;
        }
    }
    if(dup != INT_MIN) cout << dup << endl;
}
void FirstRepeating(int arr[], int n) {
    int k = 0;
    int maxi = max(arr, arr + n);
    int a[maxi + 1] = {}, b[maxi + 1] = {};
    for (int i = 0; i < n; i++) {
        // Duplicate element found
        if (a[arr[i]]) {
            b[arr[i]] = 1;
            k = 1; continue;
        }
        else a[arr[i]] = i + 1;
    }
    if (k == 0)
        cout << "No repeating element found" << endl;
    else {
        int min = maxi + 1;
        for (int i = 0; i < maxi + 1; i++)
            if (a[i] && min > a[i] && b[i])
                min = a[i];
        cout << arr[min - 1];
    }
}
void firstrepeating(int *arr, int n) {
    int mini = -1;
    set <int> st;
    for(int i = n - 1; i >= 0; i--) {
        if(st.find(arr[i]) != st.end()) mini = i;
        else st.insert(arr[i]);
    }
    if(mini != -1) cout << arr[mini];
    else cout << "No repeating elements";
}
// find the index of first repeating element in an array
int firstRepeatingIdx(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return i;
        }
    }
    return -1;
}
