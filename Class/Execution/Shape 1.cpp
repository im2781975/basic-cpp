#include<bits/stdc++.h>
using namespace std;
class shape{
    public:
    string name;
    int side;
    shape(string name, int side){
        this->name = name;
        this->side = side;
    }
};
class triangle:public shape{
    int base, height;
    public:
    triangle(string name, int side, int base, int height):shape(name, side){
        this->base = base;
        this->height = height;
    }
    void area(){
        cout << "\nArea Of Triangle are: " << (0.5 * base * height);
    }
    void print(){
        cout << "\nShape is: " << name;
        cout << "\nSides are: " << side;
        cout << "\nBase is: " << base;
        cout << "\nHeight is: " << height;
    }
};
class square:public shape{
    int height;
    public:
    square(string name, int side, int height):shape(name, side){
        this->height = height;
    }
    void area(){
        cout << "\nArea Pf Square is: " << height * height;
    }
    void print(){
        cout << "\nShape is: " << name;
        cout << "\nSides are: " << side;
        cout << "\nHeight is: " << height;
    }
};
int main(){
    triangle t("triangle", 3, 2, 5);
    t.print();
}
