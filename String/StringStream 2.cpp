#include"bits/stdc++.h"
using namespace std;
int main()
{
    string S, T;
    cout << "Enter String: ";
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, ' '))
        cout << T <<" ";

    int val;
    cout << "\nEnter integers: ";
    cin >> val;
    stringstream geek;
    // inserting integer val in geek stream
    geek << val;
    //The object has the value 123 and stream it to the string x
    string x;
    geek >> x;
    //Now the string x holds the value 12
    cout << x + "4" <<"\n";
    return 0;
}
