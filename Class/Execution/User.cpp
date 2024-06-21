#include <bits/stdc++.h>
using namespace std;
class user{
    protected:
    string name;
    int age;
};
class admin : user{
    private:
    string designation;
    public:
    void set(string str, int digit, string desig){
        name = str;
        age = digit;
        designation = desig;
    }
    void print(){
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Designation: " << designation << "\n";
    }
};
int main(){
    admin ad;
    ad.set("XYZ", 20, "Operator");
    ad.print();
}
