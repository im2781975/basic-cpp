#include<bits/stdc++.h>
using namespace std;
int add(int a, int b) { return a + b;}
int prd(int a, int b) { return a * b;}
void Build(int *arr, int n, int val) {
    cout << accumulate(arr, arr + n, val) << endl;
    cout << accumulate(arr, arr + n, val, minus <int> ()) << endl;
    cout << accumulate(arr, arr + n, val, prd) << endl;
    int ray[n];
    adjacent_difference(arr, arr + n, ray);
    adjacent_difference(arr, arr + n, ray, multiplies <int> ());
    adjacent_difference(arr, arr + n, ray, add);
    cout << inner_product(arr, arr + n, ray, val) << endl;
    // arr[0] * ray[0] + arr[1] * ray[1]..+ val
    cout << inner_product(arr, arr + n, ray, val, add, prd) << endl;
    cout << inner_product(arr, arr + n, ray, val, minus <int> (), divides <int> ()) << endl;
    partial_sum(arr, arr + n, ray);
    partial_sum(arr, arr + n, ray, prd);
    for(int i = 0; i < n; i++) cout << ray[i] << " ";
    cout << endl; 
}
void Buildvector(vector <int> vec) {
    vector <int> ::iterator it;
    for(it = vec.begin(); it!= vec.end(); ++it) {
        if(it == vec.begin()) it = vec.insert(it, 8);
        if(it == vec.begin() + 1) it = vec.erase(it);
    }
    for(int i = 1; i < 10; i++) vec.push_back(i);
    vec.insert(vec.begin() + 1, 100);
    vec.erase(vec.begin() + 2);
}
void print(vector <int> vec) {
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}
bool Iseven(int x) { return (x % 2 == 0); }
bool Isodd(int x) { return (x % 2); }
bool Isprime(int x) {
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    for(int i = 5; i * i <= x; i += 6) {
        if(x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}
int incr(int x){ return (x + 1); }
void moving(vector <int> vec) {
    vector <int> arr(5, 7);
   // arr(vec.begin(), vec.end());
    move(vec.begin() + 1, vec.begin() + 3, arr.begin() + 1);
    move_backward(arr.begin(), arr.begin() + 2, vec.begin() + 2);
    sort(arr.begin(), arr.end(), greater <int> ());
    sort(arr.begin(), arr.end(), less <int> ());
    cout << *max_element(arr.begin(), arr.end()) << endl;
    cout << *min_element(arr.begin(), arr.end()) << endl;
    cout << accumulate(arr.begin(), arr.end(), 0) << endl;
    cout << distance(arr.begin(), max_element(arr.begin(), arr.end())) << endl;
    cout << (equal(arr.begin(), arr.end(), vec.begin())) ? "Equal" : "Not Equal";
    cout << equal(arr.begin(), arr.end(), vec.begin(), [](int a, int b){ return a == b; });
    nth_element(arr.begin(), arr.begin() + 2, arr.end());
    nth_element(arr.begin(), arr.begin() + 2, arr.end(), greater <int> ());
    print(arr);
    cout << arr[arr.size() / 2];
    transform(arr.begin(), arr.end(), arr.begin(), incr);
    print(arr);
    vector <int> res(arr.size());
    transform(arr.begin(), arr.end(), vec.begin(), res.begin(), plus <int> ());
    stable_partition(arr.begin(), arr.end(), [](int x) {return x % 2 == 0;});
    auto tr = partition_point(arr.begin(), arr.end(), [](int x) {return x % 2 == 0;});
    for(auto it = arr.begin(); it != tr; it++) cout << *it << " ";
    cout << endl;
    vector <int> ::iterator pt;
    pt = stable_partition(vec.begin(), vec.end(), Isodd);
    for(auto it = vec.begin(); it != pt; ++it) cout << *it << " ";
    cout << endl;
    for(auto it = pt; it != vec.end(); ++it) cout << *it << " ";
    cout << endl;
    vector <int> ::iterator it;
    it = vec.begin(); pt = vec.end();
    if(it != pt) cout << "values isn't same" << endl;
    else cout << "value is same";
    cout << distance(it, pt) << endl;
    next_permutation(arr.begin(), arr.end());
    prev_permutation(arr.begin(), arr.end());
    partial_sort(arr.begin(), arr.begin() + 2, arr.end());
    partial_sort(arr.begin(), arr.begin() + 2, arr.end(), greater <int> ());
    it = arr.begin(); cout << *it << endl;
    vec.resize(arr.size());
    partial_sort_copy(arr.begin(), arr.end(), vec.begin(), vec.end());
    sort(vec.begin(), vec.begin() + 3);
    vector <int> tmp(12);
    it = copy(arr.begin(), arr.end(), tmp.begin());
    copy(vec.begin(), vec.end(), it);
    inplace_merge(tmp.begin(), it, tmp.end());
    for(auto it = tmp.begin(); it != tmp.end(); ++it) cout << *it << " ";
    cout << endl;
    cout << is_partitioned(arr.begin(), arr.end(), [](int x){ return x % 2 == 0;}) ? "partitioned" : "not partitioned";
    cout << endl;
    bool var = is_partitioned(arr.begin(), arr.end(), Iseven);
    cout << (var == 1) ? "partitioned" : "not partitioned";
    int dig = count_if(arr.begin(), arr.end(), [](int x){ return x % 2 == 0;});
    cout << dig << endl;
    arr.resize(dig); vec.resize(arr.size() );
    partition_copy(arr.begin(), arr.end(), vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    print(vec);
    partition_copy(arr.begin(), arr.end(), back_inserter(vec),back_inserter(tmp), [](int x){ return x % 2 == 0;});
    print(tmp);
}

bool cmp(int x){ return x < 0; }
bool lessthan(int x, int y){ return x < y; }
void prin(int *arr, int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void grp(int *arr, int n) {
    cout << (none_of(arr, arr + n, Isprime) ? "composite" : "prime") << endl;
    bool even = none_of(arr, arr + n, Iseven);
    bool odd = none_of(arr, arr + n, Isodd);
    if((!even) && (!odd)) cout << "contain both even_odd";
    else if((!even) && odd) cout << "contain odd";
    else if(even && (!odd)) cout << "contain even";
    else cout << "Empty";
    cout << endl;
    cout << (none_of(arr, arr + n, cmp)? "positive in range\n" : "negetive in range\n");
    sort(arr, arr + n, lessthan);
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << "\t";
    } while(next_permutation(arr, arr + n));
    cout << endl;
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << "\t";
    } while(prev_permutation(arr, arr + n));
    cout << endl;
    vector <int> vec(arr, arr + n);
    cout << count_if(vec.begin(), vec.end(), Iseven);
    cout << count_if(vec.begin(), vec.end(), [](int x){ return x % 2 != 0;});
    cout << count(vec.begin(), vec.end(), 20);
    cout << (find(vec.begin(), vec.end(), 5) != vec.end()) ? "found" : "not found";
    vector <pair <int, int >> ar{{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}};
    pair <int, int> trg = {3, 30};
    auto low = lower_bound(ar.begin(), ar.end(), trg);
    cout << low - ar.begin();
    string ing = "geeksforgeeks";
    cout << count(ing.begin(), ing.end(), 'e');
}
bool great(int a, int b) { return a > b; }
bool eq(int a, int b){ return a == b; }
bool mud(int a, int b) {
    if(a % b == 0) return 1;
    else return 0;
}
int gen() { static int i = 0; return ++i; }
struct great {
    bool operator()(const int &a, const int &b) const { return a < b; }
};
void range(vector <int> vec) {
    generate_n(vec.begin(), 5, gen);
    for(int x : vec) cout << x << " ";
    cout << endl;
    generate(vec.begin(), vec.end(), [](){ return rand() % 100; });
    cout << vec[0] << " " << vec[1] << endl;
    int counter = 0;
    generate(vec.begin(), vec.end(), [&]{ return counter++; }); 
    for(int x : vec) cout << x << " ";
    cout << endl;
    pair <vector <int> ::iterator, vector <int> ::iterator> it;
    it = equal_range(vec.begin(), vec.end(), 30);
    cout << it.first - vec.begin() << " " << it.second - vec.begin() << endl;
    sort(vec.begin(), vec.end(), greater <int> ());
    it = equal_range(vec.begin(), vec.begin() + 12, 10, great);
    vector <int> ::iterator xt, pt;
    xt = lower_bound(vec.begin(), vec.end(), 5); cout << xt - vec.begin() << endl;
    pt = upper_bound(vec.begin(), vec.end(), 10); cout << pt - vec.begin() << endl;
    vector <int> arr(8, 1);
    fill(arr.begin(), arr.end(), 7);
    fill(arr.begin() + 2, arr.end() - 2, 5);
    fill_n(arr.begin(), 4, 7);
    fill_n(arr.begin() + 2, 2, 3);
    
    vector <int> tmp{1, 2, 3, 4, 5};
    for(auto it = tmp.begin(); it != tmp.end(); ++it) {
        xt = arr.begin(); pt = it;
        while(pt != tmp.begin() && xt != arr.end() && *pt == *xt) {
            pt++; xt++;
        }
        if(xt == arr.end()) cout << it - tmp.begin() << endl;
    }
    cout << "subseq not found\n";
    
    if(is_heap(arr.begin(), arr.end()))
        cout << "isHeap" << endl;
    else cout << "isn'tHeaped" << endl;
    xt = is_heap_until(arr.begin(), arr.end());
    cout << xt - arr.begin() << endl;
    // make_heap(arr.begin(), arr.end(), great());
    make_heap(arr.begin(), arr.end());
    arr.push_back(30);
    push_heap(arr.begin(), arr.end());
    arr.pop_back();
    pop_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
    cout << arr.front() << endl;
}
void minheap(int *arr, int n) {
    priority_queue <int, vector <int>,  greater <int> > pq(arr, arr + n);
    while(!pq.empty()) {
        cout << pq.top() << " "; pq.pop();
    }
    cout << endl;
}
bool func(char a, char b) {
    if(a == b || a == 'v') return 1;
    return 0;
}
void unq() {
    string s = "You arre vvvisiting GFG";
    string t;
    auto it = unique_copy(s.begin(), s.end(), back_inserter(t), func);
    auto xt = unique(s.begin(), s.end(), func);
    cout << s << " " << string(s.begin(), xt) << " " << s << endl;
}
bool pred(int i, int j){ return( i == j);}
void valremove(vector <int> vec) {
    vector <char> charvec;
    for(int i = 0; i < 7; i++) charvec.push_back('A' + i);
    replace_copy(charvec.begin(), charvec.begin() + 1, charvec.begin(), 'A', 'Z');
    vector <int> tmp(10);
    vector <int> ::iterator it;
    it = remove(vec.begin(), vec.end(), 20);
    for(auto pt = vec.begin(); pt != it; ++pt) cout << *pt << " ";
    cout << endl;
    remove_copy(vec.begin(), vec.end(), vec.begin(), 5);
    vec.erase(remove_if(vec.begin(), vec.end(), [](int i){ return (i % 2) == 1; }));
    // it = remove_if(vec.begin(), vec.end(), [](int i){ return (i % 2) == 1;});
    // it = remove_if(vec.begin(), vec.end(), Isodd);
    print(vec);
    remove_copy_if(vec.begin(), vec.end(), vec.begin(), Isodd);
    vec.erase(find(vec.begin(), vec.end(), 9));
    replace_copy_if(vec.begin(), vec.end(), tmp.begin(), Isodd, -1);
    replace_copy_if(vec.begin(), vec.end(), tmp.begin(), [](int x){ return x % 2 == 1;}, -1);
    reverse(vec.begin() + 2, vec.begin() + 4);
    reverse(vec.begin(), vec.end());
    reverse_copy(vec.begin(), vec.end(), tmp.begin());
    rotate(vec.begin(), vec.begin() + 2, vec.end());
    rotate(vec.begin(), vec.begin() + vec.size() - 4, vec.end());
    rotate_copy(vec.begin(), vec.begin() + 3, vec.end(), tmp.begin());
    int val = 3;
    it = search_n(vec.begin(), vec.end(), 2, val, pred);
    if(it != vec.end()) cout << it - vec.begin() << endl;
    else cout << "val isn't present consecutively 2 times\n";
    //print(vec);
    //it = search(vec.begin(), vec.end(), tmp.begin(), tmp.end());
    it = find_end(vec.begin(), vec.end(), tmp.begin(), tmp.end());
    // it = find_end(vec.begin(), vec.end(), tmp.begin(), tmp.end(), pred);
    if(it != vec.end()) cout << it - vec.begin() << endl;
    else cout << "tmp isn't present in vec\n";
    // it = find_first_of(vec.begin(), vec.end(), tmp.begin(), tmp.end(), pred); cout << it - vec.begin() << endl;
    it = find_first_of(vec.begin(), vec.end(), tmp.begin(), tmp.end()); cout << *it << endl;
    it = find_first_of(it + 1, vec.end(), tmp.begin(), tmp.end()); cout << *it << endl;
    it = find_if(vec.begin(), vec.end(), Isodd); cout << *it << endl;
    it = find_if_not(vec.begin(), vec.end(), Isodd); cout << *it << endl;
    sort(vec.begin(), vec.end());
    tmp.resize(vec.size());
    it = unique_copy(vec.begin(), vec.end(), tmp.begin());
    tmp.resize(distance(tmp.begin(), it));
    it = unique(vec.begin(), vec.begin() + vec.size() - 1);
    vec.resize(distance(vec.begin(), it));
    cout << distance(vec.begin(), unique(vec.begin(), vec.begin() + vec.size() - 1));
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << vec.front() << " " << vec.back() << endl;
    vec.pop_back();
    while(!vec.empty()) {
        cout << vec.back() << " "; vec.pop_back();
    }
    vec.resize(10, 1); cout << vec.empty() << endl;
    for(int i = 1; i <= 10; i++) tmp.push_back(i * 2);
    cout << vec[2] << " " << vec.at(2) << endl;
} /*
// void suffle(int *arr, int n) { random_shuffle(arr, arr + n);}
int randsuffle(int x) {return rand() % x; }
void replacerev(int *arr, int n, int old, int val) {
    srand(unsigned(time(0))); //suffle(arr, n);
    vector <int> vec(arr, arr + n);
   // random_shuffle(vec.begin(), vec.end(), randsuffle(2));
    //random_shuffle(vec.begin(), vec.end());
    replace(arr, arr + n, old, val);
    replace_if(arr, arr + n, Isodd, val);
    
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
    swap(y, arr);
    y = arr.shift(-2); 
    cout << y << endl;
    y = arr.cshift(-3); 
    cout << y << endl;
    y = arr.cshift(3); 
    cout << y << endl;
} */
void init(vector <int> vec) {
    vec.clear(); vec.assign(5, 10);
    vec.push_back(15); vec.pop_back();
    vec.insert(vec.begin(), 5), vec.erase(vec.begin());
    vec.emplace(vec.begin(), 5); vec.emplace_back(15);
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
    sort(vec.begin(), vec.end(), greater <int> ());
    vec.swap(tmp);
    
    vector<int> cev {3, 2, 1, 4, 0, 2};
    vector<int> tor(vec.size() + cev.size());
    vector<int> tcev(vec.size() + cev.size());
    vector<int> union_vec(vec.size() + cev.size());
    vector<int> intersec_vec(vec.size()+cev.size());
    auto it = set_symmetric_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    tor.clear();
    it = set_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    it = set_union(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
    tor.resize(it - tor.begin());
    tor.clear();
    it = set_intersection(vec.begin(), vec.end(), cev.begin(), cev.end(), tor.begin());
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
    vector <int> arr = {2, 5, 1, 6, 3};
    auto [min_val, max_val] = minmax_element(arr.begin(), arr.end()); 
    cout << *min_val << " " << *max_val << endl;
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
    if(p != vec.end()) cout << *p << " ";
    else cout << "not exits";
    // [=] denotes all variable
    int count_N = count_if(vec.begin(), vec.end(), [=](int a) {
        return (a >= n);
    });
    cout << "The number of elements greater than or equal to 5 is : "<< count_N << endl;
}
void Insert(vector <int> vec) {
    vector <int> x = vec;
    vector <int> y = vec;
    vector <int> z(4 * vec.size());
    copy(vec.begin(), vec.end(), y.begin()); print(y);
    copy_n(vec.begin(), 4, z.begin()); y.resize(4);
    copy_if(vec.begin(), vec.end(), y.begin(), [](int i){ return i % 2 != 0;}); print(y);
    y.resize(9);
    copy_backward(vec.begin(), vec.begin() + 3, y.begin() + 5); print(y);
    y.resize(4 * vec.size());
    vector <int>::iterator it = y.begin();
    copy(vec.begin(), vec.end(), inserter(y, it)); 
    z.resize(x.size() + y.size());
    merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    for(int i = z.size() - 1; i > 0; i--)
        cout << z[i] << " ";
    cout << endl;
    y.assign(z.begin(), z.end());
    int n = 0;
    y.insert(y.begin() + n, x.begin() + n, x.end()); 
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
