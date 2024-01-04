#include <bits/stdc++.h>
using namespace std;
string Erase_First_Last(string s)
{
    s.erase(s.begin());
    s.pop_back();
    return s;
}
string EraseFirstLast(string &s)
{
    s.erase(s.begin());
    s.pop_back();
    return s;
}
void Swap(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}
int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    string ans = EraseFirstLast(s);
    cout << "\nAfter Erase_First_Last string is: " << ans;

    Erase_First_Last(s);
    cout << "\nAfter EraseFirstLast (using address) string is: " << s;

    int a, b;
    cout << "\nEnter integers: ";
    cin >> a >> b;
    Swap(a, b);
    cout << "\nAfter swap() integers are: " << a << " " << b;
    return 0;
}
