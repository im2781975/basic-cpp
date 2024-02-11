#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string& word, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (word[start] != word[end]) {
        return false;
    }
    return isPalindrome(word, start + 1, end - 1);
}
int main() {
    string str;
    cin >> str;
    
    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "\nYes" ;
    } else {
        cout << "\nNo" ;
    }
    return 0;
}
