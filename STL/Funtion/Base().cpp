// all_of() | any_of() | copy_n() | none_of() | find_first_of()
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void operation(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            arr[i] *= 2;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool allpositive = all_of(arr, arr + n, [](int i) { return i > 0; });
    cout << "\nAfter impose all_of: ";
    if (allpositive)
        operation(arr, n);

    bool anyEven = any_of(arr, arr + n, [](int i) { return i % 2 == 0; });
    cout << "\nAfter impose any_of: ";
    if (anyEven)
        operation(arr, n);

    int ar[n];
    copy_n(arr, n, ar);
    cout << "\nAfter impose copy_n: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";

    bool noneNeg = none_of(ar, ar + n, [](int i) { return i < 0; });
    cout << "\nAfter impose none_of: ";
    if (noneNeg)
        operation(ar, n);

    vector<int> vect(arr, arr + n);
    vector<int> cev(ar, ar + n);
    auto p = find_first_of(vect.begin(), vect.end(), cev.begin(), cev.end());
    cout << "\nAfter impose find_first_of: ";
    cout << p - vect.begin();

    return 0;
}
