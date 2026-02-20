#include<bits/stdc++.h>
using namespace std;
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
