#include<bits/stdc++.h>
using namespace std;
class Test{
    int a;
    public:
    Test(){
        a = 1;
    }
    void fun(int a){
        cout << this->a;
        cout << a;
        cout << Test::a;
    }
};
int main(){
    Test t;
    t.fun(3);
}
