// unique()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vect{ 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
 
    vector<int>::iterator it;
    sort(vect.begin(), vect.end());
    
    it =unique(vect.begin(), vect.begin() + 12);
    
    vect.resize(distance(vect.begin(), it));
    cout<<"\nAfter resize : ";
    for (it = vect.begin(); it != vect.end(); ++it) {
        cout << *it << " ";
    }
    
    int count =distance(vect.begin(), unique(vect.begin(), vect.begin() + 12));
    cout << "\nTotal no. of unique elements = " << count;
    return 0;
}
