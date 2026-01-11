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
using namespace std;
class cuboid {
    int l, b, h;
    public:
    cuboid(): l(0), b(0), h(0){}
    cuboid(int l, int b, int h) {
        this -> l = l; this -> b = b; this -> h = h;
    }
    int getvlm() { return l * b * h; }
    int facedarea() { return 2 * (l * b + b * h + l * h); }
    static bool cmpsur(cuboid a, cuboid b){
        return a.facedarea() > b.facedarea();
    }
    static bool cmpvlm(cuboid a, cuboid b){
        return a.getvlm() < b.getvlm();
    }
};
bool cmpsur(cuboid a, cuboid b){ return a.facedarea() > b.facedarea(); }
bool cmpvlm(cuboid a, cuboid b){ return a.getvlm() > b.getvlm(); }
class cube {
    int l, *b, h;
    public:
    cube(){ b = new int; }
    void set(int l, int w, int h){
        this -> l = l; *b = w; this -> h = h;
    }
    void disp(){
        cout << l << " " << *b << " " << h << "\n";
    }
    cube(const cube &x) {
        l = x.l; b = new int;
        *b = *(x.b); h = x.h;
    }
    cube operator + (cube &x){
        cube ub;
        ub.l = this -> l + x.l;
        ub.b = new int;
        *(ub.b) = *(this -> b) + *(x.b);
        ub.h = this -> h + x.h;
        return ub;
    }
    ~cube(){ 
        cout << "called\n";// delete b;
    }
};
int main(){
    cuboid cub[11]; int n = 5;
    for(int i = n; i >= 0; i--) {
        cub[i] = cuboid(i + 10, i + 5, i + 2);
        cout << cub[i].getvlm() << " " <<  cub[i].facedarea() << "\n";
    }
    // sort(cub, cub + n, cmpvlm);
    sort(cub, cub + n, cmpsur);
    for(int i = 0; i < n; i++){
        cout << cub[i].getvlm() << " " << 
        cub[i].facedarea() << "\n";
    }
    cube c, d, e;
    c.set(23, 12, 11); c.disp();
    d.set(11, 12, 23); d.disp();
    e = c + d; e.disp();
}
