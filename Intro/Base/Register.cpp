//Registers are faster than memory to access, so the variables which are most frequently 
//used in a program can be put in registers using the register keyword
#include <iostream>
#include <cstdio>
using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    // Extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        // Number is negative
        negative = true;
        // Extract the next character from the buffer
        c = getchar();
    }
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0' (48) to '9' (57)
    for (; (c >= '0' && c <= '9'); c = getchar())
        number = number * 10 + c - '0';

    // If scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
    int number;
    fastscan(number);
    cout << number << "\n";
    return 0;
}

