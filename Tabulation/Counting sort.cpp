#include <bits/stdc++.h>
using namespace std;
vector<int> countSort(vector<int>& input)
{
    int N = input.size();
    int M = 0;
    for (int i = 0; i < N; i++)
        M = max(M, input[i]);
 
    vector<int> count(M + 1, 0);
    // Mapping each element of inputArray[] as an index of countArray[] array
    for (int i = 0; i < N; i++)
        count[input[i]]++;
    for (int i = 1; i <= M; i++)
        count[i] += count[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> out(N);
    for (int i = N - 1; i >= 0; i--)
    {
        out[count[input[i]] - 1]
            = input[i];
        count[input[i]]--;
    }
    return out;
}
void countingSort(vector<int>& arr, int n) {
    // Create a counting array to track the frequency of each number
    vector<int> count(n, 0);
    // Count the frequency of each number in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Output the sorted numbers based on the counting array
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
void print(vector <int> vec, int n)
{
    for(int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << "\n";
}
int main()
{
    vector<int> input = { 4, 3, 12, 1, 5, 5, 3, 9 };
    vector<int> output = countSort(input);
    output.resize(input.size());
    print(output, output.size());
    countingSort(input, input.size());
    print(input, input.size());
    return 0;
}
