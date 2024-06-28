// without virtual destructor causing undefined behavior
#include <iostream>
using namespace std;
class base {
    public:
    base(){ 
        cout << "\nConstructing base";
    }
    virtual~base(){ 
        cout<<"\nDestructing base";
    }    
};
class derived: public base {
    public:
    derived(){ 
        cout << "\nConstructing derived"; 
    }
    ~derived(){ 
        cout << "\nDestructing derived"; 
    }
};
int main()
{
    derived *d = new derived(); 
    base *b = d;
    delete b;
    getchar();
    return 0;
}
