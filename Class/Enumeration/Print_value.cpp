#include <bits/stdc++.h>
using namespace std;
enum roll{
    A = 1, B = 2, C = 3,
};
enum rainbow {
    violet, indigo, blue,
    green, yellow, orange, red
}color;
enum class eyeclass : char{
    white, green, red
}eye;
string Tostring(eyeclass eye){
    switch(eye){
        case eyeclass::white:
            return "white";
        case eyeclass::green:
            return "green";
        case eyeclass::red:
            return "red";
        default:return "unknown";
    }
}
int main(){
    for(int i = violet; i <= red; i++)
        cout << i << " ";
    cout << "\n";
    eye = eyeclass::green;
    cout << Tostring(eye) << "\n";
    
    cout << "size of color is: " << sizeof(color) << "\n";
    cout << "sizeof eye is: " << sizeof(eye) << "\n";
    
    enum roll a = A;
    cout << "Roll number: " << a << "\n";
    enum NxtBin {
        A = 0, B = 10, c
    };
    NxtBin d; d = c; cout << d;
}


