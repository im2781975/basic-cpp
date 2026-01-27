#include<bits/stdc++.h>
using namespace std;
vector <int> distinct(vector <int> vec) {
    vector <int> unq, dup;
    for(int i = 0; i < vec.size(); i++) {
        if(find(unq.begin(), unq.end(), vec[i]) == unq.end()) unq.push_back(vec[i]);
        else dup.push_back(vec[i]);
    }
    return unq;
}
void distinct(int *arr, int n) {
    for(int i = 0; i < n; i++){
        int j
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j]) break;
        }
        if(i == j) cout << arr[i] << " ;"
    }/*
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        while(i < n - 1 && arr[i] == arr[i + 1]) i++;
        cout << arr[i] << " ";
    } *//*
    unordered_set <int> st;
    for(int i = 0; i < n; i++) {
        if(!st.count(arr[i])) {
            st.insert(arr[i]); cout << arr[i] << " ";
        }
    } */
}
void printdup(int *arr, int n) {
    unordered_set <int> unq, dup;
    for(int i = 0; i < n; ++i) {
        if(unq.find(arr[i]) == unq.end()) unq.insert(arr[i]);
        else dup.insert(arr[i]);
    }
    unordered_set <int> ::iterator it;
    for(it = dup.begin(); it != dup.end(); ++it) cout << *it << " ";
    cout << endl;
}
void firstdup(vector <int> vec) {
    map <int, int> mp;
    for(int i = 0; i < vec.size(); ++i) {
        if(mp.find(vec[i]) != mp.end()) {
            cout << vec[i] << " " << mp[vec[i]] << endl;
            break;
        }
        mp[vec[i]] = i;
    }
}
int dig(int n) {
    int cnt = 0;
    while(n != 0) { n /= 10; cnt++; }
    return cnt;
}
void minopr(vector <int> vec, vector <int> tor) {
    int n = vec.size();
    priority_queue <int> x, y;
    for(int i = 0; i < n; i++) x.push(vec[i]);
    for(int i = 0; i < n; i++) y.push(tor[i]);
    int res = 0;
    while(x.size() && y.size()) {
        int a = x.top(), b = y.top();
        if (a == b) { x.pop(); y.pop(); continue; }
        ++res;
        if(a > b) { x.pop(); x.push(dig(a)); }
        else { y.pop(); y.push(dig(b)); }
    }
    cout << res;
}
// Find the smallest signal range needed so every house is within range of at least one transmitter placed on a house.
void smallrange(vector <int> vec, int n) {
    bool flag = true; int tmp = INT_MAX;
    for(int i = n; i < n; ++i) {
        if(arr[i] < arr[i - 1]) {
            flag = false; break;
        }
    }
    if(flag) {
        for(int i = 1; i < n; ++i)
            tmp = min(tmp, vec[i] - vec[i - 1])
        cout << (tmp / 2) + 1;
    }
    cout << 0;
}
void pattern(vector <int> vec, int n) {
    int l, r; cin >> l >> r;
    if(l >= 1 && r <= vec.size() && l <= r)
        vec.erase(vec.begin() + l - 1, vec.begin() + r);
    int sum = 0;
    while(n > 0) {
        sum += n; vec.push_back(sum); n /= 2;
    }
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}
void cntcoin(vector <int> vec, int n, int x) {
    vector <int> cnt(x + 1, INT_MAX);
    cnt[0] = 0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < coin.size(); j++) {
            if(i - coin[j] >= 0) cnt[i] = min(cnt[i], cnt[i - cnt[j]] + 1);
        }
    }
    cout << cnt[x];
}
// find equilibrium index of an array
int equilibrium(int *arr, int n) {
    int left = 0, right = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; j++) left += arr[j];
        for(int j = i; j < n; j++) right += arr[j];
        if(left == right) return i;
    }
    return -1;
}
int equilibrium(int *arr, int n) {
    int sum = 0, left = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    for(int i = 0; i < n; i++) {
        sum -= arr[i];
        if(left == sum) return i;
        left += arr[i];
    }
    return -1;
}
int equilibrium(int *arr, int n) {
    vector <int> head(n), rev(n);
    for(int i = 1; i < n; i++) head[i] = head[i - 1] + arr[i];
    rev[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) rev[i] = rev[i + 1] + arr[i];
    for(int i = 0; i < n; i++) {
        int left = (i == 0 ? 0 : head[i - 1]);
        int right = (i == n - 1 ? 1 : rev[i + 1]);
        if(left == right) return i;
    }
    return -1;
}
int equilibrium(vector <int> vec) {
    int left = 0, right = 0, pivot = 0;
    for(int i = 1; i < vec.size(); i++) right += vec[i];
    while(pivot < vec.size() - 1 && right != left) {
        pivot++; right -= vec[pivot];
        left += vec[pivot];
    }
    return (left == right) ? pivot : -1;
}
//find maxdiff between freq of any two element such that element with greater freq is also greater in value.
int maxdiff(int *arr, int n) {
    unordered_map <int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(freq[arr[i]] > freq[arr[j]] && arr[i] > arr[j])
                res = max(res, freq[arr[i]] - freq[arr[j]])
            else if(freq[arr[i]] < freq[arr[j]] && arr[i] < arr[j])
                res = max(res, freq[arr[j]] - freq[arr[i]])
        }
    }
    return res;
}
int maxdiff(int *arr, int n) {
    unordered_map <int, int> freq;
    int dist[n], j = 0;
    for(int i = 0; i < n; i++) {
        if(freq.find(arr[i]) == freq.end()) dist[j++] = arr[i];
        freq[arr[i]]++;
    }
    sort(dist, dist + j);
    int mini = n + 1, res = 0;
    for(int i = 0; i < j; i++) {
        int cur = freq[dist[i]];
        res = max(res, cur - mini);
        mini = min(cur, mini);
    }
    return res;
}
// Returns min diff between max & min values of distribution n choco in m students
int minDiff(int *arr, int n, int m) {
    if(m == 0 || n == 0) return 0;
    sort(arr, arr + n);
    if(n < m) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        mini = min(mini, diff);
        maxi = max(maxi, diff);
    }
    cout << mini << " " << maxi << endl;
}
//find minimum diff of max & min of K number. 
int mindiff(int *arr, int n, int m) {
    int res = INT_MAX;
    sort(arr, arr + n);
    for(int i = 0; i <= n - m; i++) 
        res = min(res, arr[i + k - 1] - arr[i]);
    return res;
}
int save[100];
int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(save[n] != 0) return save[n];
    int x = fib(n - 1);
    int y = fib(n - 2);
    save[n] = x + y;
    return x + y;
}
int fibsearch(int *arr, int n, int x) {
    int fib1 = 0, fib2 = 1; fib3 = fib1 + fib2;
    while(fib3 < n) {
        fib1 = fib2; fib2 = fib3;
        fib3 = fib1 + fib2;
    }
    int j = -1;
    while(fib3 > 1) {
        int i = min(j + fib2, n - 1);
        if(arr[i] < x) {
            fib3 = fib2; fib2 = fib1; 
            fib1 = fib3 - fib1;
            j = i;
        }
        else if(arr[i] > x) {
            fib3 = fib1; fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }
        else return i;
    }
    if (fib2 == 1 && arr[j + 1] == x) return j + 1;
    else return -1;
}
