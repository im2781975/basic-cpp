#include <iostream>
#include <string>
using namespace std;
int main() {
    string str = "geeksforgeeks";
    char arr[] = "geeks";
    size_t found = str.find(arr);
    
    if (found != string::npos)
        cout << "First occurrence is " << found <<"\n";
    if (found != string::npos) {
        found = str.find(arr, found + 1); 
        // Find the next occurrence
        if (found != string::npos) 
            cout << "Next occurrence is " << found << "\n";
        else
            cout << "No more occurrences found.\n";
    } else 
        cout << "String not found.\n";
        
    size_t f = str.find("geeks.practice",0, 5);
    if (f != string::npos)
        cout << f << endl;
    return 0;
}
