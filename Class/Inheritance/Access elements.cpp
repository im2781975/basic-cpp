//public, private & protected inheritance
#include<bits/stdc++.h>
using namespace std;
class base{
    private: int pvt = 1;
    protected : int prot = 2;
    public : int pub = 3;
    int getPriv(){
        return pvt;
    }
};
//In Prot_Derived, Base's public and protected members become protected
class DerivedProt:protected base{
    public:
    int getProt(){
        return prot;
    }
    int getPub(){
        return pub;
    }
};
class DerivedPriv:private base{
    public:
    int getProt(){
        return prot;
    }
    int getPub(){
        return pub;
    }
};
//function to access protected member from Base
class DerivedPub:public base{
    public:
    int getProt(){
        return prot;
    }
};
int main(){
    DerivedProt a;
    cout << "\nPrivate cannot be accessed." ;
    cout << "\nProtected Members are: " << a.getProt();
    cout << "\nPublic Members are: " << a.getPub();
    
    DerivedPriv b;
    cout << "\nPrivate cannot be accessed." ;
    cout << "\nProtected Members are: " << b.getProt();
    cout << "\nPublic Members are: " << b.getPub();
    
    DerivedPub c;
    cout << "\nPrivate Members are: " << c.getPriv();
    cout << "\nProtected Members are: " << c.getProt();
    cout << "\nPublic Members are: " << c.pub;
}

