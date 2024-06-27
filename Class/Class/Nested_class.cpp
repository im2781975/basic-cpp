#include<bits/stdc++.h>
using namespace std;
//Local class
void func(){
    class test{
        public:
        static void method(){
            cout << "\nclass method";
        }
    };
    cout << "Yes\n";
    test::method();
    test t;
    t.method();
}
//Nested Class
class parent {
    int x;
    public:
    class child {
        int y;
        public:
        child(int val): y(val) {}
        int GetY() {
            return y;
        }
    };
    void fun(child *n) {
        cout << n->GetY();
    }
};
int main(){
    func();
    //
    parent::child c(20);
    parent b;
    b.fun(&c);
}
