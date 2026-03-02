#include<bits/stdc++.h>
using namespace std;
void initialize() {
    typedef vector <int> vec;
    vec v;
    for(int i = 1; i <= 10; i += 2) v.push_back(i * 2);
    for(int x : v) cout << x << " ";
}
