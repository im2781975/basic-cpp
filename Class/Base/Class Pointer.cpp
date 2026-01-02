#include<bits/stdc++.h>
using namespace std;
class rect{
    int len, bred;
    public:
    rect(int h, int w){
        len = h;  bred = w;
    }
    int area(){
        return len * bred;
    }
};
int main(){
    int m, n; cin >> m >> n;
    unique_ptr <rect> x(new rect(m, n));  
    cout << x->area() << "\n";
    unique_ptr <rect> y = move(x); 
    cout << y->area() << "\n";
    unique_ptr <rect> z = make_unique <rect>(m, n);
    cout << z->area() << "\n";
    shared_ptr <rect> a(new rect(m, n)); cout << a->area() << "\n";
    shared_ptr <rect> b = a; cout << b -> area() << "\n";
    cout << (b.get() == nullptr) << "\n";
    cout << a.use_count() << " " << b.use_count() << "\n";
}
