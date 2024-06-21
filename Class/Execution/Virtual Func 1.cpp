#include <bits/stdc++.h>
using namespace std;
class base{
    protected:
    int x;
    public:
    virtual void fun(){}
    base(int i){
        x = i;
        cout << "Constructor of base called\n";
    }
};
class derieved:public base{
    int y;
    public:
    derieved(int i, int j):base(i), y(j){};
    void fun(){
        cout << x << " " << y;
    }
};
int main(){
    derieved d(5, 9);
    d.fun();
    base *ptr = new derieved(8, 10);
    ptr->fun();
}
