// sorting basis of a column
#include <algorithm> 
#include <iostream>
#include <vector> 
using namespace std;
 
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
bool Sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
}
int main()
{
    vector<vector<int> >vect{ { 3, 5, 1 },{ 4, 8, 6 },{ 7, 2, 9 } };
    
    int m = vect.size();
    int n = vect[0].size();
 
    cout << "Before sorting :\n";
    for (int i = 0; i < m; i++) {
        cout<< "\n";
        for (int j = 0; j < n; j++)
            cout <<vect[i][j]<<" ";
    }
    
    //sort(vect[0].begin(), vect[0].end());
    sort(vect.begin(),vect.end(),sortcol);
   // sort(vect.begin(), vect.end(), Sortcol);
 
    cout << "\nAfter sorting : ";
    for (int i = 0; i < m; i++) {
        cout<< "\n" ;
        for (int j = 0; j < n; j++)
            cout <<vect[i][j]<<" ";
    }
    return 0;
}
