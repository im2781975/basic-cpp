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
int main(){
    circle c;
    c.area(5);
    triangle t;
    t.compute_area(5, 5);
    square s(6);
    s.area();
}

