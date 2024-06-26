//Hybrid Inheritance
#include<bits/stdc++.h>
using namespace std;
class vehicle{
    public:
    vehicle(){
        cout << "vehicle\n";
    }
};
class fare{
    public:
    fare(){
        cout << "Fare\n";
    }
};
class car:public vehicle{};
class bus:public vehicle, public fare{};
int main(){
    bus b;
}
