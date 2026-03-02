// Function to check value of bit position whether it is zero or one
#include <bits/stdc++.h>
using namespace std;
 
// index >> 5 corresponds to dividing index by 32
// index & 31 corresponds to modulo operation of index by 32
bool checkbit(int array[], int index)
{
    return array[index >> 5] & (1 << (index & 31));
}
// Sets value of bit for corresponding index
void setbit(int array[], int index)
{
    array[index >> 5] |= (1 << (index & 31));
}
int main()
{
    int a = 2, b = 10;
    int size = abs(b - a)+1;
 
    // Size that will be used is actual_size/32
    size = ceil((double)size/32);
    int* array = new int[size];
    for (int i = a; i <= b; i++)
        if (i % 2 == 0 || i % 5 == 0)
            array[i - a] = 1;
 
    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)
        if (array[i - a] == 1)
            cout << i << " ";
    for (int i = a; i <= b; i++)
        if (i % 2 == 0 || i % 5 == 0)
            setbit(array, i - a);
 
    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)
        if (checkbit(array, i - a))
            cout << i << " ";
    return 0;
}
