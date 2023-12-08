//Insert() | erase() | lower_bound() | upper_bound() 
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
void print(multimap<int, int>mmp)
{
    multimap<int, int>::iterator it;
    it=mmp.begin();
    while(it!=mmp.end())
    {
        cout<<it->first<<" "<<it->second<<"\n";
        it++;
    }
}
int main()
{
    multimap<int, int>mmp; 
    
    mmp.insert(pair<int, int>(1, 40));
    mmp.insert(pair<int, int>(2, 30));
    mmp.insert(pair<int, int>(3, 60));
    mmp.insert(pair<int, int>(6, 50));
    mmp.insert(pair<int, int>(6, 10));
    mmp.insert(make_pair(6, 12));
 
    cout << "\nmultimap mmp is : ";
    print(mmp);
 
    mmp.insert(pair<int, int>(4, 50));
    mmp.insert(pair<int, int>(5, 10));
 
    cout << "\nmultimap mmp after insertion: ";
    print(mmp);
    // assigning the elements from gquiz1 to gquiz2
    multimap<int, int>mmp2(mmp.begin(), mmp.end());
 
    cout <<"\nmultimap mmp2 after assign from mmp is : ";
    print(mmp);
    // remove all elements up to key with value 3 in mmp2
    cout << "\nmmp2 after removal of elements less than key=3 : ";
    mmp2.erase(mmp2.begin(), mmp2.find(3));
    print(mmp2);
    //remove all elements with key = 4
    int num;
    num = mmp2.erase(4);
    cout << "\nmmp2.erase(4) : ";
    cout << num << " removed \n";
    print(mmp2);
    // lower bound and upper bound
    cout<<"\nmmp.lower_bound(5): "<< mmp.lower_bound(5)->first <<" "<< mmp.lower_bound(5)->second<< "\n";
         
    cout <<"\nmmp.upper_bound(5) : "<< mmp.upper_bound(5)->first  << " "<< mmp.upper_bound(5)->second
         << "\n";
    return 0;
}
