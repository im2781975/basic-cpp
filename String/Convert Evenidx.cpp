#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
            s[i] = char('a' + (int(s[i] - 'a') + 1) % 26);
        
        /*if (isalpha(s[i])) {
            if (i % 2 == 0) {
                s[i] = 'a' + (s[i] - 'a' + 1) % 26;
            }
        }*/
    }
    cout << s << "\n";

    char arr[6] = { 'G', 'e', 'e', 'k', 's' };
    int i = 0;
    while (arr[i]) {
        printf("%c", arr[i++]);
    }
}
