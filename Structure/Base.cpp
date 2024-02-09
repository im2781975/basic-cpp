#include <bits/stdc++.h>
using namespace std;
class Number {
    private:
    int a, b;
    public:
    Number(int x, int y)
    {
        a = x;
        b = y;
    }
    // Function that find the GCD of two numbers a and b
    int gcd()
    {
        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
class MyPrimeException {
};
int main()
{
    int x = 13, y = 56;
    Number num1(x, y);
    cout << "GCD is = "
         << num1.gcd() << endl;
    // If X is prime
    if (num1.isPrime(x))
        cout << x << " is a prime number" << "\n";
    if (num1.isPrime(y))
        cout << y << " is a prime number" << "\n";
  
    // Exception Handling
    if ((num1.isPrime(x))
        || (num1.isPrime(y))) {
  
        // Try Block
        try {
            throw MyPrimeException();
        }
        // Catch Block
        catch (MyPrimeException t){
            cout << "Caught exception of MyPrimeException class." << "\n";
        }
    }
    return 0;
}
