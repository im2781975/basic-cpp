#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int sum = 0;
    A(){};
    A(int a, int x = 0){
        sum = a + x;
    }
    void disp(){
        cout << "\nSum is: " << sum;
    }
};
int main(){
    A a(6, 9);
    A b(2, 8);
    a.disp();
    b.disp();
}

