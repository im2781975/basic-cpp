#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
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

bool pred(int i, int j)
{
    return i == j;
}

int main()
{
    srand(unsigned(time(0)));
    int ar[] = {10, 20, 30, 40, 50};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "After impose shuffle using array: ";
    suffle(ar, n);

    vector<int> arr(ar, ar + n);
    vector<int>::iterator it;
    random_shuffle(arr.begin(), arr.end(), random_suffle);
    cout << "\nAfter impose shuffle using vector: ";
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    array<int, 5> s{1, 2, 3, 4, 5};
    unsigned seed = 0;

    shuffle(s.begin(), s.end(), default_random_engine(seed));

    cout << "\nAfter impose shuffle using vector array: ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    int v2 = 3;
    vector<int> v1 = {1, 2, 3, 4, 5, 3, 3, 6, 7};

    vector<int>::iterator i1;

    i1 = search_n(v1.begin(), v1.end(), 2, v2, pred);

    if (i1 != v1.end())
    {
        cout << "\nv2 is present consecutively 2 times at index "
             << (i1 - v1.begin());
    }
    else
    {
        cout << "\nv2 is not present consecutively 2 times "
             << "in vector v1";
    }

    vector<int> v3 = {3, 4};

    i1 = search(v1.begin(), v1.end(), v3.begin(), v3.end());

    if (i1 != v1.end())
    {
        cout << "\nvector3 is present firstly at index "
             << (i1 - v1.begin());
    }
    else
    {
        cout << "\nvector3 is not present in vector1 ";
    }

    i1 = find_end(v1.begin(), v1.end(), v3.begin(), v3.end());

    if (i1 != v1.end())
    {
        cout << "\nvector3 is present lastly at index " << (i1 - v1.begin());
    }
    else
    {
        cout << "\nvector3 is not present in vector1";
    }
    return 0;
}
