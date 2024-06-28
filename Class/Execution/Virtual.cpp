//How a virtual function can be private
#include<bits/stdc++.h>
using namespace std;
class base{
    public:
    base(){
        cout << "\nBase Class Constructor";
    }
    // virtual base destructor use when you know you will inherit this class
    virtual ~base(){
        cout << "\nbase class destructor";
    }
    void show(){
        cout << "\nShow called on base class";
    }
    virtual void print(){
        cout << "\nPrint called on base class";
    }
};
class derieved:public base{
    virtual void print(){
        cout << "\nPrint called on derieved class";
    }
    public:
    derieved():base(){
        cout << "\nDerieved class constructor called";
    }
    // virtual derived destructor always use when inheriting from a base class
    virtual ~derieved(){
        cout << "\nDerieved class Destructor";
    }
};
int main(){
    base *bp = new derieved();
    bp->show();
    bp->print();
    delete bp;
}

