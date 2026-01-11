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
