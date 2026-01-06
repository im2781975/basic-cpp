#include<bits/stdc++.h>
using namespace std;
class box {
    int length, breadth, height;
    public:
    void set(int length, int breadth, int height) {
        this -> length = length;
        this -> breadth = breadth;
        this -> height = height;
    }
    void display(){
        cout << length << " " << breadth << " " << height << "\n";
        cout << "volume is: " << length * breadth * height << "\n";
    }
    box operator + (const box &bx){
        box newbx;
        newbx.length = this -> length + bx.length;
        newbx.breadth = this -> breadth + bx.breadth;
        newbx.height = this -> height + bx.height;
        return newbx;
    }
};
class Box {
    static int length, breadth, height;
    public:
    void print(){
        cout << length << " " << breadth << " " << height << "\n";
    }
};
int Box :: length = 10;
int Box :: breadth = 20;
int Box :: height = 30;
int main(){
    box ax, bx; bx.set(5, 8, 9); ax.set(4, 7, 9);
    bx.display(); ax.display();
    box cx = ax + bx; cx.display();
    Box b; b.print();
}
