#include<bits/stdc++.h>
using namespace std;
class base {
    public:
    base(){ cout << "BASE()\n";}
    virtual ~base() = 0;
    // virtual ~base(){ cout << "Destructor\n"; }
};
base :: ~base(){ cout << "~BASE()\n";}
class derived : public base{
    public:
    derived(){ cout << "DERIVED()\n";}
    ~derived(){ cout << "~Derived()\n"; }
};
class parent {
    ~parent(){ cout << "Destructor\n"; }
    public:
    parent(){ cout << "Constructor\n"; }
    friend void destruct(parent*);
    // void destruct(){ delete this; }
};
void destruct(parent *ptr){ delete ptr; }
class Toy {
    public: int id;
    Toy() { cout << "Default\n"; id = 1; }
    Toy(int x) { cout << "parameterized\n"; id = x; }
    ~Toy() { cout << "Destructor " << id << "\n";}
};
int main(){
    derived *d = new derived();
    base *b = d; 
    // base *b = new derived();
    delete b;
    
    parent *ptr = new parent;
    // ptr -> destruct();
    destruct(ptr);
    Toy a, x(9); cout << a.id << " " << x.id << "\n";
    int i = 0;
    while(i < 4) {
        Toy c(i); cout << c.id << " ";
        i++;
    }
}
