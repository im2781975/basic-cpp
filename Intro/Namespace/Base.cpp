#include <iostream>
using namespace std;
namespace first
{
   void func()
   {
      cout << "first"<< "\n";
   }
   namespace second
   {
        void func()
        {
            cout << "second"<<"\n";
        }
   }
}
namespace third
{
    void func()
    {
        cout<< "Third" << "\n";
    }
}
using namespace first::second;
int main ()
{
    func();
    first::func();
    first::second::func();
    third::func();
   return 0;
}
