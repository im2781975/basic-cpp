#include <bits/stdc++.h>
using namespace std;
namespace first{
    class base;
}
class first::base{
    public:
    void display(){
        cout << "first:base:b\n";
    }
};
namespace second{
    void display();
    class base{
        public:
        void display();
    };
}
void second::base::display(){
    cout << "abcd\n";
}
void second::display(){
    cout << "efgh\n";
}
int main(){
    first::base b;
    b.display();
    second::base c;
    c.display();
    second::display();
}
