#include<bits/stdc++.h>
using namespace std;
void FindOccurance(string str, char ch)
{
    size_t found = str.find(ch);
    if(found == string::npos)
        cout << ch << " Doesn't exit";
    else
        cout << ch << " Exit at position " << found;
}
int main()
{
    string str;
    getline(cin, str);
    char ch = 'a';
    FindOccurance(str, ch);
}
