#include <bits/stdc++.h>
using namespace std;
enum class color{
    red, green, blue
};
enum class color2{
    red, black, white
};
enum class people{
    good, bad
};
int main(){
    //An enum value can now be used to create variables
    int green = 10;
    
    color x = color::green;
    if(x == color::red)
        cout << "it's red\n";
    else
        cout << "it's not red\n";
    people p = people::good;
    if(p == people::good)
        cout << "He's good\n";
    else
        cout << "He's Bad\n";
    /*if(x == p)
        cout<<"red is equal to good"
    // it's not type safe
    //it will give error because type conversion */
    cout << x;
    cout << "Idx of green is: " << int(x);

    enum Gender {
        Male,  Female 
    };
    enum Color { 
        Red, Green 
    };
    Gender gender = Male;
    Color color = Red;
    if (gender == Gender::Male && color == Color::Red)
    cout << "Equal\n";

    enum Gender2 {
        Other, NonBinary 
    };
    Gender2 gender2 = NonBinary;
    // This prints the integer values of gender and gender2. 
    //Enumerations are internally represented as integers starting from 0 by default.
    //So, gender (Male) is 0 and gender2 (NonBinary) is 1.
    cout << "\n" << gender << "\n" << gender2 << "\n";
    int otherVariable = 10;
    cout  <<gender << "\n";
}
