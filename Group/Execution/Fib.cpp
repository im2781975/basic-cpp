#include <iostream>
using namespace std;
int called = 0;
int save[100];
// fib sum;
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (save[n] != 0) return save[n];
    int x = fib(n - 1);
    int y = fib(n - 2);
    save[n] = x + y;
    return x + y;
}
// find idx of x
int fibonacciSearch(int arr[], int n, int x) {
    if (n == 0) return -1;
    int fib1 = 0, fib2 = 1, fib3 = fib1 + fib2;
    while (fib3 < n) {
        fib1 = fib2; fib2 = fib3;
        fib3 = fib1 + fib2;
    }
    int offset = -1;
    while (fib3 > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fib3 = fib2; fib2 = fib1;
            fib1 = fib3 - fib2; offset = i;
        }
        else if (arr[i] > x) {
            fib3 = fib1; fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }
        else return i;
    }
    if (fib2 == 1 && arr[offset + 1] == x) return offset + 1;
    else return -1;
}
