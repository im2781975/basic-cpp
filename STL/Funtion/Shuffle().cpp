#include<bits/stdc++.h>
using namespace std;

void suffle(int arr[], int n)
{
    random_shuffle(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int random_suffle(int j)
{
    return rand() % j;
}

int main()
{
    // srand(unsigned(time(0)));
    int ar[] = {10, 20, 30, 40, 50};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "After impose suffle using array: ";
    suffle(ar, n);

    vector<int> arr(ar, ar + n);
    vector<int>::iterator it;
    // random_shuffle(arr.begin(),arr.end());
    random_shuffle(arr.begin(), arr.end(), random_suffle);
    cout << "\nAfter impose suffle using vector: ";
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    array<int, 5> s{1, 2, 3, 4, 5};
    unsigned seed = 0;

    shuffle(s.begin(), s.end(), default_random_engine(seed));

    cout << "\nAfter impose suffle using vector aeray: ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}
