#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string name1 = "GFG";
string favlang = "python";
string companyName = "GFG_2.0";
 
class Developer {
public:
    string name = "mollavai";
    string favLang = "c++";
    string company = "GFG";
 
    Developer(string favlang,string company): favLang(favlang)
        , company(companyName){}
};
int main()
{
    Developer obj = Developer("python", "GFG");
    cout << "favourite Language : " << obj.favLang << "\n" ;
    cout << "company Name : " << obj.company << "\n";
}
