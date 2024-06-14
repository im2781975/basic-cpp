#include <bits/stdc++.h>
using namespace std;
 
vector<int> countSort(vector<int>& input)
{
    int N = input.size();
    // Finding the maximum element of array inputArray[].
    int M = 0;
    for (int i = 0; i < N; i++)
        M = max(M, input[i]);
 
    // Initializing countArray[] with 0
    vector<int> count(M + 1, 0);
    // Mapping each element of inputArray[] as an index of countArray[] array
    for (int i = 0; i < N; i++)
        count[input[i]]++;
    // Calculating prefix sum at every index of array countArray[]
    for (int i = 1; i <= M; i++)
        count[i] += count[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> output(N);
    for (int i = N - 1; i >= 0; i--)
 
    {
        output[count[input[i]] - 1]
            = input[i];
 
        count[input[i]]--;
    }
    return output;
}
int main()
{
    vector<int> input = { 4, 3, 12, 1, 5, 5, 3, 9 };
    vector<int> output = countSort(input);
 
    for (int i = 0; i < input.size(); i++)
        cout << output[i] << " ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector <int > cntsort(vector<int>arr)
{
    int n = arr.size();
    int m = 0;
    for(int i = 0; i < n; i++)
        m = max(m, arr[i]);
    vector <int >cnt(m + 1, 0);
    for(int i = 0; i < n; i++)
        cnt[arr[i]]++;
    for(int i = 1; i <= m; i++)
        cnt[i] += cnt[i - 1];
    vector <int> output(n);
    for(int i = n - 1; i >= 0; i--)
    {
        output[cnt[arr[i] -1]] = arr[i];
        cnt[arr[i]]--;
    }
}
int main()
{
    vector<int>vec{2, 3, 1, 5, 4};
    vector <int> output = cntsort(vec);
}
