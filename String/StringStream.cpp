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
int main() 
{ 
    string str = "geeks for geeks" ; 
    printFrequencies(str); 
    return 0; 
}
