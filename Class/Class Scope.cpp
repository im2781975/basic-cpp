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
class out {
    public:    
    int x;
    out(int val = 0) { x = val;}
    void Outer() { cout << x << " " ;}
    class in {
        public:   
        int x; static int y;
        in(int val = 0) { x = val; }
        int func() { return x + y; }
        static void show(){
            cout << y << endl;
        }
    };
};
int out :: in :: y = 5;
int main(){
    out ob(10); ob.Outer();
    out::in inner(20);
    cout << "Inner x = " << inner.x << endl;
    cout << inner.func() << endl;
    out::in::show();
    
    Devo obj;
    cout << obj.Lang << " " << obj.comp << "\n";
    Devo dv = Devo("Java", "XYQR");
    cout << dv.Lang << " " << dv.comp << " " << dv.name;
}
