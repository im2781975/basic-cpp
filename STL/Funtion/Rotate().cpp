//Rotate() | Rotate_copy()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<int>&v)
{
    int len=v.size();
    for(int i=0; i<len; i++)
    {
        cout<<v[i]<<" ";
    }
}
int main() {
    vector<int> vect{1, 2, 3, 4, 5, 6, 7};

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
