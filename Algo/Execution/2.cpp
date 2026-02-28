#include <bits/stdc++.h>
using namespace std;
// redundant parentheses from algebraic expressions by tracking sign propagation through nested parentheses using a stack.
string simplify(string str) {
    int len = str.length();
    string res = ""; res.reserve(len);
    int i = 0;
    stack <int> st; st.push(0);
    while(i < len) {
        if(str[i] == '(') {
            if(i > 0 && str[i - 1] == '-')
                st.push(1 - st.top());
            else st.push(st.top());
            i++; continue;
        }
        else if(str[i] == ')') {
            st.pop(); i++;
            continue;
        }
        else if(str[i] == '+' || str[i] == '-') {
            i++; continue;
        }
        res += str[i++];
    }
    return res;
}
//Given Array of size n and a number k, find all elements that appear more than n/k times
void moreThanNdKSimple(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto& p : freq) {
        if (p.second > n/k) {
            cout << "Number: " << p.first 
                 << " Count: " << p.second << endl;
        }
    }
}
void moreThanNdK(int arr[], int n, int k) {
    if (k <= 1) return;
    vector<int> candidates(k - 1, -1);  
    vector<int> counts(k - 1, 0);
    for (int i = 0; i < n; i++) {
        bool found = false;
        
        for (int j = 0; j < k-1; j++) {
            if (candidates[j] == arr[i]) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            bool placed = false;
            for (int j = 0; j < k-1; j++) {
                if (counts[j] == 0) {
                    candidates[j] = arr[i];
                    counts[j] = 1;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                for (int j = 0; j < k-1; j++) {
                    counts[j]--;
                }
            }
        }
    }
    for (int i = 0; i < k-1; i++) {
        if (candidates[i] == -1) continue;
        
        int actualCount = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == candidates[i]) actualCount++;
        }
        
        if (actualCount > n/k) {
            cout << "Number: " << candidates[i] 
                 << " Count: " << actualCount << endl;
        }
    }
}
// Maximum Length of Valid (Balanced) Bracket Subsequence in a Range
void buildBalancedArrays(int open[], int close[], string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                open[st.top()] = 1;
                close[i] = 1; 
                st.pop();
            }
        }
    }
    for (int i = 1; i < s.size(); i++) {
        open[i] += open[i-1];
        close[i] += close[i-1];
    }
}
int maxBalancedLength(int open[], int close[], int L, int R) {
    int balanced = close[R] - close[L-1];
    if (open[L - 1] == open[L]) {
        return balanced * 2;
    }
    return (balanced + 1) * 2;
}
int main() {
    string s = "())(())(())(";
    int n = s.size();
    vector<int> open(n), close(n);
    buildBalancedArrays(open.data(), close.data(), s);
    
    cout << "Max balanced in [5,11]: " << maxBalancedLength(open.data(), close.data(), 5, 11) << endl;
    cout << "Max balanced in [4,5]:  " << maxBalancedLength(open.data(), close.data(), 4, 5) << endl;
    cout << "Max balanced in [1,5]:  " << maxBalancedLength(open.data(), close.data(), 1, 5) << endl;
}
