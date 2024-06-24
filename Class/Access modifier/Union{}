#include <bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    //union that can store either an integer (standard) or a character (section).
    //unions are designed to save memory by sharing the same memory space for different member types.
    union{
        int standard;
        char section;
    };
};
int main(){
    student a;
    a.name = "ibrahim";
    a.standard = 9;
    a.section = 'C';
    cout << a.name << "\n" << a.standard << "\n" << a.section;
}
