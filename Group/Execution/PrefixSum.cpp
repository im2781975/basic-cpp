#include<bits/stdc++.h>
using namespace std;
// prefix sum
int nthsum(vector <int> &vec, int k){
    int n = vec.size(); 
    vector <int> res(n + 1); res[0] = 0;
    for(int i = 1; i <= n; i++)
        res[i] = res[i - 1] + vec[i - 1];
    vector <int> tor;
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++)
            tor.push_back(res[j] - res[i]);
    }
    sort(res.begin(), res.end(), greater <int> ());
    return res[k - 1];
}
// find the K-th largest sum of subarray
int nthsum(int *arr, int n, int k){
    vector <int> res;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            res.push_back(sum);
        }
    }
    sort(res.begin(), res.end(), greater <int> ());
    return res[k - 1];
}
int nthsum(int *arr, int n, int k){
    int fix[n + 1];
    fix[0] = 0; fix[1] = arr[0];
    for(int i = 2; i <= n; i++)
        fix[i] = fix[i - 1] + arr[i - 1];
    priority_queue <int, vector <int>, greater <int>> Q;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int x = fix[j] - fix[i - 1];
            if(Q.size() < k) Q.push(x);
            else{
                if(Q.top() < x) {
                    Q.pop(); Q.push(x);
                }
            }
        }
    }
    return Q.top();
}
bool Issorted(int *arr, int n) {
    if(n == 0 || n == 1) return true;
    //return arr[n - 1] >= arr[n - 2] && Issorted(arr, n - 1);
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}
int main(){
    vector<int> arr{ 10, -10, 20, -40 };
    int k = 6; cout << nthsum(arr, k);
    int arr[] = { 20, -5, -1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2; cout << nthsum(arr, n, key);
    
    vector <int> vec = {1, 2, 3};
    vector <int> ::iterator it;
    for(it = vec.begin(); it != vec.end(); ++it) {
        if(it == vec.begin()) it = vec. insert(it, 5);
        if(it == vec.begin() + 1) it = vec. erase(it);
    }
    for(auto it = vec.begin(); it != vec.end(); ++it) cout << *it << " ";
    cout << endl;
    for (int i = 0; i < 10; i++) vec.push_back(i);
    vec.insert(vec.begin() + 1, 100);
    vec.erase(vec.begin() + 2);
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
}
