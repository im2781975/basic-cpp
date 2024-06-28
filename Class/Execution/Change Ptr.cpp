#include<bits/stdc++.h>
using namespace std;
class test{
    int x;
    public:
    test(int x = 0){
        this->x = x;
    }
    void change(test *t){
        *this = *t;
    }
    void print(){
        cout << "\nElements is: " << x;
    }
};
int main(){
    test t(5);
    t.print();
    test *ptr = new test(10);
    t.change(ptr);
    t.print();
}
