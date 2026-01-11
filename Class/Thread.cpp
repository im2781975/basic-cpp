#include<bits/stdc++.h>
using namespace std;
// Multithreading means Running multiple parts of a program at the same time
void func(int n){
    for(int i = 0; i < n; i++)
        cout << "ptr" << " ";
    cout << "\n";
}
class threadObj{
    public:
    void operator()(int n){
        for(int i = 0; i < n; i++)
            cout << "obj" << " ";
        cout << "\n";
    }
};
class base{
    public:
    void func(){
        cout << "non-static ";
    }
    static void func1(){
        cout << "static ";
    }
};
int main(){
    thread th(func, 5); th.join();
    thread t2(func, 9); t2.join();
    thread th2(threadObj(), 8); th2.join();
    auto fu = [](int n){
        for(int i = 0; i < n; i++)
            cout << "Lambda ";
        cout << "\n";
    };
    thread th3(fu, 6); th3.join();
    base b; b.func1(); b.func();
}
