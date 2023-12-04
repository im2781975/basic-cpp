//reverse() | reverse_copy()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect;
    vector<int>::iterator it;

    for (int i = 0; i < 8; i++) {
        vect.push_back(i + 10);
    }

    cout << "Initial Vector:";
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    cout << "\nAfter reverse specific vect is: ";

    reverse(vect.begin() + 5, vect.begin() + 8);
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    cout << "\nAfter reverse specific vect is: ";

    reverse(vect.begin(), vect.end());
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
    }

    vector<int> src(vect.size());
    reverse_copy(vect.begin(), vect.end(), src.begin());

    cout << "\nAfter remove_copy vect is: ";
    for (int i = 0; i < src.size(); i++) {
        cout << src[i] << " ";
    }
    return 0;
}
