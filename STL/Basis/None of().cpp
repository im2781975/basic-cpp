#include <algorithm> 
#include <iostream> 
using namespace std;
bool isEven(int a) 
    { return (a % 2); }
bool isOdd(int a) 
    { return (a % 2 == 0); }
    
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
bool comp(int a) { return a < 0;  }

int main()
{
    int arr[] = { 4, 6, 8, 12, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "\nArray contains :";
    print(arr,n);
 
    if (none_of(arr, arr + n, isPrime))
        cout << "\nAll numbers are composite.";
    else
        cout << "\nThere are primes in array ";
    
    bool even = none_of(arr, arr + n, isEven);
    bool odd =  none_of(arr, arr + n, isOdd);
 
    if ((!even) && (!odd))
        cout << "\nContains both even and odd number";
    else if ((!even) && odd)
        cout << "\nContains odd number only";
    else if (even && (!odd))
        cout << "\nContains even number only";
    else
        cout << "\nArray is empty";
        
    if (none_of(arr, arr+n, comp))
        cout << "\nNo negative elements in the range.";
    else
        cout << "\nThere is at least one negative element in the array range.";
    return 0;
}
