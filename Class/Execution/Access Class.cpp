#include <bits/stdc++.h>
using namespace std;
class Test{
    public:
    void main(int s){
        cout << s << "\n";
    }
    void main(const char *s){
        cout << s << "\n";
    }
    void main(int m, int s){
        cout << s << " " << m << "\n";
    }
};
class Animal{
    public:
    string color = "Black";
};
class Dog:public Animal{
    public:
    string color = "shadow";
};
class cat:public Animal{
    public:
    string color = "white";
};
int main(){
    Animal x = Dog();
    cout << x.color << "\n";
    Animal:Dog d;
    cout << d.color << "\n";
    
    Test t;
    t.main(56);
    t.main("I love c++");
    t.main(7, 9);
}
