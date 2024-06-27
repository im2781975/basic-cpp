//default arguments and virtual function are used together
#include<bits/stdc++.h>
using namespace std;
class Base{
    public:
    virtual void Func(int x = 1){
        cout << "Base::Func(): " << x;
    }
};
class derieved:public Base{
    public:
    virtual void Func(int x){
        cout << "\nDerieved::Func(): " << x;
    }
};
int main(){
    Base *bp;
    derieved d;
    bp = &d;
    bp->Func();
}

