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
class square : public shape{
    public:
    square(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return len * wid;}
};
class rect : public shape{
    public:
    rect(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return len * wid;}
};
class Triangle : public shape{
    public:
    Triangle(int l = 0, int w = 0):shape(l, w){}
    double area() override{ return 0.5 * (len * wid);}
};
int main(){
    shape *sp; square sq(2, 9);
    sp = &sq; cout << sp->area();
    Triangle tri(6, 9);
    sp = &tri; cout << sp->area();
}
