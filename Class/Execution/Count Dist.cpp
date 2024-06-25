// operator overloading using a Friend Function
#include <bits/stdc++.h>
using namespace std;
class Distance{
    float inch, feet;
    public:
    Distance(){}
    Distance(float inch, float feet){
        this->inch = inch;
        this->feet = feet;
    }
    void print(){
        cout << "Feet: " << feet << "\nInch: " << inch << "\n";
    }
    friend Distance operator + (Distance&, Distance &);
};
Distance operator+(Distance &d1, Distance &d2){
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inch = d1.inch + d2.inch;
    if (d.inch >= 12) {
        d.feet += static_cast<int>(d.inch / 12);
        d.inch = d.inch - static_cast<int>(d.inch/12) *12;
    }
    return d;
}
//Without Friend Func
class Dist{
    float feet, inch;
    public:
    Dist(){}
    Dist(float inch, float feet){
        this->inch = inch;
        this->feet = feet;
    }
    void print(){
        cout << "\nFeet: " << feet << " Inch: " << inch;
    }
    Dist operator +(Dist &d){
        Dist c;
        c.feet = this->feet + d.feet;
        c.inch = this->inch + d.inch;
        if(c.inch > 12){
            c.feet += static_cast<int>(c.inch/12);
            c.inch -= static_cast<int>(c.inch/12)*12;
        }
        return c;
    }
};
int main(){
    Distance d1(6.7f, 2.9f);
    Distance d2(5.5f, 11.3f);
    Distance d3 = d1 + d2;
    d3.print();
    
    Dist d(3.9, 4.7);
    Dist e(8.9, 7.9);
    Dist f = d + e;
    d.print();
    e.print();
    f.print();
}
