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
namespace out
{
    int val = 5;
    namespace in
    {
        int v =val;
    }
}
int main()
{
    //cout << first::var;
    cout << base ::var;
    cout << out :: in::v;
    return 0;
}
