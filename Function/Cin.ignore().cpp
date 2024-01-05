#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter range: ";
    cin >> n;
    cin.ignore(1,'\n');
    string s;
    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter " << i+1 << "th string: ";
        getline(cin, s);
        cout << "\nLength of " << i+1 << "th string: " << s.length() << " ";
        cout << "\n" << i+1 << "th string is: " <<s ;
    }
    return 0;
}

