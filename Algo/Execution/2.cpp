//Given Array of size n and a number k, find all elements that appear more than n/k times
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;
    // unordered_map initialization
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    // Traversing the map
    for (auto i : freq) {
        // Checking if value of a key-value pair is greater than x (where x=n/k)
        if (i.second > x) {
            // Print the key of whose value is greater than x
            cout << i.first << endl;
        }
    }
}
// A structure to store an element and its current count
struct eleCount {
    int e; // Element
    int c; // Count
};
// Prints elements with more than n/k occurrences in arr[] of size n. If there are no such elements, then it prints nothing.
void moreThanNdK(int arr[], int n, int k)
{
    // k must be greater than 1 to get some output
    if (k < 2)
        return;
    // Create a temporary array (contains element and count) of size k-1. Initialize count of all elements as 0 
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
 
    // Process all elements of input array
    for (int i = 0; i < n; i++) {
        int j;
        // If arr[i] is already present in the element count array, then increment its count
        for (j = 0; j < k - 1; j++) {
            if (temp[j].e == arr[i]) {
                temp[j].c += 1;
                break;
            }
        }
        // If arr[i] is not present in temp[] 
        if (j == k - 1) {
            int l;
            // If there is position available  in temp[], then place arr[i] in
             // the first available position and set count as 1
            for (l = 0; l < k - 1; l++) {
                if (temp[l].c == 0) {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
            // If all the position in the temp[] are filled, then decrease count of every element by 1
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].c -= 1;
        }
    }
    // Check actual counts of potential candidates in temp[]
    for (int i = 0; i < k - 1; i++) {
        // Calculate actual count of elements
        int ac = 0;
        // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
        // If actual count is more than n/k, then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}
// Function to find the number of array elements with frequency more than n/k times
void printElements(int arr[], int n, int k)
{
    // Calculating n/k
    int x = n/k;
    // Counting frequency of every element
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    // Traverse the map and print all the elements with occurrence more than n/k times
    for (auto it : mp)
        if (it.second > x)
            cout << it.first << endl;
}
// CPP code to answer the query in constant time
#include <bits/stdc++.h>
using namespace std;
 
/*
BOP[] stands for "Balanced open parentheses" 
BCP[] stands for "Balanced close parentheses"
 
*/
 
// function for precomputation
void constructBalanceArray(int BOP[], int BCP[],
                          char* str, int n)
{
 
    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++) {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
 
        else // If closing bracket, i.e., str[i] = ')'
        {
            // If closing bracket, i.e., str[i] = ')'
            // && stack is not empty then mark both
            // "open & close" bracket indexes as 1 .
            // Pop the previous opening bracket's index
            if (!stk.empty()) {
                BCP[i] = 1;
                BOP[stk.top()] = 1;
                stk.pop();
            }
 
            // If stack is empty.
            else
                BCP[i] = 0;
        }
    }
 
    for (int i = 1; i < n; i++) {
        BCP[i] += BCP[i - 1];
        BOP[i] += BOP[i - 1];
    }
}
 
// Function return output of each query in O(1)
int query(int BOP[], int BCP[],
          int s, int e)
{
    if (BOP[s - 1] == BOP[s]) {
        return (BCP[e] - BOP[s]) * 2;
    }
 
    else {
        return (BCP[e] - BOP[s] + 1) * 2;
    }
}
 
// Driver program to test above function
int main()
{
 
    char str[] = "())(())(())(";
    int n = strlen(str);
 
    int BCP[n + 1] = { 0 };
    int BOP[n + 1] = { 0 };
 
    constructBalanceArray(BOP, BCP, str, n);
 
    int startIndex = 5, endIndex = 11;
 
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    startIndex = 4, endIndex = 5;
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    startIndex = 1, endIndex = 5;
    cout << "Maximum Length Correct Bracket"
            " Subsequence between "
         << startIndex << " and " << endIndex << " = "
         << query(BOP, BCP, startIndex, endIndex) << endl;
 
    return 0;
}
// simplify algebraic string
#include <bits/stdc++.h>
using namespace std;
// Function to simplify the string
char* simplify(string str)
{
    int len = str.length();
    // resultant string of max length equal to length of input string
    char* res = new char(len);
    int index = 0, i = 0;
 
    // create empty stack
    stack<int> s;
    s.push(0);
    while (i < len) {
          // Don't do any operation
        if(str[i] == '(' && i == 0) {
            i++;
              continue;
        }
        if (str[i] == '+') {
            // If top is 1, flip the operator
            if (s.top() == 1)
                res[index++] = '-';
 
            // If top is 0, append the same operator
            if (s.top() == 0)
                res[index++] = '+';
 
        } else if (str[i] == '-') {
            if (s.top() == 1) {
                  if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '+'; // Overriding previous sign 
                else res[index++] = '+';
            }
            else if (s.top() == 0) {
                  if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '-'; // Overriding previous sign
                else res[index++] = '-'; 
            }
        } else if (str[i] == '(' && i > 0) {
            if (str[i - 1] == '-') {
 
                // x is opposite to the top of stack
                int x = (s.top() == 1) ? 0 : 1;
                s.push(x);
            }
            // push value equal to top of the stack
            else if (str[i - 1] == '+')
                s.push(s.top());
        }
        // If closing parentheses pop the stack once
        else if (str[i] == ')')
            s.pop();
        // copy the character to the result
        else
            res[index++] = str[i];
        i++;
    }
    return res;
}
int main()
{
    string s1 = "(a-(b+c)+d)";
    string s2 = "a-(b-c-(d+e))-f";
    cout << simplify(s1) << endl;
    cout << simplify(s2) << endl;
    return 0;
}

