#include<bits/stdc++.h>
using namespace std;
void print(vector <int> vec) {
    for(int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
    cout << endl;
}
void adjfind(vector <int> vec, int rng) {
    vector <int> ::iterator it;
    it = adjacent_find(vec.begin(), vec.begin() + rng, greater <int> ());
    if(it == vec.begin() + rng) cout << "sorted in " << rng << endl;
    else cout << "not sorted in " << rng << endl;
}
void pushinto(vector <int> vec, vector <int> tor) {
    int n = 5;
    for_each(vec.begin(), vec.end(), [](int &i){ i += 2; });
    for_each(vec.begin(), vec.end(), [](int i){ cout << i << " "; });
    auto pushinto = [&](int val) {
        vec.push_back(val);
        tor.push_back(val);
    }; pushinto(20);
    // access vec by copy
[vec]() {
    for(auto it = vec.begin(); it != vec.end(); ++it) cout << *it << " ";
    cout << endl;
}();
    auto p = find_if(vec.begin(), vec.end(), [n](int i){ return i > n; });
    if (p != v1.end()) cout << *p << " ";
    else cout << "not exits";
    // [=] denotes all variable
    int count_N = count_if(vec.begin(), vec.end(), [=](int a) {
        return (a >= n);
    });
    cout << "The number of elements greater than or equal to 5 is : "<< count_N << endl;
}
void cpy(vector <int> vec) {
    vector <int> x(vec);
    vector <int> y(x);
    vector <int> z (x.size() + vec.size());
    cout << y.front() << endl;
    print(x); print(y);
    x.clear(); y.clear();
    copy(vec.begin(), vec.end(), back_inserter(y)); print(y);
    x = y;
    vector <int> ::iterator it;
    merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    print(z);
    for(it = z.end() - 1; it != z.begin(); --it) cout << *it << " ";
    cout << endl;
    y.assign(z.begin(), z.end()); print(y);
    int n = 0;
    y.insert(y.begin() + n, x.begin() + n, x.end()); print(y);
}
void dup(vector <int> vec) {
    vector <int> tor(vec.size()), cev(vec.size()), arr(vec.size());
    copy(vec.begin(), vec.begin() + 3, tor.begin()); print(tor);

    vector <int> ::iterator it;
    copy(vec.begin(), vec.end(), inserter(arr, it)); print(arr);
    copy_n(vec.begin(), 4, cev.begin()); print(cev);
    copy_if(vec.begin(), vec.end(), tor.begin(), [](int i){ return i % 2 != 0;}); print(tor);
    copy_backward(vec.begin(), vec.end() + 4, cev.begin() + 5); print(cev);
}
void opr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) arr[i] *= 2;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
bool divi(int a, int b) {
    if(a % b == 0) return 1;
    else return 0;
}
void adjfind(int *arr, int n) {
    int *ptr = adjacent_find(arr, arr + n);
    cout << *ptr << endl;
    
    bool allpos = all_of(arr, arr + n, [](int i) { return i > 0; });
    bool anyEven = any_of(arr, arr + n, [](int i) { return i % 2 == 0; });
    bool noneNeg = none_of(arr, arr + n, [](int i) { return i < 0; });
    cout << "\nAfter impose none_of: ";
    if (noneNeg) opr(arr, n);
    if (allpos) opr(arr, n);
    if(anyEven) opr(arr, n);

    int ar[n]; copy_n(arr, n, ar);
    vector <int> vec(arr, arr + n);
    vector <int> cev(ar, ar + n);
    auto p = find_first_of(vec.begin(), vec.end(), cev.begin(), cev.end());
    cout << p - vec.begin();
    vector <int> ::iterator it;
    it = find_first_of(vec.begin(), vec.end(), cev.begin(), cev.end(), divi); cout << *it << endl;
    
    string s1 = "You are reading about std::find_first_of"; 
    string s2 = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'}; 
    auto ip = find_first_of(s1.begin(),s1.end(), s2.begin(), s2.end()); 
    cout << "\nFirst vowel found at index "<<(ip - s1.begin());
    
    vector <int> ::iterator it1, it2;
    it1 = vec.begin(); it2 = vec.end() - 1;
    iter_swap(it1, it2);
    print(vec);
    vector <int> tor(5, 10);
    swap_ranges(vec.begin() + 2, vec.begin() + 5, vec.begin());
    print(tor); print(vec);
}
bool cmp(int a, int b) {
    return a > b;
}
bool grt(int a, int b) {
    return a < b;
}
void iot(int *arr, int n) {
    iota(arr, arr + n, 20);
    int *it, *pt, *rt
    it = is_sorted_until(arr, arr + 6, cmp);
    pt = min_element(arr, arr + 6, cmp);
    rt = max_element(arr, arr + 6, grt);
    cout << *it << " " << *pt << " " << *rt << (it - arr) << endl;
    vector <int> vec(arr, arr + n);
    vector <int> tor {22, 23};
    vector <int> ::iterator vt;
    vt = search(vec.begin(), vec.end(), tor.begin(), tor.end(), cmp);
    if(vt != vt.end()) cout << vt - vec.begin();
    else cout << "tor isn't present";
}
