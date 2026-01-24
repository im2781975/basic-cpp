#include <iostream>
using namespace std;
int main() {
    int num, test = 40; 
    num = test < 10 ? 10 : test + 10; 
  
    cout << "\nNum - Test : " << num - test; 
  
    int A = 39, B = 10, C = 23; 
    int maxNum 
        = (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C); 
    cout << "\nLargest number is " << maxNum ; 
    return 0;
}

