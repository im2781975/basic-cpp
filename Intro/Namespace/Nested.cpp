#include <iostream>
using namespace std;
namespace first
{
    namespace second
    {
        namespace third
        {
            int var = 10;
        }
        //using namespace third;
    } 
    //using namespace second;
} 
namespace base=first ::second ::third;
int main()
{
    //cout << first::var;
    cout << base ::var;
    return 0;
}
