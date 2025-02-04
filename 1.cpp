#include<bits/stdc++.h>
using namespace std;

int Min(int x, int y, int z)
{
        return min(min(x,y),z);
}
int editDis(string s1, string s2, int m, int n)
{
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
                for(int j=0; i<=n; j++){
                        if(i==0)
                                dp[i][j]=j;
                        else if(j==0)
                                dp[i][j]=i;
                        else
                                dp[i][j]=1 + Min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
        }
        return dp[m][n];
}
int main()
{
        string s1, s2;
        cin >> s1 >> s2;
        cout<< editDis(s1,s2,s1.length(),s2.length())<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main() {
    ios::sync_with_stdio(false); // Faster I/O
    cin.tie(nullptr);

    int n, q, sum = 0;
    cin >> n >> q;

    // Reading the array and counting non-zero elements
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != 0) sum++;
    }

    while (q--) {
        int t, v;
        cin >> t >> v;

        if (t == 2) { // Increment operation
            if (arr[v] == 0) sum++;  // Only increase sum if arr[v] was 0
            arr[v]++;
        } 
        else if (t == 1) { // Decrement operation
            if (arr[v] > 0) { 
                arr[v]--;
                if (arr[v] == 0) sum--;  // Decrease sum only when arr[v] becomes 0
            }
        }

        cout << sum << "\n";  // Faster output using cout
    }

    return 0;
}
