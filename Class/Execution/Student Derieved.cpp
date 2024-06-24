#include <bits/stdc++.h>
using namespace std;
class student{
    int roll;
    string name;
    double fee;
    public:
    //copy constructor (member wise initialization)
    student(student &t){
        this->roll = t.roll;
        this->name = t.name;
    }
    void show(){
        cout << "\nName: " << name << "\nroll: " << roll << "\n";
    }
    student(int roll, string name, double fee);
    void display();
    //student();
    //void display();
};
student::student(int roll, string name, double fee){
    this->roll = roll;
    this->name = name;
    this->fee = fee;
}/*
student::student(){
    cout << "\nEnter Name: ";
    cin >> name;
    cout << "\nEnter Roll: ";
    cin >> roll;
    cout << "\nEnter Fee: ";
    cin >> fee;
}*/
void student::display(){
    cout << "Name: " << name << "\nroll: " << roll << "\nfee: " << fee << "\n";
}
int main(){
    student stud(1000, "ibrahim", 2340);
    stud.display();
    
    student Molla(stud);
    Molla.show();
    
    student s;
    s.display();
}
