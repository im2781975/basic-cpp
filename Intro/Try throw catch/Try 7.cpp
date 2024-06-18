#include <iostream>
using namespace std;
class demo {
    int num;
    public:
    demo(int x)
    {
        try {
            if (x == 0)
                throw "Zero not allowed ";
 
            num = x;
            show();
        }
        catch (const char* exp) {
            cout << "Exception caught \n ";
            cout << exp << endl;
        }
    }
    void show()
    {
        cout << "Num = " << num << endl;
    }
};
int main()
{
    demo(0);
    cout << "Again creating object \n";
    demo(1);
}
#include<bits/stdc++.h>
using namespace std;
class demo{
    int num;
    public:
    demo(int x){
        try{
            if(x == 0)
                throw "Zero not allowed";
            num = x;
            show();
        }
        catch(const char *ex){
            cout << ex;
        }
    }
    void show(){
        cout << num;
    }
};
int main(){
    demo(-1);
}
