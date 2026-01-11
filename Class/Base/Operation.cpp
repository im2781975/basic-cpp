#include<bits/stdc++.h>
using namespace std;
class operation{
    int a, b;
    public:
    void get(); void sum(); void mul();
    void diff(); bool division(); void rem();
};
inline void operation:: get(){ cin >> a >> b; }
inline void operation:: sum(){ cout << a + b << "\n"; }
inline void operation:: mul(){ cout << a * b << "\n"; }
inline void operation:: diff(){ cout << a - b << "\n"; }
inline void operation:: rem(){ cout << a % b << "\n"; }
bool operation:: division(){
    if(b != 0) {
        cout << static_cast <float> (a) / b; return true;
    }
    else    return false;
}
class calculator{
    public:
    int add(int x, int y){ return x + y; }
    int diff(int x, int y){ 
        if(x > y)    return (x - y);
        else    return (y - x);
    }
    int mul(int x, int y){ return x * y; }
    float divi(int x, int y){ 
        return x / y;
    }
    int rem(int x, int y){ return x % y; }
};
class riga{
    int arr[3];
    public:
    riga(int i, int j, int k){ arr[0] = i; arr[1] = j; arr[2] = k; }
    int operator[](int i){ return arr[i]; }
};
class A{
    int a, b, c;
    public:
    void add(int x, int y, int z = 0) {
        a = x; b = y; c = z; cout << a + b + c << "\n";
    }
    virtual void print(){ cout << "class-A\n"; }
};
class B : public A{
    public:
    void print(){ cout << "class-B\n"; }
    void sm(int x, int y){ add(x, y); }
};
class base {
    int a, b;
    public:
    int ope(int x) {
        a = x; b = a / 2; return b;
    }
    void print(){ cout << a << " " << b << "\n"; }
};
class line {
    double len;
    public:
    line(double ln); void set(double ln);
    double get(void);
};
line:: line(double len){ this -> len = len;}
void line:: set(double l){ len = l; }
double line:: get(void){ return len; }
int main(){
    operation opt; opt.get(); opt.sum();
    opt.diff(); opt.mul(); opt.rem();
    if(!opt.division()){}
    calculator cal;
    cout << cal.add(7, 9) << " " << cal.diff(7.20, 9.89) << endl;
    cout << cal.mul(8.9f, 6.9f) << " " << cal.divi(7, 9) << endl;
    
    riga r(4, 6, 8); cout << r[1] << "\n";
    B b; b.print(); b.add(8, 5, 9);
    base bs; bs.ope(52); bs.print();
    line ln(29.35); cout << ln.get() << "\n";
}
#include<bits/stdc++.h>
using namespace std;
class base {
    int cnt;
    public:
    base(int n): cnt(n){}
    base operator ++(int) { return (++cnt);}
    base operator ++() { cnt += 1; return *this; }
    void disp(){ cout << cnt << " "; }
}; 
class complx {
    int real, img;
    public:
    complx(int real, int img) {
        this -> real = real; 
        this -> img = img;
    }
    void disp(){ cout << real << " + i" << img << endl; }
    complx operator + (complx &b) {
        return complx(real + b.real, img + b.img);
    }
    friend complx operator+(complx &, complx &);
};
complx operator+(complx &a, complx &b){
    return complx(a.real + b.real, a.img + b.img);
} 
class fract{
    int num, dig;
    public:
    fract(int num, int dig){
        this->num = num; this->dig = dig; }
    operator float(){
        return float(num)/float(dig);
    }
};
int main(){
    base b(5), pref(5), postf(5);
    pref = ++b; b.disp(); pref.disp();
    b++; b++; (++b).disp(); b.disp();
    
    complx c1(3, 4); complx c2(5, 7);
    complx c3; c3 = c1 + c2; c3.disp();
    complx c4 = operator+(c1, c2);
    c4.disp();
    fract f(9, 11); cout << f;
}
