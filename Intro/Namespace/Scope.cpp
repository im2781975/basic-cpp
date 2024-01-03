#include <iostream>
using namespace std;
namespace first
{
    int value(){ 
        return 5;
    }
} 
namespace second
{
const double x = 100;
     double value(){ 
        return 2 * x; 
    }
} 
namespace third
{
    int val=100;
}
int val=50;
namespace
{
    int rel = 122;
}
int main()
{
    cout << first::value() << '\n';
    cout << second::value() << '\n';
    cout << second::x << '\n';
    cout << third::val << '\n';
    cout << val << '\n';
    cout <<rel;
    return 0;
}
