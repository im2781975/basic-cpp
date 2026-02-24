#include<bits/stdc++.h>
using namespace std;
int Bsearch(float *arr, float val, int l, int r) {
    if(l >= r) return (val > arr[l] ? l + 1 : l);
    int mid = (l + r) >> 1;
    if(val == arr[mid]) return mid + 1;
    if(val > arr[mid]) return Bsearch(arr, val, mid + 1, r);
    return Bsearch(arr, val, l, mid - 1);
}
void valmedian(float *arr, int n) {
    int j, pos; float median;
    for(int i = 1; i < n; i++) {
        j = i - 1; flat num = arr[i];
        pos = Bsearch(arr, num, 0, j);
        while(j >= pos) {
            arr[j + 1] = arr[j]; j--;
        }
        arr[pos] = num;
    }
    float median = (n % 2 == 1)? arr[n / 2] : (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    cout << fixed << setprecision(1) << median << endl;
}
void valmedian(vector <float> arr, int n) {
    float median;
    for (int i = 1; i < n; i++) {
        float num = arr[i];
        int pos = Bsearch(arr, num, 0, i - 1);
        for (int j = i - 1; j >= pos; j--) arr[j + 1] = arr[j];
        arr[pos] = num;
        int cnt = i + 1;  
        if (cnt % 2 == 1) median = arr[cnt / 2];
        else median = (arr[cnt / 2 - 1] + arr[cnt / 2]) / 2.0;
        cout << fixed << setprecision(1) << median << endl;
    }
}
void valmedian(float *arr, int n) {
    priority_queue <int> x, y;
    for(int i = 0; i < n; i++) {
        x.push(arr[i]);
        int tmp = x.top(); x.pop();
        y.push((-1) * tmp);
        if(x.size() < y.size()) {
            tmp = y.top(); y.pop();
            x.push((-1) * tmp);
        }
        if(x.size() == y.size())
            cout << (double)(x.top() + (-1 * y.top())) / 2 << endl;
        else
            cout << (double)x.top() << endl;
    }
}
void valmedian(float *arr, int n) {
    priority_queue <int> maxHeap; // Lower Half
    priority_queue <int, vector <int>, greater <int>> minHeap; // Upper Half
    for(int i = 0; i < n; i++) {
        maxHeap.push((int)arr[i]);
        int tmp = maxHeap.top(); maxHeap.pop();
        minHeap.push(tmp);
        if(maxHeap.size() < minHeap.size()) {
            tmp = minHeap.top(); minHeap.pop();
            maxHeap.push(tmp);
        }
        if(maxHeap.size() == minHeap.size())
            cout << (double)(maxHeap.top() + minHeap.top()) / 2 << endl;
        else
            cout << (double)maxHeap.top() << endl;
    }
}
void pushzero(vector <int> arr) {
    stable_partition(arr.begin(), arr.end(), [](int n){ return n != 0;});
}
void multarr(int *arr, int n) {
    if(n == 0) return 1;
    return arr[n - 1] * multarr(arr, n - 1);
}
void sumarr(int *arr, int n) {
    if(n == 0) return 0;
    return arr[n - 1] + sumarr(arr, n - 1);
}
void revarr(int *arr, int l, int r) {
    while(l < r) {
        int tmp = arr[l]; arr[l] = arr[r];
        arr[r] = tmp; l++; r--;
    }
}
vector <int> segregate(vector <int> arr) {
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        while(l < r && arr[l] % 2 == 0) l++;
        while(l < r && arr[r] % 2 != 0) r--;
        if(l < r) swap(arr[l++], arr[r--]);
    }
    return arr;
}
void rearrange(int *arr, int n) {
    for(int i = 0; i < n - 2; i += 2) {
        if(arr[i] < arr[i + 1]) swap(arr, arr[i + 1]);
    }
}
void rearrange(int *arr, int n) {
    int tmp[n], l = 0, r = n - 1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(flag) tmp[i] = arr[l++];
        else tmp[i] = arr[r--];
        flag != flag;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void assign(int *arr, int n) {
    sort(arr, arr + n); int res[n];
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 == 0) res[i] = arr[r--];
        else res[i] = arr[l++];
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}
// rearrange an array such that arr[i] = i
void rearrange(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[j] == i){
                swap(arr[j], arr[i]); break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] != i) arr[i] = -1;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void rearrange(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] != i && arr[i] != -1) {
            int x = arr[i];
            while(arr[x] != x && arr[x] != -1) swap(arr[x], x);
            arr[x] = x;
            if(arr[i] != i) arr[i] = -1;
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
int rearrange(int *arr, int n) {
    vector <int> vec(n, -1);
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) vec[arr[i]] = arr[i];
    }
    for(int i = 0; i < n; i++) arr[i] = vec[i];
}
int rearrange(int *arr, int n) {
    int i = 0; 
    while(i < n) {
        int val = arr[i];
        if(arr[i] != -1 && arr[i] != arr[val]) swap(arr[i], arr[val]);
        i++;
    }
    return arr;
}
void rearrange(int *arr, int n) {
    unordered_set <int> st;
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) st.insert(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(st.find(i) != st.end()) arr[i] = i;
        else arr[i] = -1;
    }
}
void shiftzero(vector <int> vec) {
    int cnt = 0, n = vec.size();
    for(int i = 0; i < n; i++) {
        if(vec[i] == 0) {
            vec.erase(vec.begin() + i);
            cnt++; i--; n--;
        }
    }
    for(int i = 0; i < cnt; i++) vec.push_back(0);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}
void shiftzero(int *arr, int n, int *res) {
    int j = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) res[j++] = arr[i];
        else cnt++;
    }
    while(cnt > 0) {
        res[j++] = 0; cnt--;
    }
    for(int i = 0; i < n; i++) arr[i] = res[i];
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void shiftzero(int *arr, int n) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) swap(arr[j++], arr[i]);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
void slidewindow(vector <int> vec, int n, int k) {
    int l = 0, r = 0, sum = 0, res = -1;
    while(r < n) {
        sum += vec[r];
        if(r - l + 1 < k) r++;
        else if(r - l + 1 == k) {
            res = max(res, sum);
            sum -= vec[l]; l++; r++;
        }
    }
    cout << res;
}
int maxsubarrsum(vector <int> vec, int k) {
    vector <int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + vec[i - 1];
    int res = INT_MIN;
    for(int i = k; i <= n; i++) {
        res = max(res, prefix[i] - prefix[i - k]);
    }
    return res;
}
int maxslidingwindow(vector <int> vec, int k) {
    deque <int> dq;
    int res = INT_MIN;
    for(int i = 0; i < vec.size(); i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && vec[dq.back()] < vec[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) res = max(res, vec[dq.front()]);
    }
    return res;
}
