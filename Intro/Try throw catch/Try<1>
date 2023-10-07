#include <iostream>
using namespace std;

void fun(int *ptr, int x) {
    try {
        if (ptr == NULL)
            throw ptr;
        if (x == 0)
            throw x;
    }
    catch (int *ptrException) {
        cout << "Caught exception: Null pointer" <<"\n";
    }
    catch (int xException) {
        cout << "Caught exception: Division by zero" << endl
    }
}

int main() {
    fun(NULL, 0);
    return 0;
}

