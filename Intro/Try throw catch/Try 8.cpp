#include <iostream>
using namespace std;
int main() {
    int x=89;
    try {
        if (x <= 0 || x>=0) {
            throw x;
        }
    }
    catch (int &x) {
        cout << "Exception occurred: thrown value is " << x << "\n";
    }
    getchar();
    return 0;
}
