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

