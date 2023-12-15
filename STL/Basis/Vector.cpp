//set_difference() | set_symmetrric_difference()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main()
{
    int arr[]{5, 4, 1, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    vector<int> cev{3, 2, 1, 4, 0, 2};
    vector<int> vect(vec.size()+cev.size());
    vector<int> tcev(vec.size()+cev.size());

    cout << "Vec is: ";
    print(vec);
    cout << "\ncev is: ";
    print(cev);

    vector<int>::iterator it = set_symmetric_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), vect.begin());
    vect.resize(it - vect.begin());

    cout << "\nImposed set_symmetric_difference vect is: ";
    for(it = vect.begin(); it != vect.end(); it++)
        cout << *it << " ";

    cout << "\nImposed set_difference: ";
    vector<int>::iterator pt = set_difference(vec.begin(), vec.end(), cev.begin(), cev.end(), tcev.begin());
    tcev.resize(pt - tcev.begin());
    for(pt = tcev.begin(); pt != tcev.end(); pt++)
        cout << *pt << " ";

    return 0;
}
