#include<bits/stdc++.h>
using namespace std;
void grid() {
    int sum = 0, res = 0, grid[10][10] = {0};
    for(int i = 0; i < 10; i++) {
        sum += i; grid[i][i] = sum;
    }
    for(int j = 0; j < 10; j++) {
        res += 2 * j; cout << res << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
void recur(int n) {
    if(n > 0) {
        recur(n - 1); cout << n << " ";
        recur(n - 2);
    }
}
void func(int l, int r) {
    int mid = l + (r - l) >> 1;
    for(int i = l; i <= r; i++) cout << i << " ";
    cout << endl;
    if(l < r) {
        func(l, mid); 
        func(mid + 1, r);
    }
}
void recurs() {
    int n; cin >> n; func(0, n - 1);
    for(int i = 1; i < n / 2; i++) {
        for(int j = 1; j <= n; j++)
            cout << i << " " << j << endl;
    }
}
// find first idx of string
void Idxstr() {
    map <string, int> mp;
    int n; cin >> n; string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(mp.find(str) == mp.end()) cout << -1 << endl;
        else cout << mp[str] << endl;
        mp[str] = i;
    }
}
//valid bracket sequence
void seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else {
            if(ch == ')' && st.top() == '(') st.pop();
            else if(ch == '}' && st.top() == '{') st.pop();
            else if(ch == ']' && st.top() == '[') st.pop();
            else {
                cout << "Invalid"; return 0;
            }
        }
    }
    if(st.empty()) cout << "valid";
    else cout << "Not valid";
}
bool seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(st.empty()) return false;
            char tp = st.top(); st.pop();
            if((ch == ')' && tp != '(') || (ch == ']' && tp != '[') || (ch == '}' && tp != '{')) return false;
        }
    }
    return st.empty();
}
bool seqbrack(string str) {
    stack <char> st;
    for(int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        switch(ch) {
            case '(' :
            case '{' :
            case '[' :
                st.push(ch); break;
            case ')' :
            case '}' :
            case ']' :
                if(st.empty() || (ch == ')' && st.top() != '(' ) || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '[')) return false;
                st.pop(); break;
        }
    }
    return st.empty();
}
void showOccur(string str) {
    map <char, vec <int>> mp;
    for(int i = 0; i < str.size(); i++)
        mp[str[i]].push_back(i);
    for(auto it : mp) {
        char ch = it.first; cout << ch << " ";
        vector <int> vec = it.second;
        for(auto val : vec) cout << val << " ";
    }
}
bool IsPalindrome(string str) {
    deque <char> dq;
    for(int i = 0; i < dq.size(); i++) 
        dq.push_back(str[i]);
    while(dq.size() > 1) {
        if(dq.front() != dq.back()) return false;
        dq.pop_front(); dq.pop_back();
    }
    return false;
}
bool caselower(char a, char b) {
    return (tolower(a) <= tolower(b));
}
bool ifsorted(string str) {
    return is_sorted(str.begin(), str.end(), caselower);
}
void maxOccur(string str) {
    map <string, int> mp;
    istringstream x(str);
    string word;
    while(x >> word) {
        for(char &c : word)
            c = ispunct(c) ? ' ' : tolower(c);
        mp[word]++;
    }
    auto it = max_element(mp.begin(), mp.end(), [](const auto a, const auto b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    });
    cout << it -> second << " " << it -> first;
}
void findDup(vector <int> vec) {
    map <int, int> mp;
    for(int i = 0; i < vec.size(); i++) {
        if(mp.find(vec[i]) != mp.end())
            cout << vec[i] << " " << mp[vec[i]]; break;
            
        mp[vec[i]] = i;
    }
}
string rev(string str) {
    stack <char> st;
    for(int i = 0; i < str.length(); i++) st.push(str[i]);
    string rev = "", tmp = "";
    while(!st.empty()) {
        if(isalpha(st.top())) tmp += st.top();
        else {
            rev = " " + tmp + rev; tmp = "";
        }
        st.pop();
    }
    if(!tmp.empty()) rev = tmp + rev;
    return rev;
}

