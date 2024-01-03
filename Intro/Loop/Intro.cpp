#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m = 1;
    cout<< "Enter integer: ";
    cin >>n;
    cout << "First loop is: ";
    while (m <= n)
    {
        cout <<m << " ";
            m = m*2;
    }
    
    cout << "\nSecond loop is: ";
    for(int i =0; i <n ; i++)
    {
        for(int j =i; j >0; j--)
        {
            cout<< i <<" " <<j <<" | ";
        }
        cout<< "\n";
    }
    cout<< "\nThird loop is: ";
    for(int i =0; i <n; i++)
    {
        for(int j =i; j >0; j--)
        {
            for(int k =j; k >0; k--)
                cout<< i<< " " << j << " " << k << " | ";
        }
        cout<< "\n";
    }
    cout<< "\nFourth loop  is: ";
    for(int i = n/2; i <n ; i++)
    {
        for(int j = 1; j<=n; j*=2)
        {
            cout<< i <<" " <<j <<" | ";
        }
        cout<< "\n";
    }
    cout<< "\nFifth loop  is: ";
    for(int i = n/2; i <n ; i++)
    {
        for(int j = 1; j<=n; j += i)
        {
            cout<< i <<" " <<j <<" | ";
        }
        cout<< "\n";
    }
}
