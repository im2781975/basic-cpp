#include <iostream>
using namespace std;
int main() {
    int* p = new int(25);
    float* q = new float(75.25);

    struct cust {
        int p;
        cust(int q) : p(q) {}
        cust() = default;
    };

    cust* var1 = new cust;
    var1 = new cust();
    cust* var = new cust(25);

    cout << "Value of int p: " << *p << "\n";
    cout << "Value of float q: " << *q << "\n";
    cout << "Value of custom var->p: " << var->p << "\n" ;
    cout << "Value of custom var1->p: " << var1->p << "\n";

    delete p;
    delete q;
    delete var;
    delete var1;
    return 0;
}
