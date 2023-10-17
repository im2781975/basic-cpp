#include<bits/stdc++.h>
using namespace std;
    vector<string> tokenize(
    const string str,const regex re)
{
    sregex_token_iterator it{ str.begin(),str.end(),re, -1};
    vector<string>tokenized{it,{}};
 // Additional check to remove empty strings
    tokenized.erase(remove_if(tokenized.begin(),tokenized.end(),[](string const& s)
    {
        return s.size() == 0;
                       }),
        tokenized.end());
    return tokenized;
}
int main()
{
    const string str = "Break string a,spaces,and,commas";
    const regex re(R"([\s|,]+)");
   
    const vector<string> tokenized =tokenize(str, re);
   
    for (string token :tokenized)
        cout << token << std::endl;
    return 0;
}
