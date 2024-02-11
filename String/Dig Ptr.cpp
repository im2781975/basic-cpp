#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[] = "Aslam";
    char ch = 'a';
    char *ptr = strrchr(str, ch);
    if(ptr)
        cout << "\nLast occurrence of '" << ch << "' in "<< str << " is at idx " << ptr-str;
    else
        cout << "'" << ch <<"' isn't present in " <<str;
}
