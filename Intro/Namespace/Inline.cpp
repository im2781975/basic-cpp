#include <iostream>
using namespace std;
  
namespace first
{
    inline namespace second
    {
        inline namespace third
        {
            int var = 10;
        }
    } 
} 
int main()
{
    cout << first::var;
    return 0;
}
