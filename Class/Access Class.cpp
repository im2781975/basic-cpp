#include<bits/stdc++.h>
using namespace std;
class test{
    public:
    void main(int d){ cout << d << " "; }
    void main(const char *ch){ cout << ch << " ";}
    void main(int d, int g){ cout << d << " " << g << endl; }
};
class Animal {
    public:    string color = "Black";
};
class cat:public Animal {
    public:    string color = "Brown";
};
class dog:public Animal {
    public:    string color = "Gray";
};
class base {
    public:
    int num;
    base(int x): num(x){}
    base *operator->() { return this; }
    // (base *operator->())->num = b->num
    // objects can behave like pointers.
};
class parent{
    public:
    void func() { cout << "parent func"; }
};
class derived{
    public:
    void tion(){
        parent p; p.func();
    }
};
int main(){
    base b(8); cout << b.num << " ";
    base *ptr = &b; cout << ptr->num << " " << b->num << "\n";
    derived d; d.tion();
    
    Animal x = dog(); cout << x.color << "\n";
    dog dg; cout << dg.color << "\n";
    
    test t; t.main(56); t.main("I love c++"); t.main(7, 9);
}
