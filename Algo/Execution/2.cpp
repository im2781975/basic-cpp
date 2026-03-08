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

