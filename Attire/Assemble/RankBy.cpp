#include<bits/stdc++.h>
using namespace std;
void sortbyarr(vector <int> &vec, vector <int> &tor){
    unordered_map <int, int> idx;
    for(int i = 0; i < tor.size(); i++){
        if(idx[tor[i]] == 0) idx[tor[i]] = i + 1;
    }
    auto comp = [&](int a, int b){
        // if both value are same return increasing 
        if(idx[a] == 0 && idx[b] == 0) return a < b;
        // Element in tor always comes before element not in tor.
        if(idx[a] == 0) return false;
        if(idx[b] == 0) return true;
        return idx[a] < idx[b]; 
        // sorting in increasing order
    };
    sort(vec.begin(), vec.end(), comp);
}
int main(){
    vector <int> vec{2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 7, 5, 6, 9, 7, 5};
    vector <int> tor{ 2, 1, 8, 3, 4, 1 };
    sortbyarr(vec, tor);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
using namespace std;
int func(int *arr, int low, int high, int val, int n){
    if(high >= low){
        int mid = low + (high - low) / 2;
        if((mid == 0 || val > arr[mid - 1]) && arr[mid] == val)   return mid;
        if(val > arr[mid]) return func(arr, mid + 1, high, val, n);
        return func(arr, low, mid - 1, val, n);
    }
    return -1;
}
void sortAccording(int *arr, int *ray, int m, int n){
    int tmp[m], visited[m];
    for(int i = 0; i < m; i++){
        tmp[i] = arr[i]; visited[i] = 0;
    }
    sort(tmp, tmp + m);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x = func(tmp, 0, m - 1, ray[i], m);
        if(x == -1)    continue;
        for(int j = x; (j < m && tmp[j] == ray[i]); ++j) {
            arr[cnt++] = tmp[j];
            visited[j] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        if(visited[i] == 0) arr[cnt++] = tmp[i];
    }
}
void sortby(int *arr, int n, int *ray, int m, int *res){
    map <int, int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        mp[arr[i]] += 1;
    for(int i = 0; i < m; i++){
        if(mp[ray[i]] != 0) {
            for(int j = 1; j <= mp[ray[i]]; j++)
                res[cnt++] = ray[i];
        }
        mp.erase(ray[i]);
    }
    for(auto it : mp){
        for(int j = 1; j <= it.second; j++)
            res[cnt++] = it.first;
    }
}
void print(int *arr, int n){
    for(int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
    int ray[] = {2, 1, 8, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(ray) / sizeof(ray[0]);
    sortAccording(arr, ray, m, n);
    // int res[n]; sortby(arr, n, ray, m, res);
    print(arr, m);
}
