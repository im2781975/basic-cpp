#include<bits/stdc++.h>
using namespace std;
void moving(vector <int> vec) {
    vector <int> cev(5, 7);
    move(vec.begin(), vec.begin() + 3, cev.begin() + 1);
    move_backward(cev.begin(), cev.begin() + 2, vec.begin() + vec.begin() + 3);
    sort(vec.begin(), vec.end(), greater <int> ());
    cout << *max_element(vec.begin(), vec.end()) << endl;
    cout << *min_element(vec.begin(), vec.end()) << endl;
    cout << accumulate(vec.begin(), vec.end(), 0);
    cout << distance(vec.begin(), max_element(vec.begin(), vec.end()));
    next_permutation(vec.begin(), vec.end());
    prev_permutation(vec.begin(), vec.end(0));
    partial_sort(vec.begin(), vec.begin() + 2, vec.end());
    partial_sort(vec.begin(), vec.begin() + 2, vec.end(), greater <int> ());
    auto it = vec.begin(); cout << *it;
    cev.resize(vec.size());
    partial_sort_copy(vec.begin(), vec.end(), cev.begin(), cev.end());
    sort(cev.begin(), cev.begin() + 3);
    vector <int> tor(12);
    auto it = copy(vec.begin(), vec.end(), tor.begin());
    copy(cev.begin(), cev.end(), it);
    inplace_merge(tor.begin(), it, tor.end());
    for(auto it = tor.begin(); it != tor.end(); ++it) cout << *it << " ";
    
    cout << is_partitioned(vec.begin(), vec.end(), [](int x) {return x % 2 == 0; }) ? "partitioned" : "not partitioned";
    bool var = is_partitioned(vec.begin(), vec.end(), Iseven); 
    cout << (var == 1) ? "partitioned" : "not partitioned";
    int var = count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    vec.resize(var); cev.resize(vec.size() - n);
    partition_copy(vec.begin(), vec.end(), cev.begin(), cev.end(), [](int x) {return x % 2 == 0;});
    stable_partition(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    auto tr = partition_point(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    for(auto it = vec.begin(); it != tr; it++) cout << *it << " ";
    vector <int> ::iterator pt;
    pt = stable_partition(vec.begin(), vec.end(), Isodd);
    for(auto it = vec.begin(); it != pt; ++it) cout << *it << " ";
    for(auto it = pt; it != vec.end(); ++it) cout << *it << " ";
    vector <int> ::iterator it, pt;
    it = vec.begin(); pt = vec.end();
    if(it != pt) cout << "values isn't same";
    else cout << "value is same";
    cout << distance(it, pt);
}
bool Iseven(int x) { return (x % 2 == 0); }
bool Isodd(int x) { return (x % 2); }
bool Isprime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
bool cmp(int x) { return (x < 0); }
bool lessthan(int x, int y) { return x < y; }
void func(int *arr, int n) {
    if(none_of(arr, arr + n, Isprime)) cout << "composite";
    else cout << "prime";
    bool even = none_of(arr, arr + n, Iseven);
    bool odd =  none_of(arr, arr + n, Isodd);
    if((!even) && (!odd)) cout << "contain both even-odd";
    else if((!even) && odd) cout << "contain odd";
    else if(even && (!odd)) cout << "contain even";
    else cout << "Empty";
    if(none_of(arr, arr + n, cmp)) cout << "positive in range";
    else cout << "Negetive in range";
    nth_element(arr, arr + 2, arr + n);
    nth_element(arr, arr + 2, arr + n, less);
    nth_element(arr, arr + 2, arr + n, greater <int> ());
    sort(arr, arr + n);
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    } while(next_permutation(arr, arr + n));
    reverse(arr, arr + n);
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    } while(prev_permutation(arr, arr + n));
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    transform(arr, arr + n, arr, incr);
    int ray[] = {4, 5, 6}, res[n];
    transform(arr, arr + n, ray, res, plus <int> ());
    
    vector <int> vec(arr, arr + n);
    cout << count_if(vec.begin(), vec.end(),iseven);
    cout << count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0;});
    cout << count(vec.begin(), vec.end(), 20);
    cout << (find(vec.begin(), vec.end(), 5) != vec.end()) ? "found" : "not found";
    
    nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
    cout << vec[vec.size() / 2];
    sort(vec.begin(), vec.end(), not2(greater <int> ()));
    sort(vec.begin(), vec.end(), not2(less <int> ()));
    vector <int> cev(vec.begin(), vec.end());
    cout << (equal(cev.begin(), cev.end(), vec.begin())) ? "Equal" : "Not Equal";
    vector <int> tor(arr, arr + n);
    cout << (equal(tor.begin(), tor.end(), arr, lessthan))? "Equal" : "Not Equal";
    vector <pair <int, int >> arr{{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}};
    pair <int, int> trg = {3, 30};
    auto low = lower_bound(arr.begin(), arr.end(), trg);
    cout << low - arr.begin();
    string ing = "geeksforgeeks";
    cout << count(ing.begin(), ing.end(), 'e');
}
bool great(int a, int b) { return a > b; }
bool eq(int a, int b){ return a == b; }
bool IsOdd(int i) { return i % 2; }
bool mud(int a, int b) {
    if(a % b == 0) return 1;
    else return 0;
}
int gen() { static int i = 0; return ++i; }
int incr(int x) { return (x + 1); }
void range(vector <int> vec) {
    generate(vec.begin(), vec.end());
    generate_n(vec.begin(), 5, gen);
    
    pair <vector <int> ::iterator, vector <int> ::iterator> it;
    it = equal_range(vec.begin(), vec.end(), 30);
    cout << it.first - vec.begin() << " " << it.second - vec.begin() << endl;
    sort(vec.begin(), vec.end(), greater <int> ());
    it = equal_range(vec.begin(), vec.begin() + 12, 10, great);
    vector <int> ::iterator it, pt;
    it = lower_bound(vec.begin(), vec.end(), 5); cout << it - vec.begin();
    pt = upper_bound(vec.begin(), vec.end(), 10); cout << pt - vec.end();
    vector <int> cev(vec.begin(), vec.end());
    cout << (equal(cev.begin(), cev.end(), vec.begin())) ? "Equal" : "Not Equal";
    
    vector <int> ect(8, 1);
    fill(ect.begin(), ect.end(), 7);
    fill(ect.begin() + 2, ect.end() - 2, 5);
    fill_n(ect.begin(), 4, 7);
    fill_n(ect.begin() + 2, 2, 3);
    
    vector <int> arr{1, 2, 3, 4, 5};
    vector <int> vec{3, 4, 5};
    vector <int> ::iterator tt, pt;
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        tt = ect.begin(); pt = it;
        while(pt != arr.end() && tt != ect.end() && *pt == *tt) {
            pt++; tt++;
        }
        if (tt == ect.end()) cout << it - arr.begin();
    }
    cout << "subseq not found";
}
struct great {
    bool operator()(const int &a, const int &b) const { return a < b; }
};
void heap(vector <int> vec){
    vector <int> ::iterator it, pt;
    cout << is_heap(vec.begin(), vec.end()) ? "is heaped" : "isn't heaped";
    pt = is_heap_until(vec.begin(), vec.end());
    // make_heap(vec.begin(), vec.end(), great());
    make_heap(vec.begin(), vec.end());
    vec.push_back(30);
    push_heap(vec.begin(),vec.end());
    vec.pop_back();
    pop_heap(vec.begin(),vec.end());
    sort_heap(vec.begin(), vec.end());
    cout << vec.front() << endl;
}
void minheap(int *arr, int n) {
    priority_queue <int, vector <int>,  greater <int> > pq( arr, arr + n);
    while(!pq.empty()) {
        cout << pq.top() << " "; pq.pop();
    }
}


