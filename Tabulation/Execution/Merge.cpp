#include<bits/stdc++.h>
using namespace std;

void print(vector<int> st)
{
    for(int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }
}
struct greaters
{
    bool operator()(const int &a,const int &b)const
    {
        return a>b;
    }
};
int main()
{
    vector<int> vect {2, 3, 6};
    vector<int> vec {5, 7, 9};
    vector<int> cev(10);
    vector<int> v, root(vect.size() + vec.size());

    cout << "\nvect is: ";
    print(vect);
    cout << "\nvec is: ";
    print(vec);

    sort(vect.begin(), vect.end());
    sort(vec.begin(), vec.end());

    merge(vect.begin(), vect.end(), vec.begin(), vec.end(), cev.begin());
    cev.resize(distance(cev.begin(), unique(cev.begin(), cev.end())));
    cout << "\nAfter sorting cev is: ";
    print(cev);

    includes(v.begin(), v.end(), cev.begin(), cev.end()) ?
        cout << "\ncev is included in v" :
        cout << "\ncev isn't included";

    auto it = copy(vect.begin(), vect.end(), root.begin());
    copy(vec.begin(), vec.end(), it);
    cout << "\nMerged and copied vector is: ";
    print(root);
    root.clear();
    
   // sort(vect.rbegin(), vect.rend());
   // sort(vec.rbegin(), vec.rend());
    //merge(vect.begin(),vect.end(),vec.begin(),vec.end(),greaters());
    merge(vect.rbegin(),vect.rend(),vec.rbegin(),vec.rend(),back_inserter(root),greaters());
    cout<<"\nReversed merge vector is: ";
    print(root);
    return 0;
}
