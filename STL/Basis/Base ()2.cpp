#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main() {
    vector<int> vect1{1, 2, 3, 4};
    vector<int> vect2(vect1);
    vector<int> vect3;
    vector<int> cev(vect1.size() + vect2.size());
    cout << "\nElement of Vect1[] is: ";
    print(vect1);

    cout << "\nAfter copy(constructive) vect2[] is : ";
    print(vect2);

    vect1[0] = 2;

    cout << "\nFirst element of vect1[] is:" << vect1[0] << " " << vect1.front();

    copy(vect1.begin(), vect1.end(), back_inserter(vect3));
    cout << "\nElements of vect1[] are: ";
    print(vect1);

    cout << "\nAfter copy vect3[] are : ";
    print(vect3);

    // copy<iterative>
    vector<int> vect4;
    vect4 = vect1;

    cout << "\nElements of vect1[] are: ";
    print(vect1);

    cout << "\nAfter copy(iterative) elements of vect4[] are: ";
    print(vect4);

    vect1[0] = 2;
    cout << "\nFirst element of vect1[] is :" << vect1.front();

    cout << "\nFirst element of vect4[] is :" << vect4.front();
    vector<int>::iterator it;
    merge(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), cev.begin());
    cout << "\nAfter merge cev is: ";
    print(cev);

    cout << "\nReversed cev is: ";
    for (it = cev.end() - 1; it != cev.begin() - 1; --it)
        cout << *it;
        
    vect2.clear();
    vect2.assign(cev.begin(),cev.end());
    cout<<"\nImposed assign: ";
    print(cev);
    
    //vect3.clear();
    int n=0;
    vect3.insert(vect3.begin()+n, vect1.begin()+n, vect1.end());
    cout<<"\nImposed insert: ";
    print(vect3);
    return 0;
}
