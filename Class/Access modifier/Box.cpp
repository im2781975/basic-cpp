#include <bits/stdc++.h>
using namespace std;
class box{
    int length, breadth, height;
    public:
    void set(int length, int breadth, int height){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    void display(){
        cout << "Length: " << length << "\nBreadth: " << breadth << "\nHeight: " << height << "\n";
    }
    void volume(){
        int v = length * breadth * height;
        cout << "Volume is: " << v << "\n";
    }
    box operator +(const box & b){
        box newb;
        newb.length = this->length + b.length;
        newb.breadth = this->breadth + b.breadth;
        newb.height = this->height + b.height;
        return newb;
    }
};
int main(){
    box x, y;
    x.set(12, 13, 14);
    y.set(15, 16, 17);
    box z = x + y;
    z.display();
    z.volume();
}
