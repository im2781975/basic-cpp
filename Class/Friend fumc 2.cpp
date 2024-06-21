//demonstrate  how friend functions work as a bridge between the classes
#include <bits/stdc++.h>
using namespace std;
class start;
class end{
    int x;
    public:
    void set(int a){
        x = a;
    }
    friend void max(start,end);
};
class start{
    int y;
    public:
    void set(int a){
        y = a;
    }
    friend void max(start,end);
};
void max(start l, end r){
    if(l.y > r.x)
        cout << l.y<< " ";
    else
        cout << r.x <<  " ";
}
int main(){
    start l;
    end r;
    l.set(23);
    r.set(45);
    max(l, r);
    return 0;
}

