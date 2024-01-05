#include <iostream>
using namespace std;
int staticFun()
{
    cout<<"For static variables: ";
    static int count = 0;
    count++;
    return count;
}
// Function containing non-static variables memory is destroyed
int nonStaticFun()
{
    cout << "For Non-Static variables: ";

    int count = 0;
    count++;
    return count;
}
void demo()
{
    static int count = 0;
    cout << count << " ";

    count++;
}
int main()
{
    cout << staticFun() << "\n";
    cout << staticFun() << "\n";
     
    cout << nonStaticFun() << "\n";
    cout << nonStaticFun() << "\n";
    
    for (int i = 0; i < 5; i++)
        demo();
     
    return 0;
}
