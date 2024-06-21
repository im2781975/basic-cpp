#include <bits/stdc++.h>
using namespace std;
class shape{
    public:
    int hight, width;
    shape(int hight, int width){
        this->hight = hight;
        this->width = width;
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
    Rectangle rect(67, 2);
    cout << "Area of Rectangle: " << rect.area() << "\n";
    circle cir(5);
    cout << "Area of Circle: " << cir.area();
}
