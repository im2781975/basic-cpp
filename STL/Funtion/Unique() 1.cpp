 // unique_copy | unique()
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
bool Pred(char a, char b)
{
    if (a == b && a == 'v') 
        return 1;

    else
        return 0;

}
int main()
{
    string s = "You arre vvvisiting GFG", s1;
    auto ip = unique_copy(s.begin(), s.end(), back_inserter(s1), Pred);
 
    cout << "Before unique_copy string is: " << s;
    cout << "\nAfter unique_copy string is: " << s1;
    
   auto it = unique(s.begin(), s.end(), Pred);
    cout << "\nAfter unique string is: " << s;
    cout << string(s.begin(), it);
    cout << "\nAfter unique string is: " << s;
    return 0;
}
