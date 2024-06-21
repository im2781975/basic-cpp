//friend class can access private and protected members of 
//other classes in which it is declared as a friend
#include <bits/stdc++.h>
using namespace std;
class base{
    private:
    int x;
    protected:
    int y;
    public:
    base(){
        x = 10; y = 99;
    }
    friend class F;
};
class F{
    public:
    void display(base &b){
        cout << b.x << " " <<  b.y << " ";
    }
};
int main(){
    base a;
    F fri;
    fri.display(a);
    return 0;
}
