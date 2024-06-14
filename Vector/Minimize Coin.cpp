//CSES
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector <int> coin(n);
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    vector<int>CountCoin(x+1, INT_MAX);
    CountCoin[0] = 0;
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<coin.size(); j++)
        {
            if(i - coin[j] >=0)
                CountCoin[i] = min(CountCoin[i],CountCoin[i - coin[j]] + 1);
        }
    }
    cout << CountCoin[x];
}
