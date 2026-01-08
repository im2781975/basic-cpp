#include<bits/stdc++.h>
using namespace std;
enum class colore {red, green, blue};
enum class color2 {black, white, gray};
enum class people {good, bad};
enum roll { A = 1, B = 2, C = 3 };
enum rainbow { violet, indigo, blue, green, yellow, orange, red }color;
enum class eyeclass : char {white, green, red}eye;
string Tostr(eyeclass eye) {
    switch(eye){
        case eyeclass::white:    return "white";
        case eyeclass::green:    return "green";
        case eyeclass::red:    return "red";
        default: return "unknown";
    }
}
enum nextbin { X = 0, Y = 10, z};
int main(){
    colore x = colore::green;
    if(x == colore::red) cout << "red\n";
    else cout << "not red\n";
    cout << int(x) << "\n";
    
    enum gender {male, female};
    enum paint {red, green, gray, white};
    gender gen = male; paint col = gray;
    if(gen == gender :: male && col == paint :: white) cout << "Equal\n";
    else    cout << "Not Equal";
    
    switch(gen){
        case male:
            cout << "Male"; break;
        case female:
            cout << "female"; break;
        default:
            cout << "Other";
    }
    for(int i = violet; i <= red; i++) cout << i << " ";
    cout << endl;
    eye = eyeclass::green;
    cout << Tostr(eye) << endl;
    cout << sizeof(color) << " " << sizeof(eye) << endl;
    enum roll a = A; cout << a << endl;
    
    nextbin w; w = z; cout << w;
}
