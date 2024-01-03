#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 45;
    }
    catch (char *excp)  
    {cout << "Caught " << excp<<endl;}
    catch (int excp) {
        cout << "Caught " << excp << endl;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
