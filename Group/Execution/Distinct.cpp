#include<bits/stdc++.h>
using namespace std;
using namespace std;
void distinct(vector <int> vec) {
    vector <int> unique, dup;
    for(int i = 0; i < vec.size(); i++) {
        if(find(unique.begin(), unique.end(), vec[i]) == unique.end())
            unique.push_back(vec[i]);
        else dup.push_back(vec[i]);
    }
    for(int i = 0; i < unique.size(); i++)
        cout << unique[i] << " ";
    cout << endl;
}
void printDup(int *arr, int n) {
    unordered_set <int> intset, dup;
    for (int i = 0; i < n; i++) {
        if (intset.find(arr[i]) == intset.end())
            intset.insert(arr[i]);
        else dup.insert(arr[i]);
    }
    unordered_set <int> ::iterator it;
    for(it = dup.begin(); it != dup.end(); it++) cout << *it << " ";
    cout << endl;
}
//find first duplicate
void finddup(vector <int> vec) {
    int n = vec.size();
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
        if(mp.find(vec[i]) != mp.end()) {
            cout << vec[i] << " " << mp[vec[i]] << endl;
            break;
        }
        mp[vec[i]] = i;
    }
}
// counts the minimum number of operations needed to make two arrays equal
int digit(int x) {
    int cnt = 0;
    while(x != 0) {
        x /= 10; cnt++;
    }
    return cnt;
}
void minop(vector <int> vec, vector <int> tor){
    int n = vec.size();
    priority_queue <int> x, y;
    for(int i = 0; i < n; i++) x.push(vec[i]);
    for(int i = 0; i < n; i++) y.push(tor[i]);
    int res = 0;
    while(x.size() && y.size()) {
        int a = x.top(), b = y.top();
        if(a == b) {
            x.pop(); y.pop(); continue;
        }
        res++;
        if(a > b) {
            x.pop(); x.push(digit(a));
        }
        else {
            y.pop(); y.push(digit(b));
        }
    }
    cout << res;
}
// Find the smallest signal range needed so every house is within range of at least one transmitter placed on a house.
void smallrange(vector <int> &vec, int n){
    bool flag = true;
    int tmp = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(vec[i] < vec[i - 1]) {
            flag = false; break;
        }
    }
    if(flag == true){
        for(int i = 1; i < n; i++)
            tmp = min(tmp, vec[i] - vec[i - 1]);
        cout << (tmp/2) + 1;
    }
    else cout << 0;
}
void pattern(vector <int> vec, int n) {
    int sum = 0;
    while(n > 0) {
        sum += n;
        vec.push(sum); n /= 2;
    }
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}
void cntcoin(vector <int> coin, int n, int x) {
    vector <int> cnt(x + 1, INT_MAX);
    cnt[0] = 0;
    for(int i = 0; i <= x; ++i) {
        for(int j = 0; j < coin.size(); j++) {
            if(i - coin[j] >= 0)
                cnt[i] = min(cnt[i], cnt[i - coin[j]] + 1);
        }
    }
    cout << cnt[x];
}
