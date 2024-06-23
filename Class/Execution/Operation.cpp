#include <bits/stdc++.h>
using namespace std;
class operation{
    int a, b, add, sub, mult;
    float div;
    public:
    void get();
    void sum();
    void product();
    void diff();
    bool division();
};
inline void operation::get(){
    cout << "Enter Elements: ";
    cin >> a >> b;
}
inline void operation::sum(){
    add = a + b;
    cout << "\nsum of the elements are: " << add;
}
inline void operation::product(){
    mult = a*b;
    cout << "\nMultiplication of the elements are: " << mult;
}
inline void operation::diff(){
    sub = a - b;
    cout << "\nSubtraction of the elements are: " << sub;
}
bool operation::division(){
    if(b != 0){
        div = static_cast <float> (a)/b;
        cout << "\nDivision of two elements are: " << div;
        return true;
    }
    else
        cout << "Zero presents";
        return false;
}
class calculator{
    public:
    int add(int a, int b){
        return a + b;
    }
    int mult(double x, double y){
        return x * y;
    }
    int mult(int x, int y){
        return x * y;
    }
    int mult(float x, float y){
        return x * y;
    }
    int sub(int a, int b){
        if(a > b)
            return a - b;
        else
            return b - a;
    }
};
int main(){
    operation opt;
    opt.get();
    opt.sum();
    opt.diff();
    opt.product();
    if(!opt.division()){}
    
    calculator cal;
    cout << cal.add(7, 9) << endl;
    cout << cal.mult(7.20, 9.89) << endl;
    cout << cal.mult(8.9f, 6.9f);
}
