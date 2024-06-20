#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> vec{1, 2, 3, 4, 5};
    for(auto &x : vec)
        x += 5;
    for(int x : vec)
        cout << x << " ";
    cout << "\n";
    vector <int> cev(5, 3);
    for(int i = 0; i < 5 - 3; i++)
        cev[i] = i;
    for(int i = 0; i < cev.size(); i++)
        cout << cev[i] << " ";
    cout << "\n";
    vector <int> v(5, 0);
    v[0] = -1;
    v.resize(10, 10);
    cout << v.front() << "\n";
    cout << v[7];
}
