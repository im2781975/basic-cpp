#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n % 2 == 0) 
        goto label1;
    else
        goto label2;
 
    label1:
        cout << "Even" << "\n";
        return 0;
    label2:
        cout << "Odd" << "\n";
}


