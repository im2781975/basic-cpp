#include<bits/stdc++.h>
using namespace std;
class text{
    int x, y;
    public:
    text(int x = 0, int y = 0){
        this -> x = x; this -> y = y;
    }
    text &setX(int a){ x = a; return *this; }
    text &setY(int b){ y = b; return *this; }
    void print(){ cout << x << " " << y << "\n";}
};
class trial {
    int x, y;
    public:
    trial(int x = 0, int y = 0){}
    void setX(int a){ x = a; }
    void setY(int b){ y = b; }
    void print(){ cout << x << " " << y << "\n";}
};
class test {
    int x, y;
    public:
    test(int x = 0, int y = 0) {
        this -> x = x; this -> y = y;
    }
    static void func(){ cout << "ing\n"; }
};
class tax {
    public:
    int x; mutable int y; 
    // mutable use to modify particular const obj
    tax(): x(10), y(40){}
};
void fun(){
    static int x;
    enum { i = 1, j = 2};
    class base {
        public:
        void method() { cout << x << "\n" << i << endl; }
    };
    base b; b.method();
}
class check{
    int a;
    public:
    check(){ a = 1; }
    void func(int a) {
        cout << this -> a << " " << a << " " << check:: a << "\n";
    }
};
class cls{ int x; int y; double d; char ch[20]; };
struct str{ int x; float y; double d; char ch[20]; } s;
union uni{ int x; float y; double d; char ch[20]; }u;
int main(){
    text tt(8, 9); tt.print();
    trial tl; tl.setX(6); tl.setY(11);
    tl.print();
    test ts; ts.func();
    
    const tax tx; tx.y = 35;
    cout << tx.x << " " << tx.y << "\n";
    fun();
    cls c;   cout << sizeof(c) << " " << sizeof(s) << " " << sizeof(u) << "\n";
    check t; t.func(9);
}
