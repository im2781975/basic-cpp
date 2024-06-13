//how much coin need for complete n
#include<bits/stdc++.h>
using namespace std;
vector<int>coins{3, 4, 5};
int coin_change(int n)
{
    int mini = *min_element(coins.begin(), coins.end());
    if(n < mini)
         return 0;
    int ans = 10000;
    for(int i = 0; i < coins.size() -1 ; i++)
        ans = min(ans, 1 + coin_change(n - coins[i]));
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << coin_change(n);
}
