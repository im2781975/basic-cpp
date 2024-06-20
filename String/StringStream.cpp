//find freq of every word using unordered_map 
#include <bits/stdc++.h> 
using namespace std; 

void printFrequencies(const string &str) 
{ 
    unordered_map<string, int> Freq; 
    
    // string stream Used for breaking words 
    stringstream ss(str); 
    
    // To store individual words 
    string word;  
    while (ss >> word) 
        Freq[word]++; 
  
    unordered_map<string, int>:: iterator p; 
    for (p = Freq.begin();  
       p != Freq.end(); p++) 
    cout << p->first << " "<<p->second << "\n" ;
} 
void Type(){
    string S, T;
    cout << "Enter String: ";
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, ' '))
        cout << T <<" ";

    int val;
    cout << "\nEnter integers: ";
    cin >> val;
    stringstream geek;
    // inserting integer val in geek stream
    geek << val;
    //The object has the value 123 and stream it to the string x
    string x;
    geek >> x;
    //Now the string x holds the value 12
    cout << x + "4" <<"\n";
}
void Type_(){
    stringstream str("Programmer");
    string line;
    // Ignore all the whitespace in string str before the first word.
    getline(str >> ws, line);
 
    // After printing the output it will automatically write a new line in the output stream.
    cout << line << "\n";
 
    // without flush, the output will be the same.
    cout << "only a test" <<flush;
    // Use of ends Manipulator
    cout << "\na";
 
    // NULL character will be added in the Output
    cout << "b" << ends;
    cout << "c" << endl;
}
int main() 
{ 
    string str = "geeks for geeks" ; 
    printFrequencies(str); 
    Type();
    Type_();
    return 0; 
}
