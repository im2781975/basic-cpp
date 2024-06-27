#include<bits/stdc++.h>
using namespace std;
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
int main(){
    func();
}
