#include<bits/stdc++.h>
using namespace std;
int main()
{
    char gfg[100] = " Geeks - for - geeks - Contribute";

    const char s[4] = "-";
    char* tok;
    tok = strtok(gfg, s);
    cout << "\nAfter strtok e :";
    while (tok != NULL) {
        cout<<tok<<" ";
        tok = strtok(0, s);
    }
    cout << "\n";
    char str1[] = "Geeks for Geeks";
    char* toke;
    char* rest = str1;
 
    while ((toke = strtok_r(rest, " ", &rest)))
        cout << toke << " ";
        cout << "\n";
        
    char str[] = "Hello, World! Geeks for Geeks.";
    const char outer[] = "!.";
    const char inner[] = " ,";
 
    char* token;
    char* outer_saveptr = NULL;
    char* inner_saveptr = NULL;
 
    token = strtok_r(str, outer, &outer_saveptr);
 
    while (token != NULL)
    {
        cout << "\nOuter Token: " << token ;
        char* inner_token = strtok_r(
            token, inner, &inner_saveptr);
 
        while (inner_token != NULL) {
            cout << "\nInner Token: " << inner_token ;
            inner_token = strtok_r(NULL, inner,&inner_saveptr);
        }
        token = strtok_r(NULL, outer, &outer_saveptr);
    }
    char str2[] ="Geeks,for.Geeks";
    const char delimiters[] = ",.";
    char* toen = strtok(str, delimiters);
    while (toen != NULL) {
    cout << "\nToken: " << toen << " ";
        toen = strtok(NULL, delimiters);
    }
    cout << "\n";
    return 0;
}
