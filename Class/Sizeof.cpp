#include<bits/stdc++.h>
using namespace std;
class cls{
    int x; int y; double d;
    char ch[20];
};
struct str{
    int x; float y; double d;
    char ch[20];
}s;
union uni{
    int x; float y; double d;
    char ch[20];
}u;
int main(){
    cls c;   
    cout <<"Size of class std is in bytes  : " << sizeof(c);
    cout << "\nSize of structure is :" <<  sizeof(s) ;
    cout << "\nSize of union is: "<<sizeof(u) ;
}
