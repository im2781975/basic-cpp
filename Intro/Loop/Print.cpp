#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{0, 1, 2, 3, 4, 5};
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    for (int n : {0, 1, 2, 3, 4, 5})
        cout << n << ' ';
    cout << '\n';
  
    int a[]{0, 1, 2, 3, 4, 5};
    for (int n : a)
        cout << n << ' ';
    cout << '\n';
  
    string str = "ibrahim";
    for (char c : str)
        cout << c;
    cout << "\n";

    map<int, int> mp({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : mp)
        cout << "{" << i.first << "," << i.second << "}" << " ";
    
    cout << "\n";
}
