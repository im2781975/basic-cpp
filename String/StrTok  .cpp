#include <bits/stdc++.h>
using namespace std;
int main()
{
    char name[100], add[100], about[100];
    cout << "\nName is: ";
    cin.getline(name, 100);
    cout << "\nAddress is: ";
    cin.getline(add, 100);
    cout << "\nDescribe yourself: ";
    cin.getline(about, 100);
    
    cout << "\nName is: " << name;
    cout << "\nAddress is: " << add;
    cout << "\nAbout is: " << about ;
    
    string line = "GeeksForGeeks is a must try";
    vector <string> tokens;

    stringstream obj(line);
    string word;

    while(getline(obj, word , ' '))
        tokens.push_back(word);
    for(int i=0;i<tokens.size();i++)
        cout << tokens[i] << '\n';
}
