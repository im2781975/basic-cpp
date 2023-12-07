#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    map<string, int>::iterator it;
    mp["A"] = 1;
    mp["B"] = 2;

    cout << "\nElements of string A & B are: " << mp["A"] << " " << mp["B"];

    mp["B"] = 3;
    cout << "\nElements of string A & B after change are: " << mp["A"] << " " << mp["B"];

    cout << "\nmap[string, int] elements are: ";
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << "\nKey: "<< it->first << " " << "Value: "<< it->second ;
    }

    cout << "\n";
    map<int, int> mpp;
    map<int, int>::iterator pt;
    mpp[23] = 4;
    mpp[32] = 5;

    cout << "\nmap[int, int] elements are: ";
    for (pt = mpp.begin(); pt != mpp.end(); pt++)
    {
        cout << "\nKey: "<< pt->first << " " << "value: "<< pt->second;
    }
    if(mpp.count(23)>0)
        cout<<"\nExit";
    else
        cout<<"\ndoesn't exit";
    return 0;
}
