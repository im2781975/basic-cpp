//find the sum in a given range in an array using sparse table.
#include <bits/stdc++.h>
using namespace std;
// Because 2^17 is larger than 10^5
const int k = 16;
// Maximum value of array
const int N = 1e5;
// k + 1 because we need to access table[r][k]
long long table[N][k + 1];
// it builds sparse table.
void buildSparseTable(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
    for (int j = 1; j <= k; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] +
               table[i + (1 << (j - 1))][j - 1];
}
// Returns the sum of the elements in the range L and R.
long long query(int L, int R)
{
    // boundaries of next query, 0-indexed
    long long answer = 0;
    for (int j = k; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = answer + table[L][j];
 
            // instead of having L', we increment L directly
            L += 1 << j;
        }
    }
    return answer;
}
//do range minimum query using sparse table
#define MAX 500
 
// lookup[i][j] is going to store minimum value in arr[i..j]. Ideally lookup table
// size should not be fixed and should be determined using n Log n. It is kept constant to keep code simple.
int lookup[MAX][MAX];
// Fills lookup array lookup[][] in bottom up manner.
void buildSparseTable(int arr[], int n)
{
    // Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {
        // Compute minimum value for all intervals with size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            // For arr[2][10], we compare arr[lookup[0][7]] 
            // and arr[lookup[3][10]]
            if (lookup[i][j - 1] < 
                        lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = 
                         lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}
// lookup[i][j] is going to store GCD of
// arr[i..j]. Ideally lookup table
// size should not be fixed and should be
// determined using n Log n. It is kept
// constant to keep code simple.
int table[MAX][MAX];
 
// it builds sparse table.
void buildSparseTable(int arr[], int n)
{
    // GCD of single element is element itself
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
 
    // Build sparse table
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1],
                    table[i + (1 << (j - 1))][j - 1]);
}
 
// Returns GCD of arr[L..R]
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range.For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute GCD of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we find GCD of arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}
int main()
{
    int arr[] = { 3, 7, 2, 5, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    buildSparseTable(arr, n);
 
    cout << query(0, 5) << endl;
    cout << query(3, 5) << endl;
    cout << query(2, 4) << endl;
 
    return 0;
}

