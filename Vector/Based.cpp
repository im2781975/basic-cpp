// sorting basis of a column & size
#include <algorithm> 
#include <iostream>
#include <vector> 
using namespace std;
bool sortcol(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
    //return a[1] > b[1];
}
bool sizecom(const vector<int>& a, const vector<int>& b)
{
    return a.size() < b.size();
    //return a.size() > b.size();
}
int main()
{
    vector<vector<int> >vect{ { 3, 5, 1 },{ 4, 8, 6 },{ 7, 2, 9 } };
    sort(vect[0].rbegin(), vect[0].rend());
    //sort(vect[0].begin(), vect[0].end());
    //sort(vect.begin(),vect.end(),sortcol);
    sort(vect.begin(), vect.end(), sizecom);
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[0].size(); j++)
            cout <<vect[i][j]<<" ";
        cout << "\n";
    }
    return 0;
}
