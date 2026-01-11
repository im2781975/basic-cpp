#include<bits/stdc++.h>
using namespace std;
class dist{
    float inch, feet;
    public:
    dist(): inch(0), feet(0){}
    dist(float inch, float feet) {
        this -> inch = inch;
        this -> feet = feet;
    }
    void print() { cout << inch << " " << feet << "\n"; }
    friend dist operator + (dist &,  dist &);
};
dist operator + (dist &x, dist &y){
    dist d;
    d.feet = x.feet + y.feet;
    d.inch = x.inch + y.inch;
    if(d.inch >= 12) {
        int extra = static_cast <int> (d.inch / 12);
        d.feet += extra;
        d.inch = d.inch - extra * 12;
        // (x / 12) * 12 = x % 12;
    }
    return d;
}
class Dist{
    float inch, feet;
    public:
    Dist(): inch(0), feet(0){}
    Dist(float inch, float feet) {
        this -> inch = inch;
        this -> feet = feet;
    }
    void print() { cout << inch << " " << feet << "\n"; }
    void operator -() { --feet; --inch; }
    void operator +() { ++feet; ++inch; }
    Dist operator +(Dist &x) {
        Dist d;
        d.feet = this -> feet + x.feet;
        d.inch = this -> inch + x.inch;
        if(d.inch >= 12) {
            int extra = static_cast <int> (d.inch / 12);
            d.feet += extra;
            d.inch = d.inch - extra * 12;
            // (x / 12) * 12 = x % 12;
        }
        return d;
    }
};
int main(){
    dist x(9.3f, 6.5f); dist y(7.2f, 9.7f);
    x.print(); y.print();
    dist z = x + y; z.print();
    
    Dist d(3.9, 4.7); Dist e(8.9, 7.9);
    d.print(); e.print();
    Dist f = d + e; f.print();
    +f; f.print(); -f; f.print();
}
