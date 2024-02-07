#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    arr[0] = -1;
    arr[3/2] = 1;
    arr[2] = arr[0];
    int i = 0;
    cout << "\nBased Derieved Type: ";
    while(arr[i])
    {
        cout << arr[i] << " ";
        i++;
    }
    char ar[5] = {'a', 'b', 'c'};
    cout << "\nBased Char Type: ";
    i = 0;
    while(ar[i])
    {
        cout << ar[i] << " ";
        i++;
    }
}
