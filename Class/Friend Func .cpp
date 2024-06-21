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
    friend void FriendFunc(base &b);
};
class F{
    public:
    void display(base &b){
        cout << "The value of Private Variable = "
             << b.x<< "\n";
        cout << "The value of Protected Variable = "
             << b.y << "\n";
    }
};
void FriendFunc(base &b){
    cout << "The value of Private Variable = "
             << b.x<< "\n";
        cout << "The value of Protected Variable = "
             << b.y << "\n";
}
int main(){
    base a;
    F fri;
    fri.display(a);
    FriendFunc(a);
    return 0;
}

