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
    
    //if string didn't contain any number char
    string str = "ibrahim";
    try {
        int num = stoi(str);
        cout << num;
    } catch (invalid_argument const &e) {
        cout << "Invalid argument: " << e.what() << endl;
    } catch (out_of_range const &e) {
        cout << "Out of range: " << e.what() << endl;
    }
}
