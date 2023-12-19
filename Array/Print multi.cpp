#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count = 0;
    int x[2][2][3];
    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                x[i][j][k] = i+j+k;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                    cout<<"["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"]"<<"="<<x[i][j][k]<<"\n";
            }
        }
    }
    return 0;
}
