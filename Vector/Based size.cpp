#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;
bool sizecom(const vector<int>& v1, const vector<int>& v2)
{
    return v1.size() < v2.size();
}
bool Sizecom(const vector<int>& v1,const vector<int>& v2)
{
    return v1.size() > v2.size();
}
int main()
{
    vector< vector<int> >vect{{1, 2},{3, 4, 5},{6}};
 
    cout<<"Before sorting Matrix: ";
    for (int i=0; i<vect.size(); i++)
    {
        cout<<"\n";
        for (int j=0; j<vect[i].size() ;j++)
            cout <<vect[i][j]<< " ";
    }
    //sort(vect.begin(), vect.end(), sizecom);
    sort(vect.begin(), vect.end(), Sizecom);
 
    cout << "\nThe Matrix after sorting is: ";
    for (int i=0; i<vect.size(); i++)
    {
        cout<<"\n";
        for (int j=0; j<vect[i].size() ;j++)
            cout<< vect[i][j] <<" ";
    }
    return 0;
}
