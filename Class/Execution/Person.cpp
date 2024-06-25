#include<bits/stdc++.h>
using namespace std;
class person{
    public:
    string name;
    person *father, *mother;
    person(){
        father = NULL;
        mother = NULL;
    }
    person(string name, string f_name, string m_name){
        this->name = name;
        father = new person;
        father->name = f_name;
        mother = new person;
        mother->name = m_name;
    }
    void print(){
        cout << "Name: " << name << "\n";
        cout << "Father name: " << father->name << "\n";
        cout << "Mother name: " << mother->name << "\n";
    }
    ~person(){
        cout << "called";
        if(father!=NULL)
            delete father;
        if(mother!=NULL)
            delete mother;
    }
};
class student{
    string name;
    int age;
    public:
    student(string name, int age){
        this->name = name;
        this->age = age;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setAge(int age){
        this->age = age;
    }
    int getAge(){
        return age;
    }
};
int main(){
    person pers("A", "B", "C");
    pers.print();
    
    student p("Molla", 23);
    cout << "Name: " << p.getName() << "\nAge: " << p.getAge() << "\n";
    p.setName("Hasan");
    p.setAge(22);
    cout << "Name: " << p.getName() << "\nAge: " << p.getAge() << "\n";
}

