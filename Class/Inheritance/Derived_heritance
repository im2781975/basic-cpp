#include<iostream>
using namespace std;
class Person {
    public:
    Person(int x){ 
        cout << "\nPerson called";
    }
    Person(){ 
        cout << "Person () called";
    }
};
class Faculty : public Person {
    public:
//The Faculty class inherits from Person and its constructor takes an integer parameter x, 
//which it passes to the Person constructor. After calling the Person constructor, it prints "Faculty called".
    Faculty(int x):Person(x){
       cout <<"\nFaculty called" ;
    }
};
class Student : public Person {
    public:
    Student(int x):Person(x){
        cout<<"\nStudent called";
    }
};
class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x){
        cout<<" \nTA called" ;
    }
};
class Person {
    public:
    Person(int x) { 
        cout << "\nPerson called" ;
    }
    Person(){  
        cout<<"\nPerson () called";
    }
};
class Faculty : virtual public Person{
    public:
    Faculty(int x):Person(x){
       cout<<"\nFaculty called";
    }
};
class Student : virtual public Person{
    public:
    Student(int x):Person(x){
        cout<<"\nStudent called";
    }
};
class TA : public Faculty, public Student{
    public:
    TA(int x):Student(x), Faculty(x), Person(x){
        cout<<"\nTA called" ;
    }
};
int main()  {
    TA ta1(30);
}
