#include <iostream>
using namespace std;
class Abstract {
    private:
    int a, b;
    public:
    //Abstract(int x,int y):a(x),b(y){}
    Abstract(){}
    Abstract(int x,int y){}
    void set(int x, int y){
        a = x; b = y;
    }
    // Copy constructor
    Abstract(const Abstract& p){
        a = p.a; b = p.b;
    }
    int getX(){ 
        return a; 
    }
    int getY(){
        return b; 
    }
    void display(){
        cout << "a = " << a << " b = " << b << "\n";
    }
};
int main(){
    //Abstract t(10,20);
    Abstract t;
    t.set(10, 20);
    t.display();
    Abstract s = t; 
    cout << "s.x: "<< s.getX()
         << " s.y = " << s.getY();
         cout<<"\n";
    cout << "t.x: " << t.getX()
         << " t.y: " << t.getY();
    return 0;
}
