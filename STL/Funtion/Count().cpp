// count_if() | count()
#include <bits/stdc++.h>
using namespace std;
bool isEven(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    int noEven = count_if(v.begin(), v.end(),isEven);
    cout << "After using count_if Even count is: "<< noEven;
    
    
    string str = "geeksforgeeks";
    cout << "\nAfter using count() 'e' count is : " << count(str.begin(), str.end(), 'e');
 
    return 0;
}
