#include<bits/stdc++.h>
using namespace std;
//find k numbers with most occurrences in the given array
void nfreq(int *arr, int n, int k){
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    vector <vector <int>> freq(n + 1);
    for(auto val : mp)
        freq[val.second].push_back(val.first);
    int cnt = 0;
    for(int i = freq.size() - 1; i >= 0; i--){
        if(freq[i].size() > 1)
            sort(freq[i].begin(), freq[i].end(), greater <int> ());
        for(auto val : freq[i]){
            cnt++; cout << val << " ";
            if(cnt >= k) return;
        }
    }
    return;
}
bool cmp(pair <int, int> x, pair <int, int> y){
    if(x.second == y.second) return x.first > y.first;
    return x.second > y.second;
}
void nfreq(int *arr, int n, int k){
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    vector <pair <int, int>> freq(mp.begin(), mp.end());
    sort(freq.begin(), freq.end(), cmp);
    for(int i = 0; i < k; i++) cout << freq[i].first << " ";
}
vector <int> nfreq(vector <int> vec, int k, vector <int> res){
    unordered_map <int, int> mp;
    for(int i = 0; i < vec.size(); ++i) mp[vec[i]]++;
    vector <pair <int, int >> freq;
    for(auto it = mp.begin(); it!= mp.end(); ++it)
        freq.push_back({it -> second, it -> first});
    nth_element(freq.begin(), freq.end() - k, freq.end());
    transform(freq.begin() - k, freq.end(), res.begin(), [](pair <int, int> vec){ return vec.second;});
    return res;
}
//count all possible triangles 
int cntTriangle(int *arr, int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j]
                    && arr[k] + arr[j] > arr[i]) cnt++;
            }
        }
    }
    return cnt;
}
int cntTriangle(int *arr, int n){
    sort(arr, arr + n); int cnt = 0;
    for(int i = 0; i < n - 2; i++){
        int k = i + 2;
        for(int j = i; j < n; j++){
            while(k < n && arr[i] + arr[j] > arr[k]) k++;
            if(k > j) cnt += k - j + 1;
        }
    }
    return cnt;
}
int cntTriangle(vector <int> vec){
    int n = vec.size(), cnt = 0;
    sort(vec.begin(), vec.end());
    for(int i = n - 1; i >= 1; i--){
        int l = 0, r = i - 1;
        while(l < r){
            if(arr[l] + arr[r] > arr[i]) {
                cnt += r - l;
                r--;
            }
            else    l++;
        }
    }
    cout << cnt;
}
int findXOR(int *arr, int n) { 
    // Do XOR of all elements and return 
    int res = arr[0]; 
    for (int i = 1; i < n; i++) 
        res = res ^ arr[i]; 
    return res; 
} 
//find the array element that appears only once 
int occuronce(int *arr, int n) { 
    for (int i = 0; i < n; i++) { 
        int count = 0; 
        for (int j = 0; j < n; j++) { 
            if (arr[i] == arr[j])  
                count++; 
        }
        if (count == 1) return arr[i]; 
    } 
    return -1; 
}
void occuronce(int *arr, int n){ 
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++) mp[arr[i]]++;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it -> second == 1) cout << it -> first << " ";
    }
} 
#include<bits/stdc++.h>
using namespace std;
int cntmatch(vector <int> vec, int l, int r, int trg) {
    int cnt = 0;
    int mid = l + (r - l) / 2;
    if(r - l < 2) {
        if(vec[l] == trg) cnt++;
        if(vec[r] == trg && l != r) cnt++;
        return cnt;
    }
    else if(vec[mid] == trg)
        return cntmatch(vec, l, mid - 1, trg) + 1 + cntmatch(vec, mid + 1, r, trg);
    else if(vec[mid] < trg) return cntmatch(vec, mid + 1, r, trg);
    else return cntmatch(vec, l, mid - 1, trg);
}
int cntoccur(vector <int> &vec, int l, int r, int trg) {
    if(l > r) return 0;
    int mid = l + (r - l) / 2;
    if (vec[mid] == trg) {
        int cnt = 1;
        cnt += cntoccur(vec, l, mid - 1, trg);
        cnt += cntoccur(vec, mid + 1, r, trg);
        return cnt;
    } else if (vec[mid] > trg)
        return cntoccur(vec, l, mid - 1, trg);
    else return cntoccur(vec, mid + 1, r, trg);
}
int singleNumber(int nums[],int n) { 
    map <int, int> mp;
    long sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        if(mp[nums[i]] == 0){
            sum1 += nums[i];
            mp[nums[i]]++;
        }
        sum2 += nums[i];
    }
    return 2 * (sum1) - sum2;
} 
int singleElement(int arr[], int n){ 
    int low = 0, high = n - 2, mid; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        if (arr[mid] == arr[mid ^ 1]) low = mid + 1;
        //XOR (^ 1) is used to find the adjacent element. If the middle element is equal 
        //to its adjacent element, it means the single element is on the right side, so update the low pointer accordingly.
        else high = mid - 1; 
    } 
    return arr[low]; 
}
int main(){
    vector <int> vec{ 3, 1, 4, 4, 5, 2, 6, 1 };
    int k = 2;
    vector <int> res = nfreq(vec, k);
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
    int ar[]{ 2, 3, 5, 4, 5, 3, 4 }; 
    int n = sizeof(ar) / sizeof(ar[0]); 
    cout << occuronce(ar, n); 
    cout << findXOR(ar, n) << "\n";
    cout << singleNumber(ar,n) << "\n"; 
    occuronce(ar, n);
}
