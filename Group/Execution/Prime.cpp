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
#include<bits/stdc++.h>
using namespace std;
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
    vector <int> tor(5, 10);
    swap_ranges(vec.begin() + 2, vec.begin() + 5, vec.begin());
}
bool cmp(int a, int b) { return a > b;}
bool grt(int a, int b) { return a < b;}
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
struct great {
    bool operator()(const int &a, const int &b) const { return a > b; }
};
void Build(vector <int> vect, vector <int> vec) {
    vector<int> cev(10);
    vector<int> v, root(vect.size() + vec.size());
    sort(vect.begin(), vect.end());
    sort(vec.begin(), vec.end());
    merge(vect.begin(), vect.end(), vec.begin(), vec.end(), cev.begin());
    cev.resize(distance(cev.begin(), unique(cev.begin(), cev.end())));
    includes(v.begin(), v.end(), cev.begin(), cev.end()) ?
        cout << "\ncev is included in v" :
        cout << "\ncev isn't included";

    auto it = copy(vect.begin(), vect.end(), root.begin());
    copy(vec.begin(), vec.end(), it);
    root.clear();
    
   // sort(vect.rbegin(), vect.rend());
   // sort(vec.rbegin(), vec.rend());
    //merge(vect.begin(),vect.end(),vec.begin(),vec.end(),great());
    merge(vect.rbegin(),vect.rend(),vec.rbegin(),vec.rend(),back_inserter(root),great());
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
