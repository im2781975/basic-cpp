//insert() | erase() | find() 
#include <bits/stdc++.h>
using namespace std;

void print(multiset<int> s)
{
    multiset<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    multiset<int> s;
    multiset<int>::iterator it;

    for (int i = 0; i <= 15; i++)
    {
        s.insert(i);
    }

    cout << "\nMultiset is: ";
    print(s);
    cout << "\nSize of multiset is: " << s.size();

    // Erase all occurrences
    s.erase(4);
    cout << "\nMultiset after erasing 4: ";
    print(s);

    // Erase a single occurrence
    s.erase(s.find(7));
    cout << "\nMultiset after erasing 7: ";
    print(s);

    if (s.find(5) != s.end())
        cout << "\n5 Exists";
    else
        cout << "\n5 doesn't exist";

    return 0;
}

