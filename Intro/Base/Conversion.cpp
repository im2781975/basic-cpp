#include <iostream>    
#include <iomanip> 
using namespace std;
int main()
{
    int number = 100; 
    cout << "Hex Value :" << " " << hex << number;
    cout << "\nOctal Value=" << " " << oct << number ;
 
    cout << "\nSetbase Value=" << " " << setbase(8) << number;
    cout << "\nSetbase Value=" << " " << setbase(16) << number;
    //typeid
    auto int_=32;
    auto bool_=true;
    auto float_=21.89;
    auto ptr= &float_ ;
    
    cout<< typeid(int_).name() <<" \n";
    cout<<typeid(bool_).name() <<" \n";
    cout<<typeid(float_).name() <<" \n";
    cout<<typeid(ptr).name() <<" \n";
    return 0;
}
