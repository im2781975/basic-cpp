#include<bits/stdc++.h>
using namespace std;
int findMax(int arr[], int n) {
    if(n == 1) return arr[0];
    else {
        int maxInRest = findMax(arr, size - 1);
        return maxInRest > arr[size - 1] ? maxInRest : arr[size - 1];
    }
}
// Odd occuring element
int findOdd(int arr[], int n){
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
void array(int *arr, int n) {
    if (n == 0) return;
    array(arr, n - 1);
    cout << arr[n - 1] << " ";
}
// For each query, print the sum of elements between indices l and r.
void sumrange(vector <int> vec, int n) {
    vector <int> pref(n + 1);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + vec[i];
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }
}
using namespace std;
void func(int n) {
    if (n == 1) cout << "One";
    else if (n == 2) cout << "Two";
    else if (n == 3) cout << "Three";
    else if (n == 4) cout << "Four";
    else if (n == 5) cout << "Five";
    else if (n == 6) cout << "Six";
    else if (n == 7) cout << "Seven";
    else if (n == 8) cout << "Eight";
    else cout << "Nine";
}
void tion(int n) {
    if (n == 1) cout << "Ten";
    else if (n == 2) cout << "Twenty";
    else if (n == 3) cout << "Thirty";
    else if (n == 4) cout << "Forty";
    else if (n == 5) cout << "Fifty";
    else if (n == 6) cout << "Sixty";
    else if (n == 7) cout << "Seventy";
    else if (n == 8) cout << "Eighty";
    else cout << "Nine";
}
int main() {
    vector <int> vec;
    int n; cin >> n;
    while(n != 0) {
        int x = n % 10; n /= 10;
        vec.push_back(x);
    }
    for(int i = vec.size() - 1; i >= 0; i--) {
        if(vec[i] == 0 && i == 0) cout << "zero";
        else if(i == 0) func(vec[i]);
        else if(i == 1) tion(vec[i]);
    }
}
