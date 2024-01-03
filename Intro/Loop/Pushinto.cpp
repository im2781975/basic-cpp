#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N=5;
    vector<int> v1 = {3, 1, 7, 9};
    vector<int> v2 ={10,2,7,16,9};
 
    auto pushinto = [&] (int m)
    {
        v1.push_back(m);
        v2.push_back(m);
    };
    pushinto(20);
    // access v1 by copy
[v1]()
{
    for (auto p = v1.begin(); p != v1.end(); p++)
    {
        cout << *p << " ";
    }
    cout<<"\n";
}();

    auto p =find_if(v1.begin(),v1.end(),[N](int i)
    {
    return i > N;
    });

    if (p != v1.end())
    {
    cout << "First number greater than 5 is: " << *p << endl;
    } 
    else {
    cout << "No number greater than 5 found in v1." << endl;
    }
    // function to count numbers greater than or equal to N
    // [=] denotes,   can access all variable
    int count_N = count_if(v1.begin(), v1.end(), [=](int a)
    {
        return (a >= N);
    });
    cout << "The number of elements greater than or equal to 5 is : "<< count_N << endl;
}
