#include<bits/stdc++.h>
using namespace std;
class shape{
    protected:
    int len, wid;
    public:
    shape(int l, int w){
        len = l; wid = w;
    }
    virtual double area() { return len * wid; }
    virtual ~shape(){}
};
class box : public shape{
    public:
    box(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return len * wid;}
};
class rectangle : public shape{
    public:
    rectangle(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return len * wid;}
};
class triangle : public shape{
    public:
    triangle(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return 0.5 * (len * wid);}
};
class circle {
    private:    double radius;
    public:    /*
    void area(double r) {
        radius = r;
        cout << radius << " " << 3.1416 * radius * radius << "\n";
    } */
    void getradius() { cin >> radius; }
    void findarea() { cout << 3.1416 * radius * radius << "\n";}
};
class Triangle {
    private:    int base, height;
    public:
    void area(int h, int b) {
        base = b; height = h;
        cout << 0.5 * base * height << "\n";
    }
};
class square {
    private:    int x;
    public:
    void area(int a) {
        x = a; cout << x * x << "\n";
    }
};
class rect{
    public: double area;
    rect(): area(0){}
    rect(int x, int y) { area = x * y; }
    void disp() { cout << area << "\n";}
};
int main(){
    shape *sp; box sq(2, 9);
    sp = &sq; cout << sp->area() << "\n";
    triangle tri(6, 9);
    sp = &tri; cout << sp->area() << "\n";
    
    circle cir; cir.getradius(); cir.findarea(); // cir.area(8.5)
    Triangle tr; tr.area(8, 9);
    square sqr; sqr.area(8);
    rect rt(8, 9); rt.disp();
}
using namespace std;
class shape{
    protected: int l, b;
    public:
    shape(int l, int b) {
        this -> l = l; this -> b = b;
    }
    int area(){ return l * b;}
};
class rect: public shape{
    public:
    rect(int l, int b): shape(l, b){}
    int area(){ return l * b; }
    int perimeter(){ return 2 * (l + b); }
};
class circle: public shape{
    public:
    circle(int r): shape(r, r){}
    int area(){ return 3.1416 * l * l; }
};//virtual void
class shape{
    public:
    virtual void calculate(){ cout << "area\n";}
    virtual ~shape(){ cout << "shape-Destruct\n";}
};
class rect : public shape {
    public: int l, b;
    void calculate() {
        cin >> l >> b; cout << l * b << "\n";
    }
    ~rect(){ cout << "rect-destruct\n";}
};
class quad : public shape {
    public: int l;
    void calculate() {
        cin >> l; cout << l * l << "\n";
    }
    ~quad(){ cout << "quad-destruct\n";}
};
int main(){
    rect rc(8, 9); circle cr(9);
    cout << rc.area() << " " << rc.perimeter() << " " << cr.area() << "\n";
    shape *sp; rect rc; sp = &rc;
    sp -> calculate();
    quad qd; sp = &qd; sp -> calculate();
}
