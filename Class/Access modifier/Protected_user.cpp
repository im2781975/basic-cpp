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
int main(){
    admin ad;
    ad.set("Molla", 25, "Advisor");
    ad.show();
}
