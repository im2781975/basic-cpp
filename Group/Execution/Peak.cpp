#include<bits/stdc++.h>
using namespace std;
int peak(int *arr, int n) {
    int l = 0, r = n - 1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) break;
        if(mid > 0 && arr[mid - 1] > arr[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return mid;
}
int peak(int *arr, int n) {
    if(n == 1 || arr[0] >= arr[1]) return 0;
    if(arr[n - 1] >= arr[n - 2]) return n - 1;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1]) return i;
    }
}
int utile(int *arr, int low, int high, int n) {
    int mid = low + (high - low) >> 1;
    if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) return mid;
    if(mid > 0 && arr[mid - 1] > arr[mid]) return utile(arr, low, mid - 1, n);
    else return utile(arr, mid + 1, high, n);
}
int peak(int *arr, int n) {
    return utile(arr, 0, n - 1, n);
}
int insert(int *arr, int n, int key, int cap) {
    if(n >= cap) return n;
    int i = n - 1;
    for(;(i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];
    arr[i + 1] = key;
    return n + 1;
}
void insert(int *arr, int n, int key, int pos) {
    for(int i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
    arr[pos] = key;
}
int invcnt(int *arr, int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}
void leader(int *arr, int n) {
    int maxi = arr[n - 1]; cout << maxi << " ";
    for(int i = n - 2; i >= 0; i--) {
        if(maxi < arr[i]) {
            maxi = arr[i]; cout << maxi << " ";
        }
    } /*
    stack <int> st; st.push(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] >= st.top()) st.push(arr[i]);
    }
    while(!st.empty()) {
        cout << st.top() << " "; st.pop();
    }
    for(int i = 0; i < n; i++) {
        int j;
        for(j = i + 1; j < n; j++) {
            if(arr[i] <= arr[j]) break;
            if(j == n) cout << arr[i] << " ";
        }
    } */
}
// positive numbers at even idx and negative numbers at odd idx
void rearrange(int *arr, int n) {
    int i = -1;
    for(int j = 0; j < n; j++) {
        if(arr[j] < 0) {
            i++; swap(arr[i], arr[j]);
        }
    }
    int pos = i + 1, neg = 0;
    while(pos < n && neg < pos && arr[neg] < pos) {
        swap(arr[neg], arr[pos]);
        pos++; neg += 2;
    }
}
// computes all possible subarray sums & returns the k-th largest one
void nthsum(vector <int> arr, int k) {
    int n = arr.size();
    vector <int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i - 1];
    vector <int> res(n + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            res.push_back(prefix[j] - prefix[i]);
        }
    }
    sort(res.begin(), res.end(), greater <int> ());
    return res[k - 1];
}
int nthsum(vector <int> arr, int n, int k) {
    vector <int> res;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            res.push_back(sum);
        }
    }
    sort(res.begin(), res.end(), greater <int> ());
    return res[k - 1];
}
int nthsum(int *arr, int n, int k) {
    int prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i - 1];
    priority_queue <int, vector <int>, greater <int>> pq;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int sum = prefix[j] - prefix[i - 1];
            if(pq.size() < k) pq.push(sum);
            else if(sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}
bool issorted(int *arr, int n) {
    if(n == 0 || n == 1) return true;
    return arr[n - 1] >= arr[n - 2] && issorted(arr, n - 1);
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i]) return false;
    }
    return true;
}
void rotateleft(int *arr, int n, int k) {
    int md = k % n;
    for(int i = 0; i < n; i++)
        cout << arr[(md + i) % n] << " ";
    cout << endl;
    sort(arr, arr + (k % n), arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void rotateleft(int *arr, int n, int k) {
    /* int tmp[n], j = 0;
    for(int i = k; i < n; i++) tmp[j++] = arr[i];
    for(int i = 0; i < k; i++) tmp[j++] = arr[i];
    for(int i = 0; i < n; i++) arr[i] = tmp[j]; */
    k %= n; int gcd = __gcd(k, n);
    for(int i = 0; i < gcd; i++) {
        int tmp = arr[i], j = i;
        while(1) {
            int x = (j + k) % n;
            if(x == i) break // cycle done
            arr[j] = arr[x]; j = x;
        }
        arr[j] = tmp;
    }
}
void revarr(int *arr, int l, int r) {
    if(l >= r) return;
    int tmp = arr[l]; 
    arr[l] = arr[r];
    arr[r] = tmp;
    revarr(arr, l + 1, r - 1);
}
void rotateleft(int *arr, int n, int k) {
    if(k == 0) return; 
    k %= n;
    revarr(arr, 0, k - 1);
    revarr(arr, k, n - 1);
    revarr(arr, 0, n - 1);
}
void rotateleft(vector <int> arr, int k) {
    int n = arr.size(); k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
int findMax(int arr[], int n) {
    if(n == 1) return arr[0];
    else {
        int maxInRest = findMax(arr, size - 1);
        return maxInRest > arr[size - 1] ? maxInRest : arr[size - 1];
    }
}
int getavg(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    float avg = sum / n;
    return avg;
}
// Odd occuring element
int findOdd(int arr[], int n){
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
void array(int *arr, int n) {
    if (n == 0) return;
    array(arr, n - 1);
    cout << arr[n - 1] << " ";
}
// For each query, print the sum of elements between indices l and r.
void sumrange(vector <int> vec, int n) {
    vector <int> pref(n + 1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + vec[i];
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }
}
//how much coin need for complete n
vector <int> coins {3, 4, 5};
int coin_change(int n) {
    int mini = *min_element(coins.begin(), coins.end());
    if(n < mini) return 0;
    int ans = 10000;
    for(int i = 0; i < coins.size() -1 ; i++)
        ans = min(ans, 1 + coin_change(n - coins[i]));
    return ans;
}
using namespace std;
void func(int n) {
    if (n == 1) cout << "One";
    else if (n == 2) cout << "Two";
    else if (n == 3) cout << "Three";
    else if (n == 4) cout << "Four";
    else if (n == 5) cout << "Five";
    else if (n == 6) cout << "Six";
    else if (n == 7) cout << "Seven";
    else if (n == 8) cout << "Eight";
    else cout << "Nine";
}
void tion(int n) {
    if (n == 1) cout << "Ten";
    else if (n == 2) cout << "Twenty";
    else if (n == 3) cout << "Thirty";
    else if (n == 4) cout << "Forty";
    else if (n == 5) cout << "Fifty";
    else if (n == 6) cout << "Sixty";
    else if (n == 7) cout << "Seventy";
    else if (n == 8) cout << "Eighty";
    else cout << "Nine";
}
int main() {
    vector <int> vec;
    int n; cin >> n;
    while(n != 0) {
        int x = n % 10; n /= 10;
        vec.push_back(x);
    }
    for(int i = vec.size() - 1; i >= 0; i--) {
        if(vec[i] == 0 && i == 0) cout << "zero";
        else if(i == 0) func(vec[i]);
        else if(i == 1) tion(vec[i]);
    }
}
// sorting basis of a column & size
using namespace std;
bool sortcol(const vector <int> &a, const vector <int> &b) {
    return a[1] < b[1];
}
bool sizecom(const vector <int> &a, const vector <int> &b) {
    return a.size() < b.size();
}
int main() {
    vector <vector <int>> vec {{ 3, 5, 1 },{ 4, 8, 6 },{ 7, 2, 9}};
    sort(vec[0].rbegin(), vec[0].rend());
    //sort(vect[0].begin(), vect[0].end());
    sort(vec.begin(), vec.end(), sizecom); // sizecol
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
