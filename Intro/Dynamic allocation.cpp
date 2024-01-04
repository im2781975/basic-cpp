#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "\nInvalid array size ";
        return 0;
    }
    int *x = new int[n];
    if (x == nullptr) {
        cout << "\nMemory allocation failed";
        return 0;
    }
    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++)
        cout << &x[i] << " " << x[i] << "\n";

    delete[] x;
}
