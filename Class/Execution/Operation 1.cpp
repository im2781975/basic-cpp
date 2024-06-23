#include <bits/stdc++.h>
using namespace std;
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
    calculator cal;
    cout << cal.add(7, 9) << endl;
    cout << cal.mult(7.20, 9.89) << endl;
    cout << cal.mult(8.9f, 6.9f);
}
