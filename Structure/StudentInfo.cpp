#include<bits/stdc++.h>
using namespace std;
union geek {
    int age;
    char grade;
    float GPA;
    double marks;
};
int main()
{
    union geek student1;

    student1.age = 25;
    cout<<"Age: "<<student1.age <<" "<<cout<<"Memory address is: "<<&student1.age<<"\n";
  
    student1.grade = 'B';
    cout<<"grade: "<<student1.grade <<" "<<cout<<"Memory address is: "<<&student1.grade<<"\n";
  
    student1.GPA = 4.5;
    cout<<"GPA: "<<student1.GPA <<" "<<cout<<"Memory address is: "<<&student1.GPA<<"\n";
    student1.marks=88.75;
    cout<<"marks: "<<student1.marks<<" "<<cout<<"Memory address is: "<<&student1.marks<<"\n";
  
    cout << "Size of a union: "<< sizeof(student1) <<"\n";
  
  
    return 0;
}
