#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    void print(){
        cout << "Here I am\n";
    }
};
class student{
    public:
    static int total;
    student(){
        total += 1;
        
    }
};
int student::total = 0;
class Test{
    int a;
    public:
    Test(){
        a = 1;
    }
    void fun(int a){
        cout << this->a;
        cout << a;
        cout << Test::a;
    }
};
int main(){
//If we Declare all variable consecutively it will print same value.
    //For that Have to declare separetly
    student a;
    cout << "Number of Student: " << a.total << "\n";
    student b;
    cout << "Number of Student: " << b.total << "\n";
    student c;
    cout << "Number of Student: " << c.total << "\n";
    // 
    base b;
    for(int i = 0; i < 5; i++)
        b.print();
    //
    Test t;
    t.fun(3);
}

