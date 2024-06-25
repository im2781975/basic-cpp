#include <bits/stdc++.h>
using namespace std;
class shape{
    protected:
    int hight, width;
    public:
    shape(int hight, int width){
        this->hight = hight;
        this->width = width;
    }
    int area(){
        return(hight * width);
    }
};
class Rectangle:public shape{
    public:
    Rectangle(int hight, int width):shape(hight, width){}
    int area(){
        return hight*width;
    }
    int perimetre(){
        return 2 * (hight + width);
    }
};
class circle:public shape{
    public:
    circle(int radius):shape(radius, radius){};
    int area(){
        return 3.1416 * width * width;
    }
};
int main(){
    shape *s;
    Rectangle r(2, 9);
    circle c(3);
    s = &r;
    cout << "Area of Rectangle: " << s->area() << "\n";
    
    Rectangle rect(67, 2);
    cout << "Area of Rectangle: " << rect.area() << "\n";
    circle cir(5);
    cout << "Area of Circle: " << cir.area();
}
