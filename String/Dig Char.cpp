#include<bits/stdc++.h>
using namespace std;
void FindOccurance(string str, char ch)
{
    size_t found = str.find(ch);
    if(found == string::npos)
        cout << ch << " Doesn't exit" << "\n";
    else
        cout << ch << " Exit at position " << found;
}
void FindLast(string str, char ch, size_t position)
{
    size_t found = str.find(ch, position);
    if (found == string::npos)
        cout << "\nCharacter '"  << ch << "' isn't present";
    else
        cout << "\nOccurance of '" << ch << "' before position '" << position << "' found at idx " << found ;
}
int main()
{
    string str;
    getline(cin, str);
    char ch = 'm';
    FindOccurance(str, ch);
    
    size_t position = 4;
    FindLast(str, ch, position);
    const char *ptr = strrchr(str.c_str(), ch);
    //Use str.c_str() to get a C-style string
    if(ptr)
        cout << ptr-str.c_str();
    else
        cout << "doesn't";
}
