#include<bits/stdc++.h>
using namespace std;
class Base{
    public:
    char init[100] = "This is how";
    char add[100] = " it's work";
    friend void Func(Base b);
};
void Func(Base b){
    strcat(b.init, b.add);
    cout << b.init << " ";
}
int main(){
    Base b;
    Func(b);
}

