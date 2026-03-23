/*                LIST                */
using namespace std;
void print(list <int> &lst) {
    list <int> ::iterator it;
    it = lst.begin();
    while(it != lst.end()) {
        cout << *it << " "; ++it;
    }
}
void Insert(list <int> lst, int idx, int val) {
    auto it = lst.begin(); advance(it, idx);
    lst.insert(it, val);
}
void Delete(list <int> lst, int idx) {
    auto it = lst.begin(); advance(it, idx);
    lst.erase(it);
}
int deleteval(list <int> lst, int val) {
    list <int> ::iterator it;
    for(it = lst.begin(); it != lst.end();){
        if(*it == val) it = lst.erase(it);
        else ++it;
    }
}
void File() {
    list <int> x, y, z;
    list <int> ::iterator it;
    for(int i = 1; i < 10; i++) {
        x.push_back(i * 2); y.push_back(i * 3);
    }
    x.swap(y);
    it = x.begin();
    advance(it, 2); x.unique();
    x.splice(it, y); 
    cout << x.front() << " " << x.back();
    x.pop_front();    x.pop_back();.
    x.push_front(15); x.push_back(20);
    Insert(x, 1, 100); Delete(y, 2);
    x.reverse();    y.sort();
    x.remove_if([](int a) {return a % 2 != 0;});
    cout << x.size() << " ";
    for(int i = 1; i <= 10; i++) z.emplace_back(i)
    for(int i = 2; i <= 20; i += 2) z.emplace_front(i);
    it = z.begin(); advance(it, 3);
    z.emplace(it, 100);
    deleteval(z, 100);
}
int getval(list <int> lst, int idx) {
    list <int> ::iterator it = lst.begin();
    advance(it, idx);
    while(it != lst.end()) return *it;
    return -1;
}
bool search(list <int> lst, int val) {
    list <int> ::iterator it = lst.begin();
    while(it != lst.end()) {
        if(*it == val) return true;
        it++;
    }
    return false;
}
void forwardList() {
    forward_list <int> x, y, z;
    forward_list <int> ::iterator it;
    x.assign({1, 2, 3}); x.assign(5, 10);
    y.assign(x.begin(), x.end()); z = x;
    x.splice_after(x.begin(), z);
    x.merge(z); x.sort(); x.unique();
    it = x.insert_after(x.begin(), {1, 2, 3});
    it = x.erase_after(it);
    // it = x.erase_after(x.begin(), x.end());
    x.remove(5);
    y.remove_if([](int a) {return a % 2 != 0;});
    y.clear();
    int idx = 3; cout << getval(x, idx);
    cout << (search(lst, 3) ? "True" : "False");
}
/*                MAP                */
bool canBuildPalindrome(const string& s) {
    unordered_map<char, int> cnt;
    for (char c : s) cnt[c]++;
    int oddCount = 0;
    for (const auto& pair : charCount) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
void map(){
    map <string, int> mp;
    map <string, int> ::iterator it;
    mp["A"] = 3; mp["B"] = 5; mp["B"] = 9;
    cout << mp["A"] << " " << mp["B"] << endl;
    for(it = mp.begin(); it != mp.end(); it++)
        cout << it -> first << " " << it -> second << endl;
    map <int, int> pp;
    map <int, int> ::iterator xt;
    pp[23] = 4; pp[32] = 5;
    for(xt = pp.begin(); xt != pp.end(); xt++) cout << xt -> first << " " << xt -> second << endl;
    cout << (pp.count(23)) ? "Yes" : "No";
}
void multimap() {
    unordered_multimap <string, int> ump
    { {"A", 1}, {"B", 2}, {"C", 3}, 
    {"D", 2}, {"E", 5}, {"F", 6}};
    ump.insert(make_pair("X", 22));
    ump.insert({{"E", 12}, {"F", 33}});
    ump.insert(pair <string, int> ("D", 7));
    for(auto it = ump.begin(); it != ump.end(); it++)
        cout << it -> first << " " << it -> second << endl;
    // search value
    int val = 1;
    auto pt = ump.begin();
    while(pt != ump.end()) {
        if(pt -> second == val) break;
        pt++;
    }
    ump.erase("A");
    cout << pt -> first << endl;
    if(ump.empty()) cout << "multimap empty";
    else cout << "multimap not empty";
    cout << ump.size() << " " << ump.count("A");
    ump.clear(); 
    
    unordered_map <string, double> umap {
        {"A", 2}, {"B", 2}, {"C", 3}
    };
    umap["PI"] = 3.14; umap["root2"] = 1.414; 
    umap.insert(make_pair("e", 2.718)); 
    if(umap.find("PI") == umap.end()) cout << "not found";
    else cout << "found";
    for(auto itr = ump.begin(); itr!= ump.end(); ++itr) cout << itr -> first  << " " << itr -> second << endl;
    
    multimap <int, int> mmp
    { {1, 40}, {2, 30}, {3, 60} };
    mmp.insert( make_pair(6, 12));
    mmp.insert(pair <int, int> (7, 90));
    mmp.insert(pair <int, int> (4, 50));
    mmp.insert(pair <int, int> (5, 10));
    for(auto it = mmp.begin(); it != mmp.end(); it++)
        cout << it -> first << " " << it -> second << endl;
    multimap <int, int> x(mmp.begin(), mmp.end());
    x.erase(x.begin(), x.find(3));
    cout << x.erase(4); //remove all elements with key = 4
    cout << mmp.lower_bound(5) -> first << " " << mmp.lower_bound(5) -> second << endl;
    cout << mmp.upper_bound(5) -> first << " " << mmp.upper_bound(5) -> second << endl;
}
/*                QUEUE                */
#include<bits/stdc++.h>
using namespace std;
void print(queue <int> q) {
    queue <int> tmp = q;
    while(!tmp.empty()) {
        cout << tmp.front() << " "; tmp.pop();
    } cout << endl;
}
void queu() {
    queue <int> p, q;
    for(int i = 1; i < 6; i++) {
        q.push(i * 2); p.push(i * 3);
    }
    print(q); print(p);
    cout << q.size() << " " << q.front() << " " << q.back() << endl;
    q.pop(); q.swap(p);
    cout << q.empty() << endl;
    queue <char> pq; pq.push('a'); pq.push('b');
    cout << pq.size() << " " << pq.front() << " " << pq.back() << endl;
    pq.pop(); cout << pq.empty() << endl;
}
void Binaryrepr(int n) {
    deque <string> dq;
    dq.push_back("1");
    for(int i = 1; i <= n; i++) {
        cout << dq.front() << endl;
        string tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp + "0");
        dq.push_back(tmp + "1");
    }
    queue <string> q; q.push("1");
    for(int i = 1; i <= n; i++) {
        cout << q.front() << endl;
        string tmp = q.front(); q.pop();
        q.push(tmp + "0"); q.push(tmp + "1");
    }
}
void ladderarr(int n) {
    deque <int> ladder;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ladder.push_back(x);
    }
    sort(ladder.begin(), ladder.end());
    while(!ladder.empty()) {
        cout << ladder.front() << " "; ladder.pop_front();
    }
    cout << endl;
}
void print(deque <int> dq) {
    deque <int> ::iterator it = dq.begin();
    while(it != dq.end()) {
        cout << *it << " "; it++;
    }
}
void deque() {
    deque <int> dq;
    for(int i = 1; i <= 10; i++) {
        dq.push_front(i * 2); dq.push_back(i * 3);
    }
    cout << dq.size() << " " << dq.max_size() << " " << dq.at(3) << endl;
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_front(); dq.pop_back();
    cout << *max_element(dq.begin(), dq.end()) << endl;
    cout << *min_element(dq.begin(), dq.end());
    reverse(dq.begin(), dq.end());
}
void print(priority_queue<int>& pq)
{
    priority_queue<int> temp=pq;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
}
void print(priority_queue <int> pq) {
    priority_queue <int> tmp = pq;
    while(!tmp.empty()) {
        cout << tmp.top() << " "; tmp.pop();
    } cout << endl;
}
void priorityQ() {
    int dig; string ing;
    priority_queue <int> p;
    priority_queue <string> q;
    dig = 20; cout << dig << endl;
    p.push(dig); dig = 30; p.push(dig);
    cout << p.top() << endl;
    
    ing = "Hello"; cout << ing << endl;
    q.push(ing); ing = "Hi"; q.push(ing);
    cout << q.top() << endl;
    
    priority_queue <int> x;
    int arr[6] = {10, 11, 12, 13, 14, 15};
    for(int i = 0; i < 6; i++) pq.push(arr[i]);
    x.swap(p);
    cout << x.size() << " " << x.top() << endl;
    x.pop();
    x = priority_queue <int> ();
    for(int i = 15; i <= 22; i++) x.emplace(i);
    swap(p, x);
    priority_queue <int, vector <int>,
    greater <int>> gq(arr, arr + 6);
    while(!gq.empty()) {
        cout << gq.top() << " ";
        gq.pop();
    }
}
/*                SET                */
#include<bits/stdc++.h>
using namespace std;
void set(){
    unordered_set <string> ust {"Hey", "We", "Are"};
    ust.reserve(2); ust.rehash(9);
    ust.erase("We"); ust.insert("ewr");
    ust.erase(ust.find("Hey"), ust.end());
    ust.insert("code"); ust.insert("in");
    ust.insert("c++"); ust.insert("is");
    ust.insert({"fourth", "sixth" });
    bool res = ust.key_eq()("a", "A");
    if(res == 1) cout << "case insensitive";
    else cout << "case sensetive";
    
    unordered_set <int> st;
    cout << st.insert(1).second << " " << *(st.insert(1) .first) << endl;
    cout << st.insert(2).second << " " << *(st.insert(2) .first) << endl;
    unordered_set <int> et;
    for(int i = 1; i < 12; i++) et.insert(i);
    cout << et.size() << " " << et.bucket_count() << " ";
    cout << et.load_factor() << " " << et.max_size() << " " << et.max_load_factor() << endl;
    int i = 0;
    while(i < 25) {
        st.emplace(i); i += 5;
    }
    if(st.count(22) == 1) cout << "22 exits";
    for(auto it = st.begin(); it != st.end(); it++)
        cout << (*it) << " " << st.bucket(*it);
    set <int, greater <int>> lay;
    for(int i = 1; i <= 11; i++) lay.insert(i);
    set <int> x(lay.begin(), lay.end());
    x.erase(x.begin(), x.find(7));
    set <int, greater <int>> ::iterator it;
    for(it = x.begin(); it != x.end(); ++it) cout << *it << " ";
    cout << endl;
    cout << x.erase(8) << " " << x.size() << endl;
    cout << *x.lower_bound(8) << " " << *x.upper_bound(8) << endl;
    cout << *lay.lower_bound(8) << " " << *lay.upper_bound(8) << endl;
    if(x.find(2) != x.end()) cout << "Found";
    else cout << "Not Found";
    set <int> y, unionset
    for(int i = 20; i <= 12; i--) y.insert(i);
    for(int val : x) unionset.insert(val);
    for(int val : y) unionset.insert(val);
    for(int val : unionset) cout << val << " ";
}
typedef unordered_multiset <int> ::iterator it;
void multiset() {
    multiset <int> mst({15, 13, 11, 9, 8, 7});
    for(int i = 1; i <= 13; i++) mst.insert(i);
    if(!mst.empty()) cout << "Not Empty";
    else cout << "Empty";
    if(mst.count(5) != mst.end()) cout << "contained element";
    cout << mst.count(5) << " " << mst.size() << endl;
    mst.erase(4); mst.erase(mst.find(7));
    if(mst.find(7) != mst.end()) cout << "7 exists";
    mst.clear();
    
    unordered_multiset <int> ums ({1, 3, 1, 7, 2, 3, 4, 1, 6});
    if(ums.empty()) cout << "Empty";
    else cout << "Not empty";
    cout << ums.size();
    ums.insert(7);
    int val = 3; cout << ums.count(val);
    if(ums.find(val) != ums.end()) cout << "contained";
    else cout << "not contained";
    pair <it, it> ert = ums.equal_range(val);
    if(ert.first != ert.second) cout << val << " appeared atleast once";
    //erase one entry
    auto it = ums.find(val);
    if(it != ums.end()) ums.erase(it);
    ums.clear();
}
bool issubset(int *arr, int *ray, int n, int m) {
    unordered_set <int> elem;
    for(int i = 0; i < n; i++) elem.insert(arr[i]);
    for(int i = 0; i < m; i++) {
        if(elem.find(ray[i]) == elem.end()) return false;
    }
    return true;
}
//find length of the shortest chain transformation from source to target
int shortestchain(string start, string trg, set <string> lay) {
   /* set <string> st;
    st.insert("poon"); st.insert("plee");
    st.insert("same"); st.insert("poie");
    st.insert("plie"); st.insert("poin");
    st.insert("plea");
    string start = "toon", target = "plea"; */
    if(start == trg) return 0;
    map <string, vector <string>> mp;
    for(int i = 0; i < start.size(); i++) {
        string str = start.substr(0, i) + "*" + start.substr(i + 1);
        mp[str].push_back(start);
    }
    for(auto it = lay.begin(); it != lay.end(); ++it) {
        string word = *it;
        for(int j = 0; j < word.size(); j++) {
            string str = word.substr(0, j) + "*" + word.substr(j + 1);
            mp[str].push_back(word);
        }
    }
    queue <pair <string, int>> q;
    map <string, int> visited;
    q.push(make_pair(start, 1));
    visited[start] = 1;
    while(!q.empty()) {
        pair <string, int> p = q.front();
        q.pop();
        string word = p.first;
        int dist = p.second;
        if(word == target) return dist;
        for(int i = 0; i < word.size(); i++) {
            string str = word.substr(0, i) + "*" + word.substr(i + 1);
            vector <string> vec = mp[str];
            for(int j = 0; j < vec.size(); j++) {
                if(visited[vec[j]] == 0) {
                    visited[vec[j]] = 1;
                    q.push(make_pair(vec[j], dist + 1));
                }
            }
        }
    }
    /*
    if(start == trg) return 0;
    if(lay.find(trg) == lay.end()) return 0;
    int lev = 0, len = start.size();
    queue <string> Q; Q.push(start);
    while (!Q.empty()) {
        ++lev
        int sizeofQ = Q.size();
        for (int i = 0; i < sizeofQ; ++i) {
            string word = Q.front();
            Q.pop();
            for (int pos = 0; pos < len; ++pos) {
                char orig_char = word[pos];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[pos] = c;
                    if (word == trg)
                        return lev + 1;
                    if (lay.find(word) == lay.end())
                        continue;
                    lay.erase(word);
                    lay.push(word);
                }
                word[pos] = orig_char;
            }
        }
    } */
}
void pair(int n) {
    vector <pair <pair <string, string>, int >> pr;
    for(int i = 0; i < n; i++) {
        string first, last; int age;
        cin >> first >> last >> age;
        pr.push_back({{first, last}, age});
    }
    for(int i = 0; i < n; i++) 
        cout << pr[i].first.first << " " << pr[i].first.second << " " << pr[i].second << endl;
    
    pair <string, double> Q("abcdef", 1.23);
    pair <string, double> R;
    R = make_pair("Abcdefg", 4.56);
    cout << Q.first + R.first << " " << Q.second + R.second << endl;
    swap(Q, R);
    
    pair <int, int> qr = {1, 3};
    int a, b; tie(a, b) = qr;
    // int a, b; tie(a, ignore) = qr;
    cout << a << " " << b << endl;
    
    pair <int, pair <int, char>> rs = {3, {4, 'a'}};
    int x, y; char z;
    tie(x, ignore) = rs
    tie(y, z) = rs.second;
    cout << x << " " << y << " " << z << endl;
}

