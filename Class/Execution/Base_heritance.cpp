#include<bits/stdc++.h>
using namespace std;
class parent{
    public: int pid;
};
class child:public parent{
    public: int cid;
};
int main(){
    child c;
    c.cid = 8;
    c.pid = 10;
    cout << "Child id is: " << c.cid ;
    cout << "\nParent id is: " << c.pid;
}
