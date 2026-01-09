#include<bits/stdc++.h>
using namespace std;
class person {
    int id; string name;
    public:
    void place(int id, string name) {
        // cin >> id >> name;
        this -> id = id; this -> name = name;
    }
    void print(){ cout << id << " " << name << endl; }
};
class student: private person {
    int fee; string course;
    public:
    void set(int id, string name, int fee, string course){
        place(id, name); // cin >> fee >> course;
        this-> fee = fee; this-> course = course;
    }
    void show(){
        person::print();
        cout << fee << " " << course << endl;
    }
    union{ int standard; char section;
    };
};
int main(){
    student sud; sud.set(2045, "ABC", 340, " XYZ"); sud.show();
    sud.standard = 8; sud.section = "x";
    cout << sud.standard << " " << sud.section;
}
using namespace std;
class student {
    public:
    static int total;
    student(){ total += 1;}
};
int student:: total = 0;
int main(){
    student a; cout << a.total << " ";
    student b; cout << b.total << " ";
    student c; cout << c.total << " ";
    student d; cout << d.total << " ";
}
using namespace std;
class student{
    public:
    string name, pa, ma; int id, age;
    student(){}
    student(string name, string pa, string ma, int id, int age) {
        this -> name = name;
        this -> pa = pa; this -> ma = ma;
        this -> id = id; this -> age = age;
    }
    student(const student &sud){
        this -> name = sud.name;
        this -> pa = sud.pa; this -> ma = sud.ma;
        this -> id = sud.id; this -> age = sud.age;
    }
    student(string str, int dig, int num){
        name = str; id = dig; age = num;
    }
    void set(string str, int dig, int num){
        name = str; id = dig; age = num;
    }
    void print(){
        cout << name << " " << pa << " " << ma << " " << id << " " << age << "\n";
    }
    //~student(){ cout << "Destructor\n"; print(); }
    bool operator < (student s) { return id < s.id; }
};
bool comp(student a, student b){
    if(a.id == b.id) return a.age < b.age;
    else return a.id < b.id;
}
int main(){
    student sud; sud.set("X", 29, 35); sud.print();
    student ola(sud); ola.print();
    vector <student> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(student("A", 20 - i, 20 + i));
    for(int i = 0; i < 10; i++)
        vec[i].print();
    sort(vec.begin(), vec.end());
    for(int i = 0; i < 10; i++)
        vec[i].print();
}
using namespace std;
class person {
    public:
    string name; person *pa, *ma;
    person(): pa(NULL), ma(NULL){}
    person(string name, string dad, string mom) {
        this -> name = name;
        pa = new person; pa -> name = dad;
        ma = new person; ma -> name = mom;
    }
    void print(){ cout << name << " " << pa -> name << " " << ma -> name << endl;
    ~person(){
        if(pa != NULL) delete pa;
        if(ma != NULL) delete ma;
    }
};
int main(){
    person pers("A", "B", "C");
    pers.print();
}
