//find the only repeating element in sorted array using adjacent_find
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A[]{ 10, 13, 16, 16, 18 };
    int n =sizeof(A) /sizeof(A[0]);
 
    int* it = adjacent_find(A, A + n);
 
    cout<<"repeated element is: ";
    cout << *it;
}