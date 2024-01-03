#include <iostream>
using namespace std;
int main()
{
    int x = -1;
    char* ptr;
    ptr = new char[256];
    try {
 
        if (x < 0) {
            throw x;
        }
        if (ptr == NULL) {
            throw " ptr is NULL ";
        }
    }
    catch (...) 
    {
        cout << "Exception occurred: exiting " << endl;
        exit(0);
    }
    getchar();
    return 0;
}
