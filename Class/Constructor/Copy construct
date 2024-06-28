#include<bits/stdc++.h>
using namespace std;
class base{
    int id;
    public:
    void set(int x){
        id = x;
    }
    void show(){
        cout << "Id is: " << id << "\n";
    }
    base(){}
    base(base &b){
        id = b.id;
    }
};
class store{
    public:
    store(){}
    store(store &s){
        cout << "\nCopy Constructor Called";
    }
};
int main(){
    base b;
    b.set(10);
    b.show();
    base c(b);
    c.show();
    store d;
    store e(d);
}
