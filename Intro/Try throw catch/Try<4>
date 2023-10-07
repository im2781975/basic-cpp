#include <iostream>
using namespace std;
 
class demo1 {
};
 
class demo2:public demo1{
};
class demo3{
};
 
int main()
{
    for (int i = 1; i <= 3; i++) {
        try {
            if (i == 1)
                throw demo1();
 
            else if (i == 2)
                throw demo2();
            
            else if(i == 3)
                throw demo3();
                
        }
 
        catch (demo1 d1) {
            cout << "Caught exception of demo1 class \n";
        }
 
        catch (demo2 d2) {
            cout << "Caught exception of demo2 class \n";
        }
        catch (demo3 d3) {
            cout << "Caught exception of demo3 class \n";
        }
    }
}
