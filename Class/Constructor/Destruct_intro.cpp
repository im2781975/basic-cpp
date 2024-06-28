#include<bits/stdc++.h>
using namespace std;
class Toki{
    public:
    int id;
    Toki(){
        cout << "\nDefault Constructor called";
        id = 1;
    }
    Toki(int x){
        cout << "\nParametrized Constructor called";
        id = x;
    }
    ~Toki(){
        cout << "\nDestructor called" << " " << id;
    }
};
int main(){
    Toki a;
    cout << "\nId is: " << a.id;
    Toki b(9);
    cout << "\nId is: " << b.id;
    int i = 0;
    while(i < 4){
        Toki c(i);
        cout << "\nId is: " << c.id;
        i++;
    }
}


