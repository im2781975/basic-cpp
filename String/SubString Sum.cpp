#include <bits/stdc++.h>
using namespace std;
int toDigit(char ch)
{
    return (ch - '0');
}
// Returns sum of all substring of num
int sumOfSubstrings(string num)
{
    int n = num.length();
    int sumofdigit[n];
    
    sumofdigit[0] =toDigit(num[0]);
    int res = sumofdigit[0];

    for (int i = 1; i < n; i++) {
        int numi = toDigit(num[i]);
        sumofdigit[i] = (i + 1) * numi + 10 * sumofdigit[i - 1];
        cout << i << " " << numi << " " << sumofdigit[i]<< "\n";
        res += sumofdigit[i];
    }
    return res;
}
int main()
{
    string num = "12345";
    cout << sumOfSubstrings(num) << endl;
    return 0;
}
