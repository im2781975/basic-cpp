#include<bits/stdc++.h>
using namespace std;
bool comp(const string &l, const string &r){
    if(l.size() == r.size()) return l < r;
    else return l.size() < r.size();
}
void ingsort(string *arr, int n) {
    vector <string> vec(arr, arr + n);
    sort(vec.begin(), vec.end(), comp);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
int main(){
    string arr[] = {"54", "724523015759812365462", "870112101220845", "8723"};
    int n = sizeof(arr) / sizeof(arr[0]);
    ingsort(arr, n);
}
using namespace std;
#define x 100
void strsort(char arr[][x], int n){
    char tmp[x];
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(tmp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], tmp);
            }
        }
    }
}
void print(char arr[][x], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    char arr[][x]{"GeeksforGeeks", "Quiz", "Practice","Gblogs", "Coding" };
    int n = sizeof(arr) / sizeof(arr[0]);
    strsort(arr, n);
    print(arr, n);
}
