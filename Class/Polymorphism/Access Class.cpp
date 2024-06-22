#include <bits/stdc++.h>
using namespace std;
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
}
