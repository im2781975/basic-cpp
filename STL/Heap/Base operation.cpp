//is_heap() | is_heap_until() | make_heap()
#include<bits/stdc++.h>
using namespace std;

struct greaters
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

int main()
{
    vector<int> vect{9, 2, 1, 6, 4};
    vector<int>::iterator it, pt;

    is_heap(vect.begin(), vect.end()) ? cout << "\nContainer is heaped" : cout << "\nContainer isn't heaped";

    pt = is_heap_until(vect.begin(), vect.end());

    cout << "\nVect elements are: ";
    for (it = vect.begin(); it != pt; it++)
    {
        cout << *it << " ";
    }

    //make_heap(vect.begin(),vect.end(),greaters());
    make_heap(vect.begin(), vect.end());

    cout << "\nFront element after make_heap: " << vect.front();
}
