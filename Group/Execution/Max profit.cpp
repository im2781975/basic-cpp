#include<bits/stdc++.h>
using namespace std;
// Returns maximum profit with two transactions on a given list of stock prices, price[]
int maxprofit(int *prices, int n){
    vector <vector <vector <int>>> dp(n, vector <vector <int>>(2, vector <int>(3, -1)));
    return func(0, 0, prices, dp, 2, n);
    // return func(0, 0, prices, 2, n);
}
int func(int idx, int buy, int *prices, int cap, int n){
    if(cap == 0 || idx == n) return 0;
    int profit = 0;
    if(buy == 0)
        profit = max(-prices[idx] + func(idx + 1, 1, prices, cap, n), func(idx + 1, 0, prices, cap, n);
    
    else
        profit = max (prices[idx] + func(idx + 1, 0, prices, cap - 1, n), func(idx + 1, 1, prices, cap, n));
}
int func(int idx, int buy, int *prices, vector <vector <vector<int>>> dp, int cap, int n){
    if(cap == 0 || idx == n) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    int profit = 0;
    if(buy == 0)
        dp[idx][buy][cap] = profit = max(-prices[idx] + func(idx + 1, 1, prices, dp, cap, n), func(idx + 1, 0, prices, dp, cap, n);
    
    else
        dp[idx][buy][cap] = profit = max (prices[idx] + func(idx + 1, 0, prices, dp, cap - 1, n),func(idx + 1, 1, prices, dp, cap, n));
}
int maxprofit(int *arr,int n) {
    int buy1 = buy2 = INT_MIN;
    int sell1 = sell2 = 0;
    for(int i = 0; i < n; i++){
        buy1 = max(buy1, -arr[i]);
        sell1 = max(sell1, buy1 + arr[i]);
        buy2 = max(buy2, sell1 - arr[i]);
        sell2 = max(sell2, buy2 + arr[i]);
    }
    return sell2;
}
int maxProfit(int price[], int n){
    // Create profit array & initialize it as 0
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] > max_price)
            max_price = price[i];
     profit[i] = max(profit[i + 1], max_price - price[i]);
    }
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        if (price[i] < min_price)
            min_price = price[i];
        // Maximum profit is maximum of: previous maximum,profit[i-1]
        // -> (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
    delete[] profit;
    return result;
}
//length sub array
int minlen(vector <int> &vec){
    vector <int> tmp = vec;
    sort(tmp.begin(), tmp.end());
    int start = 0, end = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] != tmp[i]){
            start = i; break;
        }
    }
    for(int i = vec.size() - 1; i >= 0; i--){
        if(vec[i] != tmp[i]){
            end = i; break;
        }
    }
    return(end - start + 1);
}
//LCM QUERIES
int gcd(int a, int b){
    int (b == 0) return a;
    return(b, a % b);
}
int lcm(int a, int b){ return a * b / gcd(a, b);
vector <int> QueryLCM(vector <int> &vec, vector <pair <int, int>> &query){
    vector <int> res;
    for(const auto &q : query){
        int l = q.first;
        int r = q.second;
        int val = vec[l];
        for(int i = l + 1; i <= r; i++)
            val = lcm(val, vec[i]);
        res.push_back(val);
    }
    return res;
}
void downtopbound(vector <int> &vec, int val){
    cout << lower_bound(vec.begin(), vec.end(), val) - vec.begin();
    cout << upper_bound(vec.begin(), vec.end(), val) - vec.begin();
}
void findIntersection(vector <int> vec, vector <int> tor){
    unordered_set <int> st(vec.begin(), vec.end());
    vector <int> res;
    for(int i = 0; i < tor.size(); i++){
        if(st.find(tor[i]) != st.end())
            res.push_back(tor[i]);
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
//check whether permutation of two arrays satisfy the condition a[i] + b[i] >= k.
bool checkcondition(int *arr, int *ray, int n, int k){
    sort(arr, arr + n); sort(ray, ray + n, greater <int> ());
    for(int i = 0; i < n; i++){
        if(arr[i] + ray[i] < k) return false;
    }
    return true;
}
