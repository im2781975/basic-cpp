#include<bits/stdc++.h>
// reverse a string using stack
using namespace std;
string rev(string str) {
    stack <char> st;
    for(char c : str) st.push(c);
    string result;
    while (!st.empty()) {
    result += st.top(); st.pop();
    }
    return result;
}
void stacksort(stack <int> st) {
    stack <int> tmp;
    while(!st.empty()) {
        int x = st.top(); st.pop();
        while(!tmp.empty() && tmp.top() > x) {
            st.push(tmp.top()); tmp.pop();
        }
        st.push(x);
    }
    while(!tmp.empty()) {
        st.push(tmp.top()); tmp.pop();
    }
}
void stackreverse(stack <int> st) {
    stack <int> tmp;
    while(!st.empty()) {
        int x = st.top(); st.pop(); tmp.push(x);
    }
    while(!tmp.empty()) {
        int x = tmp.top(); tmp.pop(); st.push(x);
    }
}
void decreasesize(stack <int> st) {
    int cap = st.size(), sz = 0;
    stack <int> tmp;
    while(!st.empty()) {
        tmp.push(st.top()); st.pop(); sz++;
    }
    if(sz < cap / 2) {
        int newcap = cap / 2;
        stack <int> newst;
        while(!tmp.empty() && newst.size() < newcap) {
            newst.push(tmp.top()); tmp.pop();
        }
        while(!newst.empty()) {
            st.push(newst.top()); newst.pop();
        }
    }
}
