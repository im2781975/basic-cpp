#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;

    vector<int> v(n * n);

    for (int i = 0; i < n * n; i++)
        v[i] = i;

    cout << "Elements of vector are: ";
    for (int i = 0; i < n * n; i++)
        cout << v[i] << " ";

    int sum = 0;
    cout << "\nSum of the vector elements is: ";
    for (int i = 0; i < n * n; i++)
        sum += v[i];

    cout << sum;

    vector<int> cev[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cev[i].push_back(j);
    }

    cout << "\nElements of the 2D vector are: ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cev[i][j] << " ";
        cout << "\n";
    }
    
    vector <int> vect[1];
    vect[0].push_back(9);
    vect[0].push_back(2);
    
    vector <int> t= vect[0];
    cout<< t[0];
    return 0;
}

