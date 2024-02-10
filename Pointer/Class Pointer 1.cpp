// unique_ptr
#include <iostream>
#include <memory>
using namespace std;
class A {
public:
    void show(){
        cout << "A::show()\n" ;
    }
};
int main()
{
    unique_ptr<A> p1(new A);
    p1->show();
    // returns the memory address of p1
    cout << p1.get() << "\n";
  
    // transfers ownership to p2
    unique_ptr<A> p2 = move(p1);
    p2->show();
    cout << p1.get() << "\n";
    cout << p2.get() << "\n";
  
    // transfers ownership to p3
    unique_ptr<A> p3 = move(p2);
    p3->show();
    cout << p1.get() << "\n";
    cout << p2.get() << "\n";
    cout << p3.get() << "\n";
    return 0;
}
