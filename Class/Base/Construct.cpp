#include<bits/stdc++.h>
using namespace std;
class Abstract {
    int a, b;
    public:
    Abstract(){}
    Abstract(int x, int y): a(x), b(y){}
    void set(int x, int y) { a = x; b = y; }
    Abstract(const Abstract &p) { a = p.a; b = p.b; }
    int getX() { return a; }
    int getY() { return b; } 
    void disp() { cout << a << " " << b << "\n"; }
};
int main(){
    Abstract at; at.disp();
    Abstract bt(30, 60); bt.disp();
    Abstract ct = bt; ct.disp();
    at.set(9, 6); cout << at.getX() << " " << at.getY();
}
