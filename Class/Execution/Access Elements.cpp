#include <bits/stdc++.h>
using namespace std;
class user{
    protected:
    string name;
    int age;
};
class admin:user{
    private:
    string designation;
    public:
    void set(string name, int age, string designation){
        this->name = name;
        this->age = age;
        this->designation = designation;
    }
    void show(){
        cout << "Name: " << name << "\nage: " << age << "\ndesignation: " << designation << "\n";
    }
};
class parent{
    protected:
    int x;
};
class child:public parent{
    public:
    //Child class is able to access the inherited protected
    //data members of base class
    void set(int y){
        x = y;
    }
    void show(){
        cout << x << " ";
    }
};
int main(){
    admin ad;
    ad.set("Molla", 25, "Advisor");
    ad.show();
    
    child c;
    c.set(89);
    c.show();
}
