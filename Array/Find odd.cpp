#include <iostream>
using namespace std;
 
// return the only occurring which is odd or even
int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main(void)
{
    int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Odd occurring element is : "<< findOdd(arr, n);
    
    //Here's 90 occurring only ones.so it will be print
    return 0;
}
