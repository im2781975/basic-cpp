#include<bits/stdc++.h>
using namespace std;
string nome = "mlv";
string lang = "python";
string company = "PISQR";
class Devo{
    public:
    string name = "Alv";
    string Lang = "Cpp";
    string comp = "PRO";
    Devo(){}
    Devo(string lang, string company):Lang(lang), comp(company){}
};
int main(){
    Devo ob;
    cout << ob.Lang << " " << ob.comp << "\n";
    Devo dv = Devo("Java", "XYQR");
    cout << dv.Lang << " " << dv.comp << " " << dv.name;
}
