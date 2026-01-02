#include<bits/stdc++.h>
using namespace std;
class chain{
    string ing;
    public:
    chain(const string &str = "") : ing(str){}
    void print() const { cout << ing << " "; }
    void change(const string& str) { ing = str; }
};
int main() {
    chain str1("GeeksQuiz");
    chain str2 = str1; 
    str1.print(); str2.print();
    str2.change("GeeksforGeeks");
    str1.print(); str2.print();
}
