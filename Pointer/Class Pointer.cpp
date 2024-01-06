// working of unique_ptr
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
    
    shared_ptr<Rectangle> c(new Rectangle(8, 9));
    
    shared_ptr<Rectangle> d;
    d = c;
    weak_ptr<Rectangle> e (c);
   
    cout << "\nBased share count: " << c->area() ;
    cout << "\nBased share count: " << d->area() ;
 
    cout <<"\nReference count: " <<c.use_count() ;
    return 0;
}
