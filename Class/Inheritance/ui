//friend class can access private and protected members 
//of other classes in which it is declared as a friend.
#include<bits/stdc++.h>
using namespace std;
class A{
    protected: int x;
    public:
    A(){
        x = 0
    }
    // Pass an instance of class A and an integer.
    friend void show(A, int);
    int GetX(){
        return x;
    }
};
class B:public A{
    int y;
    public:
    B(){
        y = 0;
    }
    int GetY(){
        return y;
    }
};
void show(A a, int y){
    cout << "The default value of A::x = " a.GetX();
    cout << "\nThe value of B::y = " << y ;
};
int main(){
// The show function is called with b (an object of B, which is treated 
//as an object of A due to inheritance) and the value returned by b.GetY()
    B b;
    show(b, b.GetY());
}
