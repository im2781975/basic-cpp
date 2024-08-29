#include <bits/stdc++.h>
using namespace std;

void f1(int n)
{
    if (n == 1) cout << "One";
    else if (n == 2) cout << "Two";
    else if (n == 3) cout << "Three";
    else if (n == 4) cout << "Four";
    else if (n == 5) cout << "Five";
    else if (n == 6) cout << "Six";
    else if (n == 7) cout << "Seven";
    else if (n == 8) cout << "Eight";
    else cout << "Nine";
}

void f2(int n)
{
    if (n == 1) cout << "Ten";
    else if (n == 2) cout << "Twenty";
    else if (n == 3) cout << "Thirty";
    else if (n == 4) cout << "Forty";
    else if (n == 5) cout << "Fifty";
    else if (n == 6) cout << "Sixty";
    else if (n == 7) cout << "Seventy";
    else if (n == 8) cout << "Eighty";
    else cout << "Nine";
}

int main()
{
    vector<int> v;
    int n, x;
    cin >> n;
    while (n != 0)
    {
        x = n % 10;
        n /= 10;
        v.push_back(x);
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == 0 && i == 0)
            cout << "Zero";
        else if (i == 0)
            f1(v[i]);
        else if (i == 1)
            f2(v[i]);
    }
}
