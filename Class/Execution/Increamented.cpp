#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
class test{
    public:
    test(){
        cnt++;
        cout << "\nConstruct :" << cnt;
    }
    ~test(){
        --cnt;
        cout << "\nDestruct: " << cnt;
    }
};
int main(){
    test a, b, c, d;
}
