#include <bits/stdc++.h>
using namespace std;
class circle{
    double radius;
    public:
    void area(double r){
        radius = r;
        double area = 3.1416 * radius * radius;
        cout << "radius: " << radius << " Area: " << area << "\n";
    }
};
class triangle{
    int base, height;
    public:
    void compute_area(int h, int b){
        base = b;
        height = h;
        double area = (0.5) * base * height;
        cout << "Area of Triangle: " << area << "\n";
    }
};
class square{
    int x;
    public:
    square(int a){
        x = a;
    }
    void area(){
        cout << "Square is: " << x*x << "\n";
    }
};
class Circle
{
    float area, radius;
    public:
    void getRadius(){
        cout << "Enter radius\n";
        cin >> radius;
    }
    void findArea(){
        area = 3.14 * radius * radius;
        cout << "Area of circle=" << area;
    }
};
class construct{
    public: float area;
    construct(){
        area = 0;
    }
    construct(int a, int b){
        area =a*b;
    }
    void disp(){
        cout << "\nArea is: " << area;
    }
};
int main(){
    circle c;
    c.area(5);
    triangle t;
    t.compute_area(5, 5);
    square s(6);
    s.area();
    ////
    Circle cir;
    cir.getRadius();
    cir.findArea();
    ///
    construct c, c2(10, 20);
    c.disp();
    c2.disp();
}

