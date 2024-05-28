#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;
 
    public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};
 
int main()
{
    unique_ptr<Rectangle> a(new Rectangle(10, 5));
    cout << "\nBased unique ptr: " << a->area() ;
    
    unique_ptr<Rectangle> b;
    b = move(a);
    cout << "\nBased unique ptr: " << b->area() ;
    
    unique_ptr<Rectangle> f = make_unique<Rectangle>(10, 5);
    cout << "\nBased unique ptr: " << f->area() << "\n";
    
    shared_ptr<Rectangle> c(new Rectangle(8, 9));
    
    shared_ptr<Rectangle> d;
    d = c;
    weak_ptr<Rectangle> e (c);
   
    cout << "\nBased share count: " << c->area() ;
    cout << "\nBased share count: " << d->area() ;

    shared_ptr<Rectangle> g = d;

    cout << "\nAfter shared ptr: " << g->area() ;

    // This'll also print 0 now, as P1 is now nullptr
    cout << "\nIs ptr is null: " << (d.get() == nullptr) ;

    // This'll print 2 as Reference Counter is 2
    cout << "\nd.use_count(): " << d.use_count() ;
    cout <<"\nReference count: " <<c.use_count() ;
    return 0;
}
