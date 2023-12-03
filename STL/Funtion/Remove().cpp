// remove() | remove_if()
#include <bits/stdc++.h>
using namespace std;
bool IsOdd(int i) 
 { return ((i % 2) == 1); }
 
void print(vector<int>&vect)
{
    int len=vect.size();
    for(int i=0; i<len; i++)
        cout<<vect[i]<<" ";
}
int main()
{
    vector<int> vect1{10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> vect2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
    cout << "vect1 is : ";
    print(vect1);
 
    vector<int>::iterator it;
    vector<int>::iterator pt;
    it = remove(vect1.begin(), vect1.end(), 20);
 
    cout << "\nAfter remove vect1 is: ";
    for (pt =vect1.begin(); pt!= it; ++pt)
        cout << ' ' << *pt;

    cout << "\nvect2 is : ";
    print(vect2);

    //it =remove_if(vec2.begin(), vec2.end(), IsOdd);
    it = remove_if(vect2.begin(), vect2.end(),[](int i) { return ((i % 2) == 1); });
 
    cout << "\nAfter remove_if vect2 is: ";
    for (pt=vect2.begin(); pt != it; ++pt)
        cout << ' ' << *pt;
    return 0;
}
