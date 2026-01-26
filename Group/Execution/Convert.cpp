#include<bits/stdc++.h>
using namespace std;
//find an element that can be used to operate on an arr & get equal
void Equalize(int *arr, int n) {
    set <int> st;
    for(int i = 0; i < n; ++i) st.insert(arr[i]);
    if(st.size() == 1) cout << "YES";
    else if(st.size() == 2) {
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        cout << *y << " " << *x << " " << *y - *x << endl;
    }
    else if(st.size() == 3) {
        auto x = st.begin(); st.erase(x);
        auto y = st.begin(); st.erase(y);
        auto z = st.begin(); st.erase(z);
        if((*z - *y) == (*y - *x)) cout << *z - *y;
        else cout << "NO";
    }
    else cout << "NO";
}
void apply(int *arr, int n, int x, int y, int z) {
    for(int i = 0; i < n; i++) arr[i] = x * arr[i] * arr[i] + y * arr[i] + z;
    int idx, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxi) {
            maxi = arr[i]; idx = i;
        }
    }
    int i = 0, j = n - 1;
    int ray[n], k = 0;
    while(i < idx && j > idx) {
        if(arr[i] < arr[j]) ray[k++] = arr[i++];
        else ray[k++] = arr[j--];
    }
    while(i < idx) ray[k++] = arr[i++];
    while(j > idx) ray[k++] = arr[j--];
    ray[n - 1] = maxi;
    for(int i = 0; i < n; i++) arr[i] = ray[i];
}
//minimum swap required to convert BT to BST
void inorder(int *arr, vector <int> vec, int n, int idx) {
    if(idx >= n) return;
    inorder(arr, vec, n, 2 * idx + 1);
    vec.push_back(arr[idx]);
    inorder(arr, vec, n, 2 * idx + 2);
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}
// find minimum swaps to sort an array
void minswap(vector <int> vec) {
    vector <pair <int, int>>tmp(vec.size());
    for(int i = 0; i < vec.size(); i++) {
        tmp[i].first = vec[i]; tmp[i].second = i;
    }
    int res = 0;
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); ++i) {
        if(i == tmp[i].second) continue;
        else {
            swap(tmp[i].first, tmp[tmp[i].second].first);
            swap(tmp[i].second, tmp[tmp[i].second].second);
        }
        if(i != tmp[i].second) i--;
        ++res;
    }
    cout << res << endl;
    for(int i = 0; i < tmp.size(); ++i)
        cout << tmp[i].first << " " << tmp[i].second << endl;
}
// convert to Idx
void convert(int *arr, int n) {
    int ray[n]; copy(arr, arr + n, ray);
    sort(ray, ray + n);
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[ray[i]] = i;
    for(int i = 0; i < n; i++) arr[i] = mp[arr[i]];
}
void convert(int *arr, int n) {
    vector <pair <int, int>> vec;
    for(int i = 0; i < n; ++i) 
        vec.push_back(make_pair(arr[i], i));
    sort(vec.begin(), vec.end());/*
    for(int i = 0; i < n; i++)
        cout << vec[i].first << " " << vec[i].second << endl; */
    for(int i = 0; i < n; ++i)
        arr[vec[i].second] = i;
}
void print(int *arr, int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int add(int a, int b){ return a + b; };
int prd(int a, int b){ return a * b; };
void sum(int *arr, int n, int val) {
    cout << accumulate(arr, arr + n, val) << endl;
    cout << accumulate(arr, arr + n, val, minus <int> ()) << endl;
    cout << accumulate(arr, arr + n, val, prd) << endl;
    int ray[n];
    adjacent_difference(arr, arr + n, ray); print(ray, n);
    adjacent_difference(arr, arr + n, ray, multiplies <int> ()); print(ray, n);
    adjacent_difference(arr, arr + n, ray, add); print(ray, n);
    cout << inner_product(arr, arr + n, ray, val) << endl;
    // arr[0] * ray[0] + arr[1] * ray[1]..+ val
    cout << inner_product(arr, arr + n, ray, val, add, prd) << endl;
    cout << inner_product(arr, arr + n, ray, val, minus <int> (), divides <int> ()) << endl;
    partial_sum(arr, arr + n, ray); print(ray, n);
    partial_sum(arr, arr + n, ray, prd); print(ray, n);
}
//find the largest three elements in an array
int dreilargest(int *arr, int n) {
    int first, duo, drei;
    if(n < 3) return 0;
    first = duo = drei = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > first) {
            drei = duo; duo = first; first = arr[i];
        }
        else if(arr[i] > duo && arr[i] != first) {
            drei = duo; duo = arr[i];
        }
        else if(arr[i] > drei && arr[i] != duo && arr[i] != first) drei = arr[i];
    }
    cout << first << " " << duo << " " << drei << endl;
}
void dreilargest(int *arr, int n) {
    sort(arr, arr + n);
    int check = 0, cnt = 1;
    for(int i = 1; i <= n; ++i) {
        if(cnt < 4) {
            if(check != arr[n - i]) {
                cout << arr[n - i] << " ";
                check = arr[n - i]; cnt++;
            }
        }
        else break;
    }
}
void duolargest(int *arr, int n) {
    sort(arr, arr + n);
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] != arr[n - 1]) cout << arr[i] << endl;
        return;
    }
}
void duolargest(vector <int> vec) {
    set <int> st(vec.begin(), vec.end());
    /*if(st.size() < 2) return;
    vector <int> uniq(vec.begin(), vec.end());
    cout << uniq[uniq.size() - 2]; */
    vec.clear();
    set <int> ::iterator it;
    for(it = st.begin(); it != st.end(); ++it) vec.push_back(*it);
    cout << vec[vec.size() - 2];
}
int duogiant(int *arr, int n) {
    int giant = 0, duogiant = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[giant]) giant = i;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[giant]) {
            if(duogiant == -1) duogiant = i;
            else if(arr[i] > arr[duogiant]) duogiant = i;
        }
    }
    return duogiant;
}
int duogiant(int *arr, int n) {
    int first = 0, duo = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[first]) {
            duo = first; first = i;
        }
        else if(arr[i] < arr[first]) {
            if(duo == -1 || arr[duo] != arr[first]) duo = i;
        }
    }
    return duo;
}
void duogiant(int n, vector <int> vec) {
    map <int, int> mp;
    for(int i = 0; i < n; i++) mp[vec[i]]++;
    if(mp.size() == 1) return;
    int sz = 1;
    for(auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        if(sz == 2){ cout >> it -> first; break; }
        sz++;
    }
}
void duogiant(vector <int> vec) {
    priority_queue <int> pq;
    for(int i = 0; i < vec.size(); ++i) pq.push(vec[i]);
    pq.pop(); cout << pq.top();
}
