#include<bits/stdc++.h>
using namespace std;
int main()
{
    char src[50] = "forgeeks";
    char dest1[50] = "geeks";
    char dest2[50] = "geeks";
   
    cout << "\nBefore strcat() func execution,string :" << dest1 ;
    strcat(dest1, src);
    cout << "\nAfter strcat() func execution,string :" << dest1 ;
  
    cout << "\nBefore strcat() func execution,string :"<<dest2 ;
    // Appends 3 characters from src to dest2
    strncat(dest2, src, 3);
    cout << "\nAfter append char strcat() func execution,string :" << dest2 ;
    
    string str1("Geeksfor");
    string str2("Geeks");
 
    cout << "\nOriginal String : "<< str1 ;
    for(int i =0;str2[i]!='\0';i++)
        str1.push_back(str2[i]);
    cout << "\nAfter push_back : " << str1 ;
    
    string init("this is init");
    string add(" added now");
    //init.append(add);
    // init = init + add;
    //cout << init <<"\n";

    string output;
    for (int i = 0; init[i] != '\0'; i++)
        output += init[i];
    for (int i = 0; add[i] != '\0'; i++)
        output += add[i];
    cout << "\nAfter Concat string is: " << output;
    return 0;
}