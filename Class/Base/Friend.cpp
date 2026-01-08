#include<bits/stdc++.h>
using namespace std;
class start;
class finish{
    int x;
    public: 
    void set(int a) { x = a; }
    friend void max(start, finish);
};
class start {
    int y;
    public:
    void set(int a) { y = a; }
    friend void max(start, finish);
};
void max(start l, finish r) {
    if (l.y > r.x)    cout << l.y << " ";
    else    cout << r.x << " ";
}
class foot;
class another {
    public: void member(foot &f);
};
class foot {
    int x;
    protected : int y;
    public: 
    foot() : x(10), y(20){}
    friend void another :: member(foot &);
};
void another :: member(foot &f) { cout << f.x << " " << f.y << "\n"; }
class base {
    public:
    char init[100] = "This is how";
    char add[100] = " it's work";
    friend void func(base b);
};
void func(base b) { 
    strcat(b.init, b.add); cout << b.init << " "; 
}
int main(){
    start l; finish r; l.set(34); r.set(56);
    max(l, r);
    foot f; another c; c.member(f);
    base b; func(b);
}
using namespace std;
class base {
    private : int x;
    protected : int y;
    public:
    base() : x(10), y(99) {}
    friend class F;
    friend void func(base &b);
};
class F {
    public:
    void disp(base &b) { cout << b.x << " " << b.y << "\n"; }
};
void func(base &b) { cout << b.x << " " << b.y << "\n"; }
class A {
    protected : int x;
    public: 
    A() : x(0){}
    friend void show(A, int);
    int getX() { return x; }
};
class B : public A {
    int y;
    public: 
    B() : y(0){}
    int getY() { return y; }
};
void show(A a, int y){
    cout << a.getX() << " " << y << "\n";
} 
int main(){
    base b; F f;
    f.disp(b); func(b);
    
    A ja; B jb;
    show(ja, 10); show(jb, 20); show(ja, jb.getY());
    cout << ja.getX() << " " << jb.getX() << jb.getY() << "\n";
}
