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
int main(){
    person pers("A", "B", "C");
    pers.print();
}

