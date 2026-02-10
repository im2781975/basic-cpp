#include<bits/stdc++.h>
using namespace std;
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


