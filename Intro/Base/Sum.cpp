#include <iostream>
using namespace std;
int sum(int x,int y,float z=0, float w = 0)
{
    return (x + y + z + w);
}
int main()
{
    cout << sum(10, 15, 25, 30) <<"\n";
    return 0;
}
