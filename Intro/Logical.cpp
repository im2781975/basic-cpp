//logical AND, OR, NOT Operator 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int age = 25; 
    bool isStudent = true; 
  
    if (age > 18 && isStudent) 
        cout <<"\nYou are eligible for a student discount.";
    else
        cout << "\nYou are not eligible for a student discount.";
    int num = 7; 
    if (num <= 0 || num >= 10) 
        cout  << "\nThe number is outside the range of 0 to 10." ;
    else 
        cout << "\nThe number is between 0 to 10." ;
    bool isLoggedIn = false; 
  
    // using logical not operator 
    if (!isLoggedIn) 
        cout << "\nPlease log in to access this feature.";
    else 
        cout << "\nWelcome !" ; 
        return 0; 
}
