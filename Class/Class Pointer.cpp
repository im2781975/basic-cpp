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
