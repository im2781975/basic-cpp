#include<bits/stdc++.h>
using namespace std;

void print(map<int, int> mp)
{
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout <<"\nKey: "<< it->first << "  Value: " << it->second ;
    }
}

int main()
{
    map<int, int> mp;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        
        //insert key elements.
        cin >> x;
        //update value elements which is depend over key.
        mp[x]++;
    }
    print(mp);
    return 0;

    string s;
    cin >> s;

    map<char, vector<int>> mp;

    // Each character in the input string is associated with a vector of integers.
    // The map is used to store the indices (positions) of each character in the input string.
    for(int i = 0; i < s.size(); i++) {
        // Iterates over each character in the string using a for loop.
        // Inside the loop, it appends the index (i) of the current character to the vector associated with that character in the map.
        mp[s[i]].push_back(i);
        // s[0] is 'p', so mp['p'] will be created if it doesn't exist, and 0 will be pushed into the vector associated with 'p'.
        // s[1] is 'r', so mp['r'] will be created if it doesn't exist, and 1 will be pushed into the vector associated with 'r'.
        // s[2] is 'o', so mp['o'] will be created if it doesn't exist, and 2 will be pushed into the vector associated with 'o'.
    }

    for(auto it: mp) {
        char ch = it.first;
        vector<int> v = it.second;

        // it.second is the vector containing the indices where that character appears in the string.
        cout << ch << " ";
        
        for(int val: v)
            cout << val << " ";
        
        cout << "\n";
    }
}
