#include<bits/stdc++.h>
using namespace std;
//Fast input function
inline long long int fast_input(void)
{
    char t;
    long long int x = 0;
    long long int neg = 0;
    t = getchar();
    while ((t < '0' || t > '9') && t != '-')
        t = getchar();
    if (t == '-') // Handle negative input
    {
        neg = 1;
        t = getchar();
    }
    while (t >= '0' && t <= '9')
    {
        x = (x << 3) + (x << 1) + t - '0';

        // x << 3 means 8*x and x << 1 means 2*x, so we have x = 10*x + (t - '0')
        t = getchar();
    }

    if (neg)
        x = -x;
    return x;
}

// Fast output function
inline void fast_output(long long int x)
{
    char buffer[21]; // Buffer for storing the output characters
    int i = 0;
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x == 0)
    {
        putchar('0');
        return;
    }
    while (x)
    {
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        putchar(buffer[j]);
    }
}

int main()
{
    long long int x = fast_input();
    fast_output(x);
    return 0;
}
