#include <iostream>
#include <memory>
using namespace std;
class A {
public:
    void show() { cout << "A::show()" << "\n"; }
};
int main()
{
    shared_ptr<A> p1(new A);
    cout << p1.get() << endl;
    p1->show();
    shared_ptr<A> p2(p1);
    p2->show();
    cout << "\nAddress of p1 is: " << p1.get() ;
    cout << "\nAddress of p2 is: " << p2.get() ;
 
    cout << "\np1.use_count(): " << p1.use_count() ;
    cout << "\np2.use_count(): " << p2.use_count() ;
  
    p1.reset();
    cout<<"\nImplemented reset p1.get(): " << p1.get() ;
    cout<<"\nImplemented reset p2.use_count(): " << p2.use_count() ;
    cout<<"\nImplemented reset p2.get(): " << p2.get() <<"\n";
    
    auto_ptr<A>p3(new A);
    p3->show();
    cout << "\nMemory address of p3 is: " << p3.get() <<"\n";
    
    auto_ptr<A>p4(p3);
    p4->show();
    
    cout <<"\nAfter copy memory address is :" <<p3.get();
  
    cout << "\nMemory address of p2 is: "<<p4.get() ;
    return 0;
}
