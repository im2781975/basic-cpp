#include <iostream>    
#include <iomanip> 
using namespace std;
int main()
{
    int number = 100; 
 
    cout << "Hex Value :" << " " << hex << number;
    cout << "\nOctal Value=" << " " << oct << number ;
 
    cout << "\nSetbase Value=" << " " << setbase(8) << number;
    cout << "\nSetbase Value=" << " " << setbase(16) << number ;
    return 0;
}
