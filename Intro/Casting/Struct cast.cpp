#include <bits/stdc++.h>
using namespace std;
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};
int main()
{
    mystruct s;
    
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;
    
    int* p = reinterpret_cast<int*>(&s);
    cout << sizeof(s) << "\n";
    cout << *p << "\n";
    
    p++;
    cout << *p << endl;
    p++;
 
    char* ch = reinterpret_cast<char*>(p);
    cout << *ch << " " ;
    ch++;
 
    bool* n = reinterpret_cast<bool*>(ch);
    cout << *n << " ";

    cout << *(reinterpret_cast<bool*>(ch));
    return 0;
}
