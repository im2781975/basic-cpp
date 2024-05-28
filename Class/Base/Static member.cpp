//static member function
#include <iostream>
using namespace std;
class fun {
    public:
    static void disp() 
    { 
        cout << "Welcome !";
    }
};
int main()
{
    fun::disp();
}
