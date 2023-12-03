//find() | find_end() | find_first_of() 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int a, int b)
{
    return (a == b);
}

int main()
{
    vector<int> v{1, 3, 10, 3, 10, 1, 3, 3, 10, 7, 8, 1, 3, 10};
    vector<int> v1 = {1, 3, 10};
    vector<int>::iterator ip;

    // find()
    ip = search(v.begin(), v.end(), v1.begin(), v1.end());

    cout << "First occurrence at index: " << (ip - v.begin()) ;

    // find_end()
    ip = find_end(v.begin(), v.end(), v1.begin(), v1.end(), Pred);

    if (ip != v.end())
        cout << "\nLast common occurrence begins at index: " << (ip - v.begin()) ;
    else
        cout << "\nNo common occurrence found." ;
    
    // find_first_of()
    ip = find_first_of(v.begin(), v.end(), v1.begin(), v1.end()); 
    // Displaying the first common element.
    cout << "\nFirst common element at idx: " << *ip ;

    ip = find_first_of(ip + 1, v.end(), v1.begin(), v1.end()); 
  
    // Displaying the second common element found 
    cout << "\nSecond common element at idx: " << *ip ;
    
    return 0;
}
