#include<bits/stdc++.h>
using namespace std; /*
vector <int> distinct(vector <int> vec) {
    vector <int> unq, dup;
    for(int i = 0; i < vec.size(); i++) {
        if(find(unq.begin(), unq.end(), vec[i]) == unq.end()) unq.push_back(vec[i]);
        else dup.push_back(vec[i]);
    }
    return unq;
} */
void distinct(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int j;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) break;
        }
        if(i == j) cout << arr[i] << " ";
    } /*
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        while(i < n - 1 && arr[i] == arr[i + 1]) i++;
        cout << arr[i] << " ";
    }
    unordered_set <int> st;
    for(int i = 0; i < n; i++) {
        if(!st.count(arr[i])) {
            st.insert(arr[i]); cout << arr[i] << " ";
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
void firstdup(vector <int> arr) {
    map <int, int> mp;
    for(int i = 0; i < arr.size(); ++i) {
        if(mp.find(arr[i]) != mp.end()) {
            cout << arr[i] << " " << mp[arr[i]] << endl; break;
        }
        mp[arr[i]] = i;
    }
}
int dig(int n) {
    int cnt = 0;
    while(n != 0) {
        n /= 10; cnt++;
    }
    return cnt;
}
int func(vector <int> vec, vector <int> tor) {
    priority_queue <int> x, y;
    for(int i = 0; i < vec.size(); i++) x.push(vec[i]);
    for(int i = 0; i < tor.size(); i++) y.push(tor[i]);
    int res = 0;
    while(x.size() && y.size()) {
        int a = x.top(), b = y.top();
        if(a == b) {
            x.pop(); y.pop(); continue;
        }
        ++res;
        if(a > b) {
            x.pop(); x.push(dig(a));
        }
        else {
            y.pop(); y.push(dig(b));
        }
    }
    cout << res;
}
// Find the smallest signal range needed so every house is within range of at least one transmitter placed on a house
void smallrange(vector <int> arr, int n) {
    bool flag = true; int tmp = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            flag = false; break;
        }
    }
    if(flag) {
        for(int i = 1; i < n; ++i) 
            tmp = min(tmp, vec[i] - vec[i - 1]);
        cout << (tmp / 2) + 1;
    }
    cout << 0;
}
void pattern(vector <int> vec, int n) {
    int l, r; cin >> l >> r;
    if(l >= 1 && r <= vec.size() && l <= r)
        vec.erase(vec.begin() + l - 1, vec.begin() + r);
    int res = 0;
    while(n > 0) {
        sum += n; vec.push_back(sum); n /= 2;
    }
    for(int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
}
void cntcoin(vector <int> coin, int n, int amt) {
    vector <int> cnt(amt + 1, 0); cnt[0] = 0;
    for(int i = 0; i <= amt; i++) {
        for(int j = 0; j <= n; j++) {
            if(i - coin[j] >= 0) 
                cnt[i] = min(cnt[i], cnt[i - coin[j]] + 1);
        }
    }
    cout << cnt[amt];
}
int equilibrium(int *arr, int n) {
    int left = 0, total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    for(int i = 0; i < n; i++) {
        total -= arr[i];
        if(left == total) return i;
        left += arr[i];
    }
    return -1;
}
int equilibrium(int *arr, int n) {
    vector <int> suffix(n + 1);
    suffix[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + arr[i];
    for(int i = 0; i < n; i++) {
        int prefix = 0;
        for(int j = 0; j < i; j++) prefix += arr[j];
        int right = suffix[i + 1];
        if(prefix == right) return i;
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
int equilibrium(vector <int> arr) {
    int left = 0, right = 0, piv = 0;
    for(int i = 1; i < n; i++) right += arr[i];
    while(piv < arr.size() - 1 && right != left) {
        piv++; left += arr[piv - 1];
        right += arr[piv];
    }
    return (left == right) ? piv : -1;
}
void equilibrium(int *arr, int n) {
	int prefix[n], suffix[n];
    int res = INT_MIN; prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];
    suffix[n - 1] = arr[n - 1];
    if(suffix[n - 1] == prefix[n - 1]) res = max(res, prefix[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + arr[i];
        if(suffix[i] == prefix[i]) res = max(res, prefix[i]);
    }
    return res;
}
int maxsum(int *arr, int n) {
    int sum = accumulate(arr, arr + n, 0);
    int prefix = 0, res = INT_MIN;
    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        if(prefix == sum) res = max(res, prefix);
        sum -= arr[i];
    }
    return res;
}
//find maxdiff between freq of any two element such that element with greater freq is also greater in value.
int maxdiff(int *arr, int n) {
    unordered_map <int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    int res = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(freq[arr[i]] > freq[arr[j]] && arr[i] > arr[j])
                res = max(res, freq[arr[i]] - freq[arr[j]]);
            else if(freq[arr[j]] > freq[arr[i]] && arr[j] > arr[i])
                res = max(res, freq[arr[j]] - freq[arr[i]]);
        }
    }
    return res;
}
int maxdiff(int *arr, int n) {
    unordered_map <int, int> mp;
    int tmp[n], j = 0;
    for(int i = 0; i < n; i++) {
        if(freq.find(arr[i]) == freq.end()) tmp[j++] = arr[i];
        freq[arr[i]]++;
    }
    sort(tmp, tmp + j);
    int mini = n + 1, res = 0;
    for(int i = 0; i < n; ++i) {
        int cur = freq[tmp[i]];
        res = max(res, cur - mini);
        mini = min(mini, cur);
    }
    return res;
}
// Returns min diff between max & min values of distribution n choco in m students
int minDiff(int *arr, int n, int m) {
    if(m == 0 || n == 0) return 0;
    sort(arr, arr + n); if(n < m) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        mini = min(mini, diff); maxi = max(maxi, diff);
    }
    cout << mini << " " << maxi << endl;
}
//find minimum diff of max & min of m numbers
int mindiff(int *arr, int n, int m) {
    if(n < m) return INT_MAX;
    sort(arr, arr + n);
    int res = INT_MAX;
    for(int i = 0; i <= n - m; i++) {
        res = min(res, arr[i + m - 1] - arr[i]);
    }
    return res;
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
int save[100];
int fib(int n) {
    if(n == 0) return 0; if(n == 1) return 1;
    if(save[n] != 0) return save[n];
    int x = fib(n - 1); int y = fib(n - 2);
    save[n] = x + y;
    return x + y;
}
