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
int utile(int *arr, int low, int end, int n) {
    int mid = low + (end - low) >> 2;
    if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) return mid;
        if(mid > 0 && arr[mid - 1] > arr[mid]) return utile(arr, low, mid - 1, n);
        else return utile(arr, mid + 1, end, n);
}
int peak(int *arr, int n) { return utile(arr, 0, n - 1, n); }
int insert(int *arr, int n, int key, int cap) {
    if(n >= cap) return n; int i;
    for(i = n - 1; (i >= 0 && arr[i] > key); i--) arr[i + 1] = arr[i];
    arr[i + 1] = key;
    return (n + 1);
}
void insert(int *arr, int n, int key, int pos) {
    for(int i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
    arr[pos] = key;
}
int invcnt(int *arr, int n) {
    int cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] > arr[j]) ++cnt;
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
    } */ /*
    for(int i = 0; i < n; i++) {
        int j;
        for(j = i + 1; j < n; j++) {
            if(arr[i] <= arr[j]) break;
            if(j == n) cout << arr[i] << " ";
        }
    } */
}
// put positive numbers at even idx and negative numbers at odd idx
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
void nthsum(vector <int> vec, int k) {
    int n = vec.size();
    vector <int> res(n + 1); res[0] = 0;
    for(int i = 1; i <= n; i++) res[i] = res[i - 1] + vec[i - 1];
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) 
            res.push_back(res[j] - res[i]);
    }
    sort(res.begin(), res.end(), greater <int> ());
    return res[k - 1];
}
int nthsum(vector <int> vec, int n, int k) {
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
    int fix[n + 1];
    fix[0] = 0; fix[1] = arr[0];
    for(int i = 2; i <= n; i++) fix[i] = fix[i - 1] + arr[i - 1];
    pririty_queue <int, vector <int>, greater <int>> pq;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int x = fix[j] - fix[i - 1];
            if(pq.size() < k) pq.push(x);
            else {
                if(pq.top() < x) {
                    pq.pop(); pq.push(x);
                }
            }
        }
    }
    return pq.top();
}
bool Issorted(int *arr, int n) {
    if(n == 0 || n == 1) return true;
    //return arr[n - 1] >= arr[n - 2] && Issorted(arr, n - 1);
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}
void opr() {
    vector <int> vec = {1, 2, 3};
    vector <int> ::iterator it;
    for(it = vec.begin(); it != vec.end(); ++it) {
        if(it == vec.begin()) it = vec. insert(it, 5);
        if(it == vec.begin() + 1) it = vec. erase(it);
    }
    for (int i = 0; i < 10; i++) vec.push_back(i);
    vec.insert(vec.begin() + 1, 100);
    vec.erase(vec.begin() + 2);
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}
//left rotation of an array K number of times
void rotateleft(int *arr, int n, int k) {
    int md = k % n;
    for(int i = 0; i < n; i++)
        cout << arr[(md + i) % n] << " ";
    cout << endl; /*
    rotate(arr, arr + (k % n), arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl; */
}
void rotateleft(int *arr, int n, int k) {
    int tmp[n], j = 0;
    for(int i = k; i < n; i++) tmp[j++] = arr[i];
    for(int i = 0; i < k; i++) tmp[j++] = arr[i];
    for(int i = 0; i < n; i++) arr[i] = tmp[i];
    /*
    k %= n; int gcd = __gcd(k, n);
    for(int i = 0; i < gcd; i++) {
        int tmp = arr[i];
        int j = i;
        while(1) {
            int x = (j + k) % n;
            if(x == i) break;
            arr[j] = arr[x]; j = x;
        }
        arr[j] = tmp;
    } */
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
