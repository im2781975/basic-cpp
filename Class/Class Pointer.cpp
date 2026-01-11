#include<iostream>
#include<memory>
using namespace std;
class A{
    public:
    void show(){
        cout << "A :: show()" << "\n";
    }
};
class B{
    public:
    void show(){
        cout << "B :: show()" << "\n";
    }
};
class C{
    public:
    void show(){
        cout << "C :: show()" << "\n";
        delete this;
    }
};
int main(){
    // unique_ptr can own an object at a time (no copying allowed).
    unique_ptr <A> x(new A); x->show();
    cout << x.get() << "\n"; // returns the memory address of x
    unique_ptr <A> y = move(x); y->show();
    cout << y.get() << " " << x.get() << "\n";
    unique_ptr <A> z = move(y); z->show();
    cout << z.get() << " " << y.get() << " " << x.get() << "\n";
    
    shared_ptr <B> e(new B); e -> show();
    cout << e.get() << "\n";
    shared_ptr <B> f(e); f->show();
    cout << e.get() << " " << f.get() << "\n";
    cout << e.use_count() << " " << f.use_count() << "\n";
    e.reset();
    cout << e.get() << " " << e.use_count() << " " << f.use_count() << "\n";
    
    C *ptr = new C; ptr -> show();
    //ptr = nullptr; // Make ptr nullptr to make sure that it's not used again.
    ptr -> show();
    C c; c.show();
}
using namespace std;
class rect{
    int len, bred;
    public:
    rect(int h, int w){
        len = h;  bred = w;
    }
    int area(){
        return len * bred;
    }
};
class text{
    int x;
    public:
    text(int x = 0) { this -> x = x; }
    void change(text *t) { *this = *t; }
    void print() { cout << x << "\n"; }
};
int main(){
    int m, n; cin >> m >> n;
    unique_ptr <rect> x(new rect(m, n));  
    cout << x->area() << "\n";
    unique_ptr <rect> y = move(x); 
    cout << y->area() << "\n";
    unique_ptr <rect> z = make_unique <rect>(m, n);
    cout << z->area() << "\n";
    shared_ptr <rect> a(new rect(m, n)); cout << a->area() << "\n";
    shared_ptr <rect> b = a; cout << b -> area() << "\n";
    cout << (b.get() == nullptr) << "\n";
    cout << a.use_count() << " " << b.use_count() << "\n";

    text tx(30); tx.print();
    text *ptr = new text(80);
    tx.change(ptr); tx.print();
}
