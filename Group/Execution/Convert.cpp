#include<bits/stdc++.h>
using namespace std;
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
//find an element that can be used to operate on an arr & get equal
void equalize(int *arr, int n) {
    set <int> st;
    for(int i = 0; i < n; i++) st.insert(arr[i]);
    if(st.size() == 1) cout << "Yes";
    else if(st.size() == 2) {
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        cout << *y - *x << endl;
    }
    else if(st.size() == 3) {
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        auto z = st.begin(); st.erase(z);
        if((*z - *y) == (*y - *x)) cout << *z - *y << endl;
        else cout << "NO";
    }
    else cout << "NO" << endl;
}
void apply(int *arr, int n, int x, int y, int z) {
    for(int i = 0; i < n; i++) arr[i] = x * arr[i] * arr[i] + y * arr[i] + z;
    int idx, maxi = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i]; idx = i;
        }
    }
    int i = 0, j = n - 1, k = 0, res[n];
    while(i < idx && j > idx) {
        if(arr[i] < arr[j]) res[k++] = arr[i++];
        else res[k++] = arr[j--];
    }
    while(i < idx) res[k++] = arr[i++];
    while(j > idx) res[k++] = arr[j--];
    res[n - 1] = maxi;
    for(int i = 0; i < n; i++) arr[i] = res[i];
}
// minimum swap required to convert BT to BST
void inorder(int *arr, vector <int> &vec, int n, int idx) {
    /* inorder(arr, vec, n, 0);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; */
    if(idx >= n) return;
    inorder(arr, vec, n, 2 * idx + 1);
    vec.push_back(arr[idx]);
    inorder(arr, vec, n, 2 * idx + 2);
}
void postorder(int *arr, vector <int> &vec, int n, int idx) {
    /* postorder(arr, vec, n, 0);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; */
    if(idx >= n) return;
    postorder(arr, vec, n, 2 * idx + 1);
    postorder(arr, vec, n, 2 * idx + 2);
    vec.push_back(arr[idx]);
}
void preorder(int *arr, vector <int> &vec, int n, int idx) {
    /* preorder(arr, vec, n, 0);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; */
    if(idx >= n) return;
    vec.push_back(arr[idx]);
    preorder(arr, vec, n, 2 * idx + 1);
    preorder(arr, vec, n, 2 * idx + 2);
}
// find minimum swaps to sort an array
void minswap(vector <int> vec) {
    vector <pair <int, int>> tmp(vec.size());
    for(int i = 0; i < vec.size(); i++) {
        tmp[i].first = vec[i]; tmp[i].second = i;
    }
    int res = 0; sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); ++i) {
        if(i == tmp[i].second) continue;
        else {
            swap(tmp[i].first, tmp[tmp[i].second].first);
            swap(tmp[i].second, tmp[tmp[i].second].second);
        }
        if(i != tmp[i].second) --i;
        ++res;
    }
    for(int i = 0; i < tmp.size(); ++i)
        cout << tmp[i].first << " " << tmp[i].second << endl;
}
// converts original array values to their dense ranks (0-based positions in sorted order)
void convert(int *arr, int n) {
    int res[n]; copy(arr, arr + n, res);
    sort(res, res + n);
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[res[i]] = i;
    for(int i = 0; i < n; i++) arr[i] = mp[arr[i]];
}
void converted(int *arr, int n) {
    vector <pair <int, int>> vec;
    for(int i = 0; i < n; i++) vec.push_back(make_pair(arr[i], i));
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; ++i) arr[vec[i].second] = i; /*
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i].first << " " << vec[i].second << endl; */
}
void dreipeak(int *arr, int n) {
    int first, duo, drei;
    if(n < 3) return 0;
    first = duo = drei = INT_MIN;
    for(int i = 0; i < n; i++) {
        drei = duo; duo = first; first = arr[i];
    }
    else if(arr[i] > duo && arr[i] != first) {
        drei = duo; duo = arr[i];
    }
    else if(arr[i] > drei && arr[i] != duo && arr[i] != first) drei = arr[i];
    cout << first << " " << duo << " " << drei << endl;
}
void dreilargest(int *arr, int n) {
    sort(arr, arr + n); int check = 0, cnt = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt < 4) {
            if(check != arr[n - i]) {
                cout << arr[n - i] << " ";
                check = arr[n - i]; cnt++;
            }
        }
        else break;
    }
}
void dreilargest(int *arr, int n) {
    if(n < 3) return;
    vector<int> temp(arr, arr + n);
    sort(temp.rbegin(), temp.rend());
    cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
}
void dreilargest(int *arr, int n) {
    if(n < 3) return;
    partial_sort(arr, arr + 3, arr + n, greater <int> ());
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}
void zweitpeak(int *arr, int n) {
    sort(arr, arr + n);
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] != arr[i - 1]) cout << arr[i] << endl;
        return;
    }
}
void zweitpeak(vector <int> vec) {
    set <int> st(vec.begin(), vec.end());
    /* if(st.size() < 2) return;
    vector <int> tmp(vec.begin(), vec.end()); sort(tmp.begin(), tmp.end());
    cout << tmp[tmp.size() - 2] << endl; */
    vec.clear();
    for(auto it = st.begin(); it != st.end(); ++it) vec.push_back(*it);
    cout << vec[vec.size() - 2];
}
void zweitgiant(int *arr, int n) {
    int giant = 0, zweitgiant = -1;
    for(int i = 1; i < n; i++) {
        for(int i = 1; i < n; i++) {
            if(arr[i] > giant) giant = i;
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] != arr[giant]) {
                if(zweitgiant == -1) zweitgiant = i;
                else if(arr[zweitgiant] <    arr[i]) zweitgiant = i;
            }
        }
    }
    return zweitgiant;
}
void zweitgiant(int n, vector <int> vec) {
    map <int, int> mp;
    for(int i = 0; i < n; i++) mp[vec[i]]++;
    if(mp.size() == 1) return; // all values are same
    int sz = 1;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
        if(sz == 2) {
            cout << it -> first << endl;
            break;
        }
        sz++;
    }/* 
    int sz = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
        cout << it -> first << " ";
        if(++sz == 2) break;
    } */
}
void duogiant(vector <int> vec) {
    priority_queue <int> pq;
    for(int i = 0; i < vec.size(); ++i) pq.push(vec[i]);
    pq.pop(); cout << pq.top();
}
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
int findmax(int *arr, int low, int high) {
    int maxi = arr[low];
    for(int i = low + 1; i <= high; i++) {
        if(arr[i] > maxi) maxi = arr[i];
    } 
    return maxi;
}
int findmin(int *arr, int n) {
    int mini = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < mini) mini = arr[i];
    }
    return mini;
}
int findmin(vector <int> arr, int low, int high) {
    if(arr[low] <= arr[high]) return arr[low];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]) return mid;
        if(arr[mid] > arr[high]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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
