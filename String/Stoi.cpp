//stoi() is a standard library function that turns a string into an integer
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "2009 GeeksforGeeks_founded";
    string str1 = "0x6C1";
    string str2 = "-10010010101";

    int num = stoi(str);
    int num_hex = stoi(str1, nullptr, 16);
    int num_bin = stoi(str2, nullptr, 2);
 
    cout << str << ": " << num << "\n";
    cout << str1 << ":" << num_hex<< "\n";
    cout << str2 << ": " << num_bin << "\n";
    return 0;
}
