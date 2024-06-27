#include<bits/stdc++.h>
using namespace std;
class parent {
    int x;
    public:
    class child {
        int y;
        public:
        child(int val): y(val) {}
        int GetY() {
            return y;
        }
    };
    void fun(child *n) {
        cout << n->GetY();
    }
};

int main() {
    parent::child c(20);
    parent b;
    b.fun(&c);
    return 0;
}

