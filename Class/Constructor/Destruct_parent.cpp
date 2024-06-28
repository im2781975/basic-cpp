#include<bits/stdc++.h>
using namespace std;
class parent{
    ~parent(){
        cout << "\nDestructor called";
    }
    public:
    parent(){
        cout << "\nConstructor called";
    }
    void destruct(){
        delete this;
    }
};
int main(){
    parent *p = new parent;
    p->destruct();
}
