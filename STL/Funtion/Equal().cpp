//equal() | equal_range()
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v{10, 10, 30, 30, 30, 100, 10, 300, 300, 70, 70, 80};

    pair<vector<int>::iterator, vector<int>::iterator> ip;

    cout << "Before sorting elements: ";
    for (auto i : v)
        cout << i << " ";

    // Sorting the vector
    sort(v.begin(), v.end());

    cout << "\nAfter sorting elements: ";
    for (auto i : v)
        cout << i << " ";

    // Comparing elements with 30
    ip = equal_range(v.begin(), v.end(), 30);

    cout << "\n30 is present in the sorted vector from index "
         << (ip.first - v.begin()) << " to " << (ip.second - v.begin());

    vector<int> vect(v.begin(), v.end());
    //vector<int> vect(v, v+sizeof(v) / sizeof(int) );
    cout << "\nElements of vect are:";
    for (unsigned int i = 0; i < vect.size(); i++)
        cout << " " << vect[i];

    // Using std::equal() to compare vectors
    if (equal(vect.begin(), vect.end(), v.begin()))
        cout << "\nContents of both sequences are equal";
    else
        cout << "\nContents of both sequences differ.";

    return 0;
}