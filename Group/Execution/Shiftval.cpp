#include<bits/stdc++.h>
using namespace std;
//find position to insert current element of arr using binary search
int Bsearch(float *arr, int val, int l, int r) {
    if(l >= r) return (val > arr[l] ? (l + 1): l);
    int mid = (l + r) >> 1;
    if(val == arr[mid]) return mid + 1;
    if(val > arr[mid]) return Bsearch(arr, val, mid + 1, r);
    return Bsearch(arr, val, l, mid - 1);
}
void valmedian(int *arr, int n) {
    int j, pos, cnt = 1; float median;
    for(int i = 1; i < n; i++) {
        j = i - 1; num = arr[i];
        pos = Bsearch(arr, num, 0, j);
        while(j >= pos) {
            arr[j + 1] = arr[j]; j--;
        }
        arr[j + 1] = num; cnt++;
        if(cnt % 2 != 0) median = arr[cnt / 2];
        else median = (arr[(cnt / 2) - 1] + arr[cnt / 2]) / 2;
    }
    cout << median << endl;
}
void valmedian(int *arr, int n) {
    priority_queue <int> x, y;
    for(int i = 0; i < n; i++) {
        x.push(arr[i]);
        int tmp = x.top(); x.pop();
        y.push((-1) * tmp);
    }
    if(x.size() != y.size()) cout << (double) x.top();
    else cout << (double)((x.top() - y.top()) / 2);
}
void pushzero(vector <int> vec) {
    stable_partition(vec.begin(), vec.end(), [](int n) {return n != 0;});
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
        if(arr[i] < arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
}
void rearrange(int *arr, int n) {
    int tmp[n], l = 0, r = n - 1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(flag) tmp[i] = arr[l++];
        else tmp[i] = arr[r--];
        flag = false;
    }
    for(int i = 0; i < n; i++) arr[i] = tmp[i];
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
void fix(int *arr, int n) {
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
void fix(int *arr, int n) {
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
//rearrange an array such that arr[i] = i.
int fixarr(int *arr, int n) {
    vector <int> vec(n, -1);
    for(int i = 0; i < n; i++) {
        if(arr[i] != -1) vec[arr[i]] = arr[i];
    }
    for(int i = 0; i < n; i++) arr[i] = vec[i] << " ";
}
void fixarr(int *arr, int n) {
    int i = 0;
    while(i < n) {
        int val = arr[i]; 
        if(arr[i] != -1 && arr[i] != arr[val]) swap(arr[i], arr[val]);
        else i++;
    }
    return arr;
}
void fixarr(int *arr, int n) {
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
            cnt++; vec.erase(vec.begin() + i); 
            i--; n--;
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

