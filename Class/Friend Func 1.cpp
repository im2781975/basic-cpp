//create a member function of another class as a friend function
#include<bits/stdc++.h>
using namespace std;
class base;
// another class in which function is declared
class another{
    public:
    void member(base &b);
};
// base class for which friend is declared
class base {
    int x;
    protected:
    int y;
    public:
    base():x(10), y(90){}
    friend void another::member(base &);
};
void another::member (base &b){
    cout << "Private Variable: " << b.x << endl;
    cout << "Protected Variable: " << b.y << "\n";
}
int main(){
    base b;
    another c;
    c.member(b);
}
