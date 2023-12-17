//reverse() | reverse_copy() | Rotate() | Rotate_copy()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>&v)
{
    int len=v.size();
    for(int i=0; i<len; i++)
    {
        cout<<v[i]<<" ";
    }
}
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

    cout << "\nVector is: ";
    print(vect);

    int rotL = 3;
    rotate(vect.begin(), vect.begin() + rotL, vect.end());
    cout << "\nVector after rotation: ";
    print(vect);

    int rotR = 5;
    rotate(vect.begin(), vect.begin() + vect.size() - rotR, vect.end());
    cout << "\nNew vector after right rotation: ";
    print(vect);

    vector<int> cev(7);
    rotate_copy(vect.begin(), vect.begin() + 3, vect.end(), cev.begin());

    cout << "\ncev[] contains:";
    for (auto i = cev.begin(); i != cev.end(); i++)
        cout << ' ' << *i;
    return 0;
}
