#include <iostream>
using namespace std;
int main()
{
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially ";
            throw;
        }
    }
    catch (int n) {
        cout << "Handle remaining ";
    }
    return 0;
}
