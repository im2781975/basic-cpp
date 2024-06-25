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
//area of shapes USING VIRTUAL FUNCTION
class shape{
    public:
    virtual void calculate(){
        cout << "\nArea of the shape";
    }
    // usage of virtual Destuctor to avoid memory leak
    // Declaring the destructor in the Shape class as virtual ensures that 
    //the destructors of derived classes (Rectangle and Square) are called correctly.
     //When an object of a derived class is destroyed, the destructor of the derived class
     //is called first, followed by the destructor of the base class.
    virtual ~shape(){
        cout << "\nshape Destructor Called";
    }
};
class rectangle:public shape{
    public:
    int weidth, height, area;
    void calculate(){
        cout << "\nEnter Values for Weidth & Height: ";
        cin >> weidth >> height;
        int area = weidth * height;
        cout << "\nArea Of Rectangle is: " << area;
    }
    ~rectangle(){
        cout <<"\nRectangle Destructor called";
    }
};
class Square:public shape{
    public:
    int side;
    void calculate(){
        cout << "\nEnter Values for side: ";
        cin >> side;
        int area = side * side;
        cout << area;
    }
    ~Square(){
        cout << "\nsquare Destruct called";
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
    ////////
    shape *s;
    rectangle r;
    s = &r;
    s->calculate();
    
    Square sq;
    s = &sq;
    s->calculate();
}
