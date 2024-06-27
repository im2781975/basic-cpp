#include<bits/stdc++.h>
using namespace std;
class person{
    int id;
    string name;
    public:
    void setP(int id, string name);
    void showP();
};
void person::setP(int id, string name){
    /*cout << "Enter Id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;*/
    this->name = name;
    this->id = id;
}
void person::showP(){
    cout << "Id: " << id << "name: " << name << "\n";
}
// Inherits Person privately, meaning the public & protected 
//members of Person become private members of Student
class student:private person{
    string course;
    int fee;
    public:
    void setS(int id, string name, string course, int fee);
    void showS();
};
void student::setS(int id, string name, string course, int fee){
    setP(id, name);
   /* cout << "Enter Course: ";
    cin >> course;
    cout << "Enter fee: ";
    cin >> fee; */
    this->course = course;
    this->fee = fee;
}
void student::showS(){
    showP();
    cout << "Course: " << course << "Fees: " << fee << "\n";
}
int main(){
    student s;
    s.setS(1001, "XYZ", "ABC", 6550);
    s.showS();
}
