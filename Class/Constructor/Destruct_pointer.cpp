#include<bits/stdc++.h>
using namespace std;
class Test{
    ~Test(){}
    friend void Destruct(Test*);
};
// Only this function can destruct objects of Test
void Destruct(Test *ptr){
    delete ptr;
}
int main(){
    Test *ptr = new Test;
    Destruct(ptr);
}

