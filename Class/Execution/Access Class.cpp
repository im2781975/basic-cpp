#include<bits/stdc++.h>
using namespace std;
class test{
    public:
    void main(int d){ cout << d << " "; }
    void main(const char *ch){ cout << ch << " ";}
    void main(int d, int g){ cout << d << " " << g << endl; }
};
class Animal {
    public:    string color = "Black";
};
class cat:public Animal {
    public:    string color = "Brown";
};
class dog:public Animal {
    public:    string color = "Gray";
};
int main(){
    Animal x = dog(); cout << x.color << "\n";
    dog d; cout << d.color << "\n";
    
    test t; t.main(56); t.main("I love c++"); t.main(7, 9);
}
