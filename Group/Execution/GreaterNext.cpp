#include<bits/stdc++.h>
using namespace std;
bool Isoperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%') return true;
    return false;
}
bool Isoperand(char ch) {
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) return true;
    return false;
}
string prefixToinfix(string str) {
    // string str = "*-A/BC-/AKL";
    stack <string> st;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(Isoperator(str[i])) {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x +  ")");
        }
        else st.push(string(1, str[i]));
    }
    return st.top();
}
string postfixToinfix(string str) {
    // string str ="ab*c+";
    stack <string> st;
    for(int i = 0; i < str.length(); i++) {
        if(Isoperand(str[i])) st.push(string(1, str[i]));
        else {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push("(" + y + str[i] + x + );
        }
    }
    return st.top();
}
bool Isoperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
    return false;
}
string prefixTopostfix(string str) {
    // string str = "*-A/BC-/AKL";
    stack <string> st;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(Isoperator(str[i])) {
            if(st.size() < 2) return "Invalid";
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push(x + y + str[i]);
        }
        else st.push(string(1, str[i]));
    }
    return st.top();
}
string postfixToprefix(string str) {
    stack <string> st;
    for(int i = 0; i < str.size(); i++) {
        if(Isoperator(str[i])) {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            st.push(str[i] + y + x);
        }
        else st.push(string(1, str[i]));
    }
    string res = "";
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
// Function to return precedence of operators
int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}
bool Isoperator(char ch){
    return (!isalpha(ch) && !isdigit(ch));
}
void infixTopostfix(string str) {
    // string str = "a+b*(c^d-e)^(f+g*h)-i"
    stack <char> st; string res;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // if(isalpha(ch) || isdigit(ch)) res += ch;
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) res += ch;
        else if(ch == '(') st.push(ch);
        else if(ch == ')') {
            while(st.top() != '(') {
                res += st.top(); st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && priority(ch) <= priority(st.top())) {
                res += st.top(); st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
string infixToprefix(string str) {
    // string str = "x+y*z/w+u" 
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] == '(';
    }
    string prefix = infixTopostfix(str);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
// evaluate value of a postfix expression having multiple digit operands
int postfix(string str) {
    stack <int> st;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') continue;
        if(isdigit(str[i])) {
            int num = 0;
            while(isdigit(str[i])) {
                num = num * 10 + (str[i++] - '0');
            }
            i--;
            if(st.size() < 1) return -1;
            st.push(num);
        }
        else {
            if(st.size() < 2) return -1;
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            switch(str[i]) {
                case '+' : st.push(x + y); break;
                case '-' : st.push(y - x); break;
                case '*' : st.push(x * y); break;
                case '/' : st.push(y / x); break;
            }
        }
    }
    if(st.size() != 1) return -1;
    return st.top();
}
// Function to find the cross over point (the point before which elements are 
// smaller than or equal to x and after which greater than x)
int findcross(int *arr, int low, int high, int x) {
    if(arr[high] <= x) return high;
    if(arr[low] > x) return low;
    int mid = (low + high) / 2;
    if(mid < high && arr[mid] <= x && arr[mid + 1] > x) return mid;
    if(arr[mid] <= x) return findcross(arr, mid + 1, high, x);
    else return findcross(arr, low, mid - 1, x);
}
// print next greater number of Q queries
void nextGreater(int *arr, int *next, int n) { 
    // int nxt[4]; nextGreater(arr, nxt, n);
    // cout << Query(arr, nxt, 4, 3) << " ";
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            next[st.top()] = i; st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        next[st.top()] = -1; st.pop();
    }
}
int Query(int *arr, int *next, int idx) {
    return next[idx] == -1 ? -1 : arr[next[idx]];
}
void nextgreater(int *arr, int *next, int n, int order) {
    stack <int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && (order == 'G'? arr[st.top()] <= arr[i] : arr[st.top()] >= arr[i]))
            st.pop();
        next[i] = st.empty() ?  -1 : st.top();
        st.push(i);
    }
}
// find Right smaller element of next greater element
void miniOfnextTall(int *arr, int n) {
    int NG[n], RS[n]; // next greater right smaller
    nextgreater(arr, NG, n, 'G');
    nextgreater(arr, RS, n, 'S');
    for(int i = 0; i < n; i++) {
        int idx = -1;
        if(NG[i] != -1 && RS[NG[i]] != -1)
            idx = RS[NG[i]];
    }
    cout << (idx == -1 ? -1 : arr[idx]) << " ";
}
//print next greater number of Q queries 
void nextGreater(int *arr, int *Query, int n, int q) {
    for(int i = 0; i < q; i++) {
        bool found = false
        int k = Query[i];
        for(int j = k + 1; j < n; j++) {
            if(arr[j] > arr[k]) {
                cout << arr[j] << " ";
                found = true; break;
            }
        }
        if(!found) cout << -1 << endl;
    }
}
vector <int> nextGreater(vector <int> arr) {
    vector <int> res; stack <int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        res.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end()); return res;
}
void nextGreaterfreq(int *arr, int *res, int n) {
    unordered_map <int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    stack <pair <int, int>> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().second <= freq[arr[i]]) st.pop();
        res[i] = st.empty() ? -1 : st.top().first;
        st.push({arr[i], freq[arr[i]]});
    }
}
void nextGreater(int *arr, int n) {
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            arr[st.top()] = arr[i]; st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        arr[st.top()] = -1; st.pop();
    }
}
void nextGreater(int *arr, int n) {
    stack <int> st; st.push(arr[0]);
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(arr[i]); continue;
        }
        while(!st.empty() && st.top() < arr[i]) {
            cout << st.top() << " " << arr[i] << endl; st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        cout << st.top() << " " << -1 << endl; st.pop();
    }
}
void nextGreater(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int next = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                next = arr[j]; break;
            }
        }
        cout << arr[i] << " " << next << endl;
    }
}

