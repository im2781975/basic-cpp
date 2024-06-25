#include<bits/stdc++.h>
using namespace std;
class vehicle{
    void operatore(){
        cout << "Owner Name is Molla Ibrahim\n";
    }
    void piston(){
        cout << "it has Four Piston\n";
    }
    public:
    void company(){
        cout << "Company name: TOYOTA\n";
    }
    void model(){
        cout << "Model Number: Yaris 5008\n";
    }
    void color(){
        cout << "Color is: Golden\n";
    }
    void oil(){
        cout << "Oil is petrol\n";
    }
    void cost(){
        cout << "Cost Between 2000 - 5000";
    }
    void show(vehicle &v){
        v.operatore();
        v.piston();
    }
};
int main(){
    vehicle vec;
    vec.color();
    vec.show(vec);
    vec.cost();
}
