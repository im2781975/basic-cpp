#include<bits/stdc++.h>
using namespace std;
// find the difference b/w left & right smaller element of every element in array 
int MaxDiff(int arr[], int n) {
    stack <int> s;
    vector <int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) s.pop();
        left[i] = s.empty() ? 0 : s.top();
        s.push(arr[i]);
    }
    while (!s.empty()) s.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() >= arr[i]) s.pop();
        right[i] = s.empty() ? 0 : s.top();
        s.push(arr[i]);
    }
    int maxDiff = 0;
    for (int i = 0; i < n; i++)
        maxDiff = max(maxDiff, abs(left[i] - right[i]));
    return maxDiff;
}
// find index of closing bracket for given opening bracket.
void test(string expr, int idx){
    // test("[ABC[23]][89]", 0); 
    if(expr[idx]!='['){
        cout << expr << " " << idx << endl;
        return;
    }
    stack <int> st;
    for(int i = idx; i < expr.length(); i++){
        if(expr[i] == '[') st.push(expr[i]);
        else if(expr[i] == ']'){
            st.pop();
            if(st.empty()){
                cout << expr << " " << idx << " " << i << endl;
                return;
            }
        }
    }
    cout << expr << " " << idx << endl;
}
