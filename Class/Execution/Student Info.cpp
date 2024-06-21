#include <bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int age, std_id;
    string father_name, mother_name;
    student(){}
    student(string name, int age, int id, string f_name, string m_name){
        this->name = name;
        this->age = age;
        std_id = id;
        father_name = f_name;
        mother_name = m_name;
    }
    student(string str, int digit, int num){
        name = str;
        age = digit;
        std_id = num;
    }
    void setInformation(string str, int num, int digit)
    {
        name = str;
        std_id = num;
        age = digit;
    }
    void print(){
        cout << "Name: " << name <<"\n" ;
        cout << "Age: " << age << "\n";
        cout << "Student id: " << std_id << "\n";
        cout << "Father name: " << father_name << "\n";
        cout << "Mother name: " << mother_name << "\n\n";
    }
    /*~student(){
        cout << "\nDestructor Called\n";
        print();
    }*/
    bool operator < (student s){
        return std_id < s.std_id;
    }
};
bool comp(student a, student b){
    //when (a < b)
    if(a.std_id == b.std_id)
        return a.age < b.age;
    else
        return a.std_id < b.std_id;
}
int main(){
    student s;
    s.setInformation("X", 29, 35);
    s.print();
    vector <student> stud;
    for(int i = 0; i < 10; i++)
        stud.push_back(student("A", 20 - i, 20 + i));
    for(int i = 0; i < 10; i++)
        stud[i].print();
    sort(stud.begin(), stud.end());
    for(int i = 0; i < 10; i++)
        stud[i].print();
}
