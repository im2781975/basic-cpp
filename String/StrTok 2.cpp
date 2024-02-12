#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line = "GeeksForGeeks is a must try";
    vector <string> tokens;

    stringstream obj(line);
    string word;

    while(getline(obj, word , ' '))
    {
        tokens.push_back(word);
    }
    for(int i=0;i<tokens.size();i++)
        cout << tokens[i] << '\n';
}
