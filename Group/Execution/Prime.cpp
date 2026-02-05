#include<bits/stdc++.h>
using namespace std;
void primes(int n) {
    vector <int> prime;
    vector <bool> flag(n + 1);
    for(int i = 2; i <= n; i++) {
        if(flag[i] == false) {
            prime.push_back(i);
            for(int x = 2; i * x <= n; x++){
                flag[i * x] = true;
            }
        }
    }
    for(int i = 0; i < prime.size(); i++)
        cout << prime[i] << " ";
}
int recusive(int *arr, int n, int l, int r) {
    if(l == r) return arr[l];
    else {
        int mid = l + (r - l) / 2;
        return min(recursive(arr, n, l, mid - 1), recursive(arr, n, mid + 1, r));
    }
}
void cntzero(int *arr, int n, int q) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] != 0) cnt++;
    }
    while(q--) {
        int type, idx; cin >> type >> idx;
        if(type == 2) {
            if(arr[idx] == 0) arr[idx]++;
        }
        else if(type == 1) {
            if(arr[idx] > 0) {
                arr[idx]--;
                if(arr[idx] == 0) cnt--;
            }
        }
    }
    cout << cnt;
}
bool IsOdd(int val) { return ((val % 2) == 1); }
void suffle(int *arr, int n) { random_shuffle(arr, arr + n); }
int randsuffle(int x) { return rand() % x; }
bool pred(int i, int j) { return (i == j); }
bool func(char a, char b) {
    if(a == b && a == 'v') return 1;
    else return 0;
}
void unq() {
    string s = "You arre vvvisiting GFG", t;
    auto it = unique_copy(s.begin(), s.end(), back_inserter(t), func);
    auto tt = unique(s.begin(), s.end(), func);
    cout << s << " " << string(s.begin(), tt) << " " << s << endl;
}
void valremove(vector <int> vec, vector <int> tmp) {
    vector <int> ::iterator it;
    it = remove(vec.begin(), vec.end(), 20);
    for(auto pt = vec.begin(); pt != it; ++pt) cout << *pt << " ";
    remove_copy(vec.begin(), vec.end(), vec.begin(), 30);
    it = remove_if(vec.begin(), vec.end(), [](int i){ return (i % 2) == 1;});
    // it = remove_if(vec.begin(), vec.end(), IsOdd);
    remove_copy_if(vec.begin(), vec.end(), vec.begin(), IsOdd);
    vec.erase(find(vec.begin(), vec.end(), 10));
    replace_copy_if(vec.begin(), vec.end(), tmp.begin(), IsOdd, -1);
    reverse(vec.begin() + 3, vec.begin() + 7);
    reverse(vec.begin(), vec.end());
    reverse_copy(vec.begin(), vec.end(), tmp.begin());
    rotate(vec.begin(), vec.begin() + 2, vec.end());
    rotate(vec.begin(), vec.begin() + vec.size() - 4, vec.end());
    rotate_copy(vec.begin(), vec.begin() + 3, vec.end(), tmp.begin());
    vector <char> cev;
    for(int i = 0; i < 7; i++) cev.push_back('A' + i);
    replace_copy(cev.begin(), cev.begin() + 1, cev.begin(), 'A', 'Z');
    int val = 3;
    auto it = search_n(vec.begin(), vec.end(), 2, val, pred);
    if(it != vec.end()) cout << it - vec.begin();
    else cout << "val isn't present consecutively 2 times".
    auto it = search(vec.begin(), vec.end(), tmp.begin(), tmp.end());
    if(it != vec.end()) cout << it - vec.begin();
    else cout << "tmp isn't present in vec ";
    auto it = find_end(vec.begin(), vec.end(), tmp.begin(), tmp.end());
    if(it != vec.end()) cout << it - vec.begin();
    else cout << "tmp isn't present in vec ";
    auto it = find_first_of(vec.begin(), vec.end(), tmp.begin(), tmp.end()); cout << *it;
    it = find_first_of(it + 1, vec.end(), tmp.begin(), tmp.end()); cout << *it;
    it = find_if(vec.begin(), vec.end(), IsOdd); cout << *it;
    it = find_if_not(vec.begin(), vec.end(), IsOdd); cout << *it;
    vector <int> cev = {2};
    it = find_end(vec.begin(), vec.end(), cev.begin(), cev.end(), pred);
    cout << it - vec.begin();
    it = find_first_of(vec.begin(), vec.end(), cev.begin(), cev.end(), pred); cout << it - vec.begin();
    sort(vec.begin(), vec.end());
    tmp.resize(vec.size());
    auto it = unique_copy(vec.begin(), vec.end(), tmp.begin());
    tmp.resize(distance(tmp.begin(), it));
    auto it = unique(vec.begin(), vec.begin() + vec.size() - 1);
    vec.resize(distance(vec.begin(), it));
    cout << distance(vec.begin(), unique(vec.begin(), vec.begin() + vec.size() - 1));
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << vec.front() << " " << vec.back() << vec.pop_back() << endl;
    while(!vec.empty()) {
        cout << vec.back() << " "; vec.pop_back();
    }
    vec.resize(10, 1);
    cout << vec.empty();
    for(int i = 1; i <= 10; i++) tmp.push_back(i * 2);
    cout << vec[2] << " " << vec.at(2) << endl;
    int *pos = vec.data; cout << *pos;
}
void replacerev(int *arr, int n, int old, int val) {
    srand(unsigned(time(0)));
    suffle(arr, n);
    vector <int> vec(arr, arr + n);
    random_shuffle(vec.begin(), vec.end(), randsuffle(2));
    random_shuffle(vec.begin(), vec.end());
    replace(arr, arr + n, old, val);
    replace_if(arr, arr + n, IsOdd, val);
    
    array <int, 5> ar{1, 2, 3, 4, 5};
    unsigned seed = 0;
    shuffle(ar.begin(), ar.end(), default_random_engine(seed));
}
void print(valarray <int> vec) {
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
void assign(valarray <int> arr) {
    valarray <int> x, y;
    x = arr.apply([](int x){ return x += 5;});
    cout << x.sum() << " " << arr.sum();
    swap(s, arr);
    y = arr.shift(-2); cout << y << endl;
    y = arr.cshift(-3); cout << y << endl;
    y = arr.cshift(3); cout << y << endl;
}
void pair() {
    vector <pair <int, int>> vpr;
    int arr[]{10, 20, 5, 40};
    int ray[]{30, 60, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        vec.push_back(make_pair(arr[i], ray[i]));
    for(int i = 0; i < n; i++)
        cout << vec[i].first << " " << vec[i].second << endl;
}
void initvec(vector <int> vec) {
    vec.clear();
    vec.assign(5, 10);
    vec.push_back(15);
    vec.pop_back();
    vec.insert(vec.begin(), 5);
    vec.erase(vec.begin());
    vec.emplace(vec.begin(), 5); // inserts at the beginning
    vec.emplace_back(20); // insert at the end
    cout << vec.size() << " " << vec.capacity() << " " << vec.max_size();
    vec.resize(4);
    vec.shrink_to_fit();
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << " ";
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
        cout << *it << " ";
    for (auto it = vec.crbegin(); it != vec.crend(); it++)
        cout << *it << " ";
    vector <int> tmp;
    sort(vec.begin(), vec.end(), not2(less <int> ()));
    vec.swap(tmp);
    
    vector<int> vec {5, 4, 1, 2, 1, 3};
    vector<int> cev {3, 2, 1, 4, 0, 2};
    vector<int> tor(vec.size() + cev.size());
    vector<int> tcev(vec.size()+cev.size());
    vector<int> union_vec(vec.size()+cev.size());
    vector<int> intersec_vec(vec.size()+cev.size());
    auto it = set_symmetric_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    tor.clear();
    auto it = set_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    auto it = set_union(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    tor.clear();
    auto it = set_intersection(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    if(vec.size() % 2 == 0)
        swap_ranges(vec.begin(), vec.begin() + (vec.size() / 2), vec.begin() + vec.size() / 2);
    else swap_ranges(vec.begin(), vec.begin() + vec.size() / 2, vec.begin() + (vec.size() / 2) + 1);
    pair <vector <int> ::iterator, vector <int> ::iterator >mispair;
    mispair = mismatch(vec.begin(), vec.end(), cev.begin()); 
    cout << *mispair.first << " " << *mispair.second << endl;
    pair <vector <int> ::iterator, vector <int> ::iterator >minmax;
    minmax = minmax_element(vec.begin(), vec.begin() + 4);
    cout << minmax.first - vec.begin() << " " << minmax.second - vec.begin();
    minmax = minmax_element(vec.begin(), vec.end());
    cout << minmax.first - vec.begin() << " " << minmax.second - vec.begin();
    pair <int, int> arr = minmax({2, 5, 1, 6, 3});
    cout << arr.first << " " << arr.second;
}

