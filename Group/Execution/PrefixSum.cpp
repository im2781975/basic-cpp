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
int main(){
    vector<int> arr{ 10, -10, 20, -40 };
    int k = 6; cout << nthsum(arr, k);
}
