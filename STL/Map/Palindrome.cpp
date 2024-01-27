//You are given a string s of small letters. You can reorder or rearrange the characters of that string in any order or any way. 
//You have to determine whether you can build any valid palindrome from that string.Print “YES” if you can otherwise print “NO”.
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool canBuildPalindrome(const string& s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    int oddCount = 0;
    for (const auto& pair : charCount) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }
    // For a string to be a palindrome, it can have at most one character with an odd count.
    return oddCount <= 1;
}
int main() {
    string s;
    cout << "Enter a string of small letters: ";
    cin >> s;
    if (canBuildPalindrome(s))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}
